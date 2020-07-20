#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<pair<int,int>>arr(n);
    vector<int>left(n);
    vector<int>right(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>left[i]>>right[i];
        arr[i] = make_pair(left[i],right[i]);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    int length = right[0] - left[n-1] ;
    
    for(int i=0;i<n;i++)
    {
        int l = left[n-1] , r = right[0] ;
        if(arr[i].first==l)
            l = left[n-2];
        if(arr[i].second == r) 
            r = right[1];
        length = max(length , r - l);
    }
    cout<<max(0,length)<<endl;
    
    return 0;
}