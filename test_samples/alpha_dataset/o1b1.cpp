#include <stdio.h>
int CON = 7;
int main() {
    int number;

    scanf("%d",&number);
    for(;;number--){
    int min_number, fg = 1;
    scanf("%d",&min_number);
    char my_arr[min_number][CON];

    for(int i = 0;i < min_number;i++) {
        scanf("%s", my_arr[i]);
    }
        for(int i =0;i < min_number; i++) {
            if (my_arr[i][0] == 'c') {
                if (i == min_number - 1 || my_arr[i + 1][0] == 'c') {
                    fg = 0;
                    break;
                }
            }
        }
        if(fg ==1) {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }


    return 0;
}
