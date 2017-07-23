# using the request object from flask. Redirect and url_for
# will be used to redirect the user once the upload is done
# and send_from_directory will help us to send/show on the
# browser the file that the user just uploaded
from flask import Flask, render_template, request, redirect, url_for, send_from_directory
from werkzeug import secure_filename
import csv
import os
import time
import re
import glob
from clang.cindex import Index
from pprint import pprint

def find_min_max_avg(graph_csv):
    max = 0
    min = 1
    sum = 0
    count = 0
    for edge in graph_csv:
        if edge[2] > max:
            max = edge[2]
        if edge[2] < min:
            min = edge[2]
        sum = sum + edge[2]
        count = count + 1
    return [min,max,(sum/count)]

def write_csv_graph(Graph_csv):
    with open('./uploads/graph_out.csv', 'w') as csvfile:
        fieldnames = ['source', 'target','weight']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for edge in Graph_csv:
            row = {}
            row[fieldnames[0]] = edge[0]
            row[fieldnames[1]] = edge[1]
            row[fieldnames[2]] = edge[2]
            writer.writerow(row)

def read_csv_graph(csv_file):
    # Open csv file where each line represents an edge "node1;node2;weight\n"
    data = []
    with open(csv_file,'r') as f:
        cont=f.read()
        #skip fist line that containg strings
        iter_cont = iter(cont.split('\n'))
        next(iter_cont)
        for line in iter_cont :
            if line != '':
                # Read line "edge" and add it to graph
                edge=line.split(',')
                row = []
                row.append(edge[0])
                row.append(edge[1])
                row.append(float(edge[2]))
                data.append(row)
    return data

def clean_upload_buffer(upload_path):
    files = glob.glob(upload_path+'*')
    for f in files:
        os.remove(f)
    pass

# Loader
def load_code_from_file(file_path):
    try:
        return open(file_path, 'r').read()
    except IOError as e:
        print('[-] Error : '+str(e))
        return

# Filter
# strip include from code file using RE
def remove_includes(code):
    #match include , replace with space
    return re.sub('#include[ ]*(<.*>|".*")', '', code, re.S)

def filter_code(code):
    filtered_code = remove_includes(code)
    return filtered_code

#Dynamic programming (longest common sequence)
def dlcs(a, b):
    lengths = [[0 for j in range(len(b)+1)] for i in range(len(a)+1)]
    # row 0 and column 0 are initialized to 0 already
    for i, x in enumerate(a):
        for j, y in enumerate(b):
            if x == y:
                lengths[i+1][j+1] = lengths[i][j] + 1
            else:
                lengths[i+1][j+1] = max(lengths[i+1][j], lengths[i][j+1])
    result = []
    x, y = len(a), len(b)
    while x != 0 and y != 0:
        if lengths[x][y] == lengths[x-1][y]:
            x -= 1
        elif lengths[x][y] == lengths[x][y-1]:
            y -= 1
        else:
            assert a[x-1] == b[y-1]
            result.insert(0, a[x-1])
            x -= 1
            y -= 1
    return result

def calculate_sim(text_a, text_b):
    return (2.0*len(dlcs(text_a, text_b)))/(len(text_a)+len(text_b))

def save_opreation(key, xkey, xhash):
    strpair = key+'-'+xkey
    xstrpair = xkey+'-'+key
    xhash[strpair] = True
    xhash[xstrpair] = True
    pass

def similarity(ready_dict):
	# save opreation in hisroty like  p(a, b) = p(b, a) for non reapating opreation
    history = {}
    # 2d array represents edges in a graph
    graph_data = []
    for key, value in ready_dict.items():
        for xkey, xvalue in ready_dict.items():
        	# checking history and key => p(a, b) = p(b, a) and  p(a, a) = 1
            if not((key+'-'+xkey) in history) and (key != xkey):
            	# Saving opreation in history
                save_opreation(key, xkey, history)
                sim = calculate_sim(value, xvalue)
                # creating a similarity row (edge)
                row = []
               	row.append(key)
                row.append(xkey)
                row.append(sim)
                #print("{},{},{}".format(key, xkey, sim))
                # add row (edge) to graph
                graph_data.append(row)
    return graph_data
"""
A simple command line tool for dumping a source file using the Clang Index
Library.
"""
def get_info(node):
    kinds = [node.kind.value]
    for c in node.get_children():
        kinds += get_info(c)
    return kinds
# Initialize the Flask application
app = Flask(__name__,static_url_path="", static_folder="static")
# This is the path to the upload directory
app.config['UPLOAD_FOLDER'] = 'uploads/'
# These are the extension that we are accepting to be uploaded
app.config['ALLOWED_EXTENSIONS'] = set(['cpp', 'c'])
# For a given file, return whether it's an allowed type or not
def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1] in app.config['ALLOWED_EXTENSIONS']

@app.route('/')
def index():
    return render_template('index.html')

# Route that will process the file upload
@app.route('/upload', methods=['POST'])
def upload():
    dir_path = './uploads/'
    clean_upload_buffer(dir_path)
    # Get the name of the uploaded files
    uploaded_files = request.files.getlist("file[]")
    filenames = []
    for file in uploaded_files:
        # Check if the file is one of the allowed types/extensions
        if file and allowed_file(file.filename):
            # Make the filename safe, remove unsupported chars
            filename = secure_filename(file.filename)
            # Move the file form the temporal folder to the upload
            # folder we setup
            file.save(os.path.join(app.config['UPLOAD_FOLDER'], filename))
            # Save the filename into a list, we'll use it later
            filenames.append(filename)
            # Redirect the user to the uploaded_file route, which
            # will basicaly show on the browser the uploaded file
            #code simeliarty analysis
    index = Index.create()
    abs_struct_dict = {}
    code_files = os.listdir(dir_path)
    for code_file in code_files:
        code_file_path = os.path.join(dir_path, code_file)
        try:
            code_str = load_code_from_file(code_file_path)
            tu = index.parse(code_file_path, unsaved_files=[[code_file_path, code_str]])
            if len(code_str)<2 or len(tu.diagnostics)>1:
                raise Exception('invaled code')
            else:
                filtered_code_str = filter_code(code_str)
                tu = index.parse(code_file_path, unsaved_files=[[code_file_path, filtered_code_str]])
                abs_struct_dict[code_file] = get_info(tu.cursor)
        except Exception as e:
                print('[-]'+str(e))
                print("unable to load input from \'{}\', skiped!".format(code_file_path))
    for k in abs_struct_dict.keys():
        print '[+]'+k
        print abs_struct_dict[k]
    graph_data = similarity(abs_struct_dict)
    write_csv_graph(graph_data)
    # Load an html page with a link to each uploaded file
    results =  find_min_max_avg(graph_data)
    return render_template('test.html',hybrid_data=graph_data,min=results[0] ,max=results[1] ,avg=results[2] )

@app.route('/uploads/<filename>')
def uploaded_file(filename):
    return send_from_directory(app.config['UPLOAD_FOLDER'],filename)

@app.route('/statics/js/<path:path>')
def send_js(path):
    return send_from_directory('js', path)

@app.route('/viewdata')
def viewdata():
    graph_data = read_csv_graph('./uploads/graph_out.csv')
    results =  find_min_max_avg(graph_data)
    return render_template('test.html',hybrid_data=graph_data,min=results[0] ,max=results[1] ,avg=results[2])

@app.route('/wgcluster')
def wgcluster():
    graph_data = read_csv_graph('./uploads/graph_out.csv')
    results =  find_min_max_avg(graph_data)
    return render_template('wgcluster.html',min=results[0] ,max=results[1] ,avg=results[2] )

if __name__ == '__main__':
    app.run(debug=True)
