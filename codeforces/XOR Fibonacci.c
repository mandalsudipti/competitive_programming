#include<stdio.h>
 
int main()
{
    int T;
    long int a,b,c,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%ld",&a);
        scanf("%ld",&b);
        scanf("%ld",&n);
        c=a^b;
        if(n%3==0) printf("%ld\n",a);
        else if(n%3==1) printf("%ld\n",b);
        else  printf("%ld\n",c);
    }
    return 0;
}