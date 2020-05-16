#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m , partition ;
    cin>>n>>m>>partition;
    
    long long int arr[n] ;
    vector<long long int>sorted_arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sorted_arr[i]=arr[i];
    }
    sort(sorted_arr.begin(),sorted_arr.end(),greater<long long int>());
    long long int sum = 0 ;
    map<long long int , int> maximum;
    for(int i=0;i<(m*partition);i++)
    {
        sum+=sorted_arr[i];
        maximum[sorted_arr[i]]++;
    }
    cout<<sum<<endl;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(partition==1)
            break;
        else
        {
            if(maximum[arr[i]]>=1)
            {
                maximum[arr[i]]--;
                cnt++;
            }
            if(cnt==m)
            {
                cout<<(i+1)<<" ";
                cnt=0;
                partition--;
            }
        }
    }
    return 0;
}
