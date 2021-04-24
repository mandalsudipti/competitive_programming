#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int val; 
        vector<int>even , odd ;
        for(int i = 0 ; i < n  ;i++)
        {
            cin>>val;
            val%2 == 0 ? even.push_back(val) : odd.push_back(val);
        }
        
        if(even.size() > odd.size())
        {
            for(int i = 0 ; i < even.size() ; i++)
                cout<<even[i]<<" ";
            for(int i = 0 ; i < odd.size() ; i++)
                cout<<odd[i]<<" ";
            cout<<endl;
        }
        else
        {
            for(int i = 0 ; i < odd.size() ; i++)
                cout<<odd[i]<<" ";
            for(int i = 0 ; i < even.size() ; i++)
                cout<<even[i]<<" ";
            cout<<endl;
        }
    }
    
    return 0 ;
}
