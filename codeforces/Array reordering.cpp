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
        vector<int>even , odd ;
        
        for(int i = 0 ; i < n ; i++)
        {
            int val ;
            cin>>val;
            val%2 == 0 ? even.push_back(val) : odd.push_back(val) ;
        }
        long long int count = 0 ;
        for(int i = 0 ; i < even.size() ; i++)
            count+=(n - i - 1);
            
        for(int i = 0 ; i < odd.size() ; i++)
        {
            for(int j = i+1 ; j < odd.size() ; j++)
            {
                if(__gcd(odd[i] , odd[j]) > 1)
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0 ;
}