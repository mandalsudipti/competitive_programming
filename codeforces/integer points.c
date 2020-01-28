#include<stdio.h>
 
int main()
{
    int T,N,M,i;
    long long int val, pair,odd_a,even_a,odd_b,even_b,zero=0,one=1,two=2;
    scanf("%I64d",&T);
    while(T--)
    {
        odd_a=zero;
        even_a=zero;
        odd_b=zero;
        even_b=zero;
        scanf("%Id",&N);
        for(i=0;i<N;i++)
        {
            scanf("%I64d",&val);
            if((val==zero|| val%two==zero)&& val!=one)
                even_a++;
            else 
                odd_a++;
        }
        scanf("%d",&M);
        for(i=0;i<M;i++)
        {
            scanf("%I64d",&val);
            if((val==zero|| val%two==zero)&& val!=one)
                even_b++;
            else
                odd_b++;
        }
        pair=(odd_b*odd_a)+(even_b*even_a);
        printf("%I64d\n",pair);
    }
}
 