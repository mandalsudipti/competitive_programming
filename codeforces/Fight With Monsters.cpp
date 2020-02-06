#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    int arr[n],i,cnt=0;
    for(i=0;i<n;i++)
        cin>>arr[i];
    vector<int>rem ;
    for(i=0;i<n;i++)
    {
        if(arr[i]%(a+b)==0)
            rem.push_back(b);
        else if(arr[i]%(a+b)<=a)
            cnt++;
        else
            rem.push_back(arr[i]%(a+b)-a);
    }
    sort(rem.begin(),rem.end());
    for(i=0;i<rem.size();i++)
    {
       
       k-=(rem[i]/a+(rem[i]%a!=0));
        if(k>=0)
            cnt++;
        else
            break;
    }
    cout<<cnt;
    return 0;
}
