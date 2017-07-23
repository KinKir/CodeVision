#include <stdio.h>
int main() {
    int numT;
    int minN;
    int i,j,flag;

    scanf("%d",&numT);

    while(numT--){

    scanf("%d",&minN);
    char input[minN][7];
    for(j = 0;j < minN;j++) {
        scanf("%s", input[j]);
        flag = 1;
    }
        for(i =0;i < minN; i++) {
            if (input[i][0] == 'c') {
                if (i == minN - 1 || input[i + 1][0] == 'c') {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag ==1) {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }


    return 0;
} 
