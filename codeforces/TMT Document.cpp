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
        string S ;
        cin>>S;
        vector<int>T , M ;
        
        for(int i = 0 ; i < n ; i++)
            S[i] == 'T' ? T.push_back(i) : M.push_back(i) ;
        
        if(T.size() != M.size()*2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            bool flag = true ;
            int T_size = T.size() , idx = 0;
            for(int i = 0 ; i < T_size/2 ; i++)
            {
                if(T[i] > M[idx])
                {
                    flag = false ;
                    break;
                }
                else
                    idx++;
            }
            
            idx = 0 ;
            for(int i = T_size/2 ; i < T_size ; i++)
            {
                if(T[i] < M[idx])
                {
                    flag = false ;
                    break;
                }
                else
                    idx++;
            }
            
            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    
    return 0 ;
}