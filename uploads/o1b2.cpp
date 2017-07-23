#include <stdio.h>
int main() {
    int No, minimuom, flg;

    scanf("%d",&No);

    while(No >= 0){
    flg = 1;
    scanf("%d",&minimuom);
    char input[minimuom][7];
    for(int i = 0;i < minimuom;i++) {
        scanf("%s", input[i]);
    }
        for(int j =0;j < minimuom; j++) {
            if (input[j][0] == 'c') {
                if (j == minimuom - 1 || input[j + 1][0] == 'c') {
                    flg = 0;
                    break;
                }
            }
        }
        if(flg ==1) {
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    No--;
    }


    return 0;
}
