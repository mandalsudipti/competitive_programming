#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,x,fre[200005]={0},val,i,pair=0;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
        cin>>val;
        fre[val]++;
    }
    if(x==0)
    {
        for(i=0;i<200005;i++)
        {
            if(fre[i]>=2)
                pair+=(fre[i]*(fre[i]-1))/2;
        }
        cout<<pair;
    }
    else
    {
        for(i=1;i<200005;i++)
        {
            if((i^x)<200005 && fre[i^x]!=0)
            {
                pair+=(fre[i]*fre[i^x]);
            }
        }
        cout<<pair/2;
    }
    return 0;
}
