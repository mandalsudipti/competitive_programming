#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        vector<long long int>arr(n);
        vector<long long int>freq(n,1);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        int idx = 0 ;
        while(idx < arr.size())
        {
            if(arr[idx]%x)
                break;
            else
            {
                arr.push_back(arr[idx]/x);
                freq.push_back(freq[idx] * x);
            }
            idx++;
        }
        
        long long int sum = 0 ;
        for(int i = 0 ; i < arr.size() ; i++)
            sum+=(arr[i] * freq[i]);
        cout<<sum<<endl;
    }
    
    return 0;
}
