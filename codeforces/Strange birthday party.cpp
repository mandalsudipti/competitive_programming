#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        vector<int>friends(n);
        vector<long long int>present(m+1);
        
        for(int i = 0 ; i < n ; i++)
            cin>>friends[i];
        for(int i = 1 ; i <= m ; i++)
            cin>>present[i];
            
        long long int total = 0 ;
        sort(friends.begin() , friends.end() , greater<long long int>());
        int idx = 1 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(idx < friends[i])
            {
                total+=present[idx];
                idx++;
            }
            else
                total+=present[friends[i]];
        }
        
        cout<<total<<endl;
    }
    
    return 0;
}