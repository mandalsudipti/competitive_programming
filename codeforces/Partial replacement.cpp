#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        string S ;
        cin>>S ;
    
        vector<int>star ;
        for(int i = 0 ; i < n ; i++)
        {
            if(S[i] == '*')
                star.push_back(i);
        }
        
        int pre = -1 , count = 0 ;
        for(int i = 0 ; i < star.size() ; i++)
        {
            if(i == 0 || i == star.size()-1)
            {
                pre = star[i] ;
                count++;
            }
            else if( i+1 < star.size() && star[i+1] - pre > k)
            {
                pre = star[i];
                count++;
            }
        }
        
        cout<<count<<endl;
    }
    
    return 0 ;
}
