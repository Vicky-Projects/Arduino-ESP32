#include<stdio.h>
#include<conio.h>
void main()
{
    int a[3],b[3],i,j,k,l;
    for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }
    for(k=0;k<4;k++)
    
        for(j=0;j<4;j++)
        {
            b[k]=a[k]<a[j];
            l=b[k];
            printf("%d",b[k]);

            }


        }
    }
}