#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<long long int>arr(n+1);
        for(int i = 1 ; i<=n ;i++)
        {
            cin>>arr[i];
        }
        vector<long long int>val(n+1);
        for(int i = n ; i > 0 ; i--)
        {
            int next = i + arr[i] ;
            val[i] = arr[i] ;
            if(next <= n)
                val[i]+=val[next];
        }
        
        long long int maximum = val[1] ;
        for(int i = 2 ; i <= n ; i++)
            maximum = max( maximum , val[i]);
            
        cout<<maximum<<endl;
    }
    
    return 0;
}