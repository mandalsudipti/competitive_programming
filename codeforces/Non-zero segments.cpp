#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    set<long long int>prefix_sum;
    prefix_sum.insert(arr[0]);
    long long int cur = arr[0] ;
    int cnt = 0 ;
    
    for(int i=1;i<n;i++)
    {
        cur+=arr[i];
        if(cur==0 || prefix_sum.find(cur)!=prefix_sum.end())
        {
            cnt++;
            cur = arr[i] ;
            prefix_sum.clear();
            prefix_sum.insert(cur);
        }
        else
            prefix_sum.insert(cur);
    }
    
    cout<<cnt<<endl;
    
    return 0;
}