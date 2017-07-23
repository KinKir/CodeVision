#include <stdio.h>
#include <string.h>

int main() {
    int flag;
    char arr1[7],arr2[7];
    int t,i,n;
    scanf("%d",&t);
    while(t--){
        flag=0;
        scanf("%d",&n);
        scanf("%s",arr1);
		for(i=1;i<n;i++)
        {
            scanf("%s",arr2);
	    	if((arr1[0]=='c')&&(arr2[0]=='c'))
				flag=1;
	 		if((i==(n-1))&&(arr2[0]=='c'))
				flag=1;
	    	strcpy(arr1,arr2);
		}

		if((n==1)&&(arr1[0]=='c'))
            flag=1;
        if(flag==1)
            printf("\nNO");
        else
            printf("\nYES");
    }
	return 0;
}
