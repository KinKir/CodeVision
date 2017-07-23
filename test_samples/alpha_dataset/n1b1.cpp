#include<stdio.h>
int main()
    {
      int array_size;
      scanf("%d", &array_size);

      for(int i=0; i<array_size; i++)
         {
          int C, D, L;
          int result=0;
           scanf("%d%d%d", &C, &D, &L);
           int tmp_arr[C+2*D];
           if(2*D>=C)
             {
               for(int j=0; j<C+1; j++)
                  {
                  tmp_arr[j]=4*D+(C-j)*4;
                  if(L==tmp_arr[j])
                    result=1;
                   }
              }
            else
                {
                  for(int k=0; k<(2*D+1); k++)
                     {
                      tmp_arr[k]=(4*D)+(C-k)*4;
                       if(L==tmp_arr[k])
                           result=1;
                     }
                 }
        if(result) printf("yes\n");
        else printf("no\n");
        }

    return 0;
  }
