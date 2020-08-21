#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<long long int>arr(n);
        vector<long long int>cpy_arr(n);
        long long int minimum = 1e9 ;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            cpy_arr[i] = arr[i];
            minimum = min(minimum , arr[i]);
        }
        sort(cpy_arr.begin(),cpy_arr.end());
        bool possible = true ;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==cpy_arr[i] || (arr[i]%minimum == 0))
                continue;
            else
            {
                possible = false;
                break;
            }
        }
        
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}