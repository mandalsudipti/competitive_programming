#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , val;
        cin>>n;
        vector<long long int>even ;
        vector<long long int>odd ;
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val;
            if(val % 2 == 0)
                even.push_back(val);
            else
                odd.push_back(val);
        }
        
        sort(even.begin() , even.end() , greater<long long int>());
        sort(odd.begin() , odd.end() , greater<long long int>());
        
        long long int Alice = 0 , Bob = 0 ;
        bool flag = true ;
        int idx1 = 0 , idx2 = 0 ;
        
        while(idx1 < even.size() || idx2 < odd.size())
        {
            if(flag)
            {
                flag = false ;
                if(idx1 >= even.size() || (idx2 < odd.size() && even[idx1] <= odd[idx2]) )
                    idx2++;
                else
                {
                    Alice+=even[idx1];
                    idx1++;
                }
            }
            else
            {
                flag = true ;
                if(idx2 >= odd.size() || ( idx1 < even.size() && odd[idx2] <= even[idx1]) )
                    idx1++;
                else
                {
                    Bob+=odd[idx2];
                    idx2++;
                }
            }
        }
        
        if(Alice > Bob)
            cout<<"Alice"<<endl;
        else if(Alice < Bob)
            cout<<"Bob"<<endl;
        else
            cout<<"Tie"<<endl;
    }
    
    return 0;
}
