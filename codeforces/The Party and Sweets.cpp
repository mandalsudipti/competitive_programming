#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m;
    cin>>n>>m;
    long long int boy[n],girl[m];
    
    for(int i=0;i<n;i++)
        cin>>boy[i];
    for(int i=0;i<m;i++)
        cin>>girl[i];
        
    sort(boy,boy+n);
    sort(girl,girl+m);
    if(girl[0]<boy[n-1])
    {
        cout<<"-1";
        return 0;
    }
    long long int cost = 0;
    for(int i=0;i<n;i++)
        cost= cost + (boy[i]*m);
    for(int i=1;i<m;i++)
        cost+=(girl[i]-boy[n-1]);
    if(girl[0]!=boy[n-1])
        cost+=(girl[0]-boy[n-2]);
    cout<<cost<<endl;
    return 0;
}