#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<long long int>arr(2*n);
    
    for(int i=0;i<2*n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    
    long long int area = (arr[n-1]-arr[0])*(arr[2*n-1]-arr[n]) , tmp = arr[2*n-1] - arr[0];
    
    for(int i=1;i<n;i++)
        area = min(area, tmp*(arr[i+n-1]-arr[i]));
        
    cout<<area<<endl;
    
    return 0;
}
