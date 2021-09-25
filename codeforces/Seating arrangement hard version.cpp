#include<bits/stdc++.h>
using namespace std ;

bool sortbypos(const pair<int,int>& A , const pair<int,int>& B)
{
    return A.second < B.second ;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        
        vector<pair<int,int>>eyesight_loc(n*m) ;
        int eyesight ;
        
        for(int i = 0 ; i < n*m ; i++)
        {
            cin>>eyesight ;
            eyesight_loc[i] = make_pair(eyesight , i);
        }
        sort(eyesight_loc.begin() , eyesight_loc.end());
        
        long long int total_inconvenience = 0 ;
        for(int i = 0 ; i < n*m ; i+=m)
        {
            sort(eyesight_loc.begin()+i , eyesight_loc.begin()+i+m , sortbypos) ;
            int start = i ;
            
            for(int j = start + 1; j < start + m ; j++)
            {
                for(int k = start ; k < j ; k++)
                {
                    if(eyesight_loc[k].first < eyesight_loc[j].first)
                        total_inconvenience++ ;
                }
            }
        }
        
        cout<<total_inconvenience<<endl;
    }
    
    return 0 ;
}