#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , type;
        cin>>n ;
        
        map<int,int>freq ;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>type ;
            freq[type]++ ;
        }
        
        vector<int>type_freq ;
        for(pair<int,int> P : freq)
            type_freq.push_back(P.second) ;
            
        sort(type_freq.begin() , type_freq.end() , greater<int>()) ;
        int total = 0 , pre = INT_MAX ;
        
        for(int i = 0 ; i < type_freq.size() ; i++)
        {
            if(pre == 0)
                break ;
                
            if(type_freq[i] < pre)
            {
                total+=type_freq[i] ;
                pre = type_freq[i] ;
            }
            else
            {
                pre-- ;
                total+=pre ;
            }
        }
        
        cout<<total<<endl;
    }
    
    return 0 ;
}