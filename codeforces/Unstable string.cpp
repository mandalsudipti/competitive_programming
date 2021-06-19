#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        string S ;
        cin>>S;
        int n = S.length() ;
        
        set<int>partition ;
        int start = -1 , end = -1 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(i-1 >= 0 && S[i] != '?' && S[i] == S[i-1])
                partition.insert(i-1);
            
            if(S[i] == '?')
            {
                if(start == -1)
                    start = end = i ;
                else
                    end = i ;
            }
            
            if(start != -1 && (S[i] != '?' || i == n-1))
            {
                int len = end - start + 1 ;
                if(len%2 == 0 && (start - 1 < 0 || end + 1 >= n || S[start-1] != S[end+1]))
                {
                    for(int j = start ; j <= end ; j++)
                        S[j] = '*';
                }
                else if(len%2 == 1 && (start - 1 < 0 || end+1 >= n || S[start-1] == S[end+1]))
                {
                    for(int j = start ; j <= end ; j++)
                        S[j] = '*';
                }
                else
                    partition.insert(end);
                start = end = -1 ;
            }
        }
        
        long long int count = 0 ;
        
        
        for(int i = 0 ; i < n ; i++)
        {
            int len ;
            auto itr = partition.lower_bound(i) ;
            
            if(itr == partition.end())
                len = n - i ;
            else
            {
                if(S[i] != '?')
                    len = (*itr) - i + 1 ;
                else
                {
                    if(S[(*itr)] == '?')
                        ++itr ;
                    if(itr == partition.end())
                        len = n - i ;
                    else
                        len = (*itr) - i + 1 ;
                }
            }
            count+=len; 
        }
        cout<<count<<endl;
    }
    
    return 0 ;
}