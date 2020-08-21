#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , z , cnt = 0;
    cin>>n>>z;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    
    int mid = n/2 ;
    int tmp = mid ;
    for(int i=0;i<tmp;i++)
    {
        if(mid>=arr.size())
            break;
        while(mid<arr.size()&& abs(arr[i]-arr[mid])<z)
            mid++;
        if(mid>=arr.size())
            break;
        else
        {
            cnt++;
            mid++;
        }
    }
    
    cout<<cnt;
    return 0;
    
}



