#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int A[n],B[n],i,one=0 , zero=0;
    for(i=0;i<n;i++)
        cin>>A[i];
    for(i=0;i<n;i++)
        cin>>B[i];
    for(i=0;i<n;i++)
    {
        if(A[i]==1 && B[i]==0)
            one++;
        else if(A[i]==0 && B[i]==1)
            zero++;
    }
    if(one>zero)
        cout<<"1";
    else if(one==0)
        cout<<"-1";
    else
    {
        //int x=(zero/one)+(zero%one!=0);
        int x = (zero/one)+1;
        cout<<x;
        
    }
    return 0;
}