#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int block , tower , max_diff , block_height;
        cin>>block>>tower>>max_diff ;
        
        multiset<pair<long long int , int>>tower_height ;
        
        for(int i = 1 ; i <= tower ; i++)
            tower_height.insert(make_pair(0 , i)) ;
            
        cout<<"YES"<<endl;
        for(int i = 0 ; i < block ; i++)
        {
            cin>>block_height ;
            int smallest_tower = (*tower_height.begin()).second , smallest_height = (*tower_height.begin()).first ;
            tower_height.erase(tower_height.begin()) ;
            
            cout<<smallest_tower<<" ";
            tower_height.insert(make_pair(smallest_height + block_height , smallest_tower));
        }
        cout<<endl;
    }
    return 0 ;
}