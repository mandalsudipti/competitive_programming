#include<stdio.h>
 
int main()
{
    int len ,val,even=0,odd=0,i;
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        scanf("%d",&val);
        if(val%2==0)
            even++;
        else 
            odd++;
    }
    if(even>odd)
        printf("%d",odd);
    else
        printf("%d",even);
    return 0;
}