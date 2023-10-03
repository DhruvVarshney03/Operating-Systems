#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[100],i,n,Total=0,initial;
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    printf("Enter the Requests sequence: ");
    for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
    printf("Enter initial head position: ");
    scanf("%d",&initial);
    
    
    
    for(i=0;i<n;i++)
    {
        Total=Total+abs(arr[i]-initial);
        initial=arr[i];
    }
    
    printf("%d",Total);
    return 0;
    
}
