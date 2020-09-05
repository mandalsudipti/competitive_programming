#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n ;
    cin>>n;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    
    long long int range = pow(arr[n-1],1.0/(n-1));
    long long int min_cost = 0 ;
    
    for(int i=0;i<n;i++)
        min_cost+=(arr[i]-1);
        
    for(long long int c = 2 ; c<=(range+1) ; c++)
    {
        long long int cost = 0 , x = 1 ;
        for(int i=0;i<n;i++)
        {
            cost+=abs(arr[i]-x);
            if(x>1e11)
            {
                cost = min_cost + 10 ;
                break;
            }
            x = x*c;
        }
        
        min_cost = min(min_cost,cost);
    }
    
    cout<<min_cost<<endl;
    return 0;
}
