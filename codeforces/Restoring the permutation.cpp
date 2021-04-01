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
        vector<int>arr(n);
        vector<int>inc(n,0);
        vector<int>dec(n,0);
        
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        set<int>S ;
        
        for(int i = 0 ; i < n ;i++)
        {
            if(i == 0)
            {
                inc[i] = arr[i] ;
                for(int j = 1 ; j < arr[i] ; j++)
                    S.insert(j);
            }
            else if(arr[i] == arr[i-1])
            {
                
                inc[i] = (*S.begin());
                //cout<<(*S.begin())<<" "<<inc[i]<<endl;
                S.erase(S.begin());
            }
            else
            {
                inc[i] = arr[i] ;
                for(int j = arr[i-1]+1 ; j < arr[i] ; j++)
                    S.insert(j);
            }
        }
        
        S.clear();
        for(int i = 0 ; i < n ;i++)
        {
            if(i == 0)
            {
                dec[i] = arr[i] ;
                for(int j = 1 ; j < arr[i] ; j++)
                    S.insert(j);
            }
            else if(arr[i] == arr[i-1])
            {
                dec[i] = (*S.rbegin());
                S.erase(--(S.end()));
            }
            else
            {
                dec[i] = arr[i] ;
                for(int j = arr[i-1]+1 ; j < arr[i] ; j++)
                    S.insert(j);
            }
        }
        
        for(int i = 0 ; i < n ;i++)
            cout<<inc[i]<<" ";
        cout<<endl;
        
        for(int i = 0 ; i < n ;i++)
            cout<<dec[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}