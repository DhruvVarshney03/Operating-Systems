#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,Total=0,initial,count=0;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    printf("Enter the Requests sequence: ");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d",&initial);
    

    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-initial);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        Total=Total+min;
        initial=RQ[index];

        RQ[index]=1000;
        count++;
    }
    
    printf("%d",Total);
    return 0;
}
