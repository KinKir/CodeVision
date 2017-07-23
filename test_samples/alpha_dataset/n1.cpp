#include<stdio.h>
int main()
    {
      int T,C,D,L,i,j,k,result;
       scanf("%d",&T);
 int test[T];
      for(i=0;i<T;i++)
         {
          result=0;
           scanf("%d%d%d",&C,&D,&L);
           int temp[C+2*D];
           if(2*D>=C)
             {
               for(j=0;j<C+1;j++)
                  {
                  temp[j]=4*D+(C-j)*4;
                  if(L==temp[j])
                    result=1;
                   }
              }
            else
                {
                  for(k=0;k<(2*D+1);k++)
                     {
                      temp[k]=(4*D)+(C-k)*4;
                     // printf("check%d\n",temp[k]);
                       if(L==temp[k])
                           result=1;
                     }
                 }
        if(result==1) test[i]=1;
        else test[i]=0;
        }
         for(i=0;i<T;i++)
         {
           if(test[i]==1)
           printf("yes\n");
           else printf("no\n");
         }

    return(0);
  }
