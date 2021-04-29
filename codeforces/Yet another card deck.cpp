#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n , q ;
    cin>>n>>q;
    
    vector<int>card(n+1);
    map<int,int>best_card ;
    
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>card[i] ;
        if(best_card.find(card[i]) == best_card.end())
            best_card[card[i]] = i ;
    }
    
    while(q--)
    {
        int find_card ;
        cin>>find_card ;
        int pos = best_card[find_card] ;
        for(auto itr = best_card.begin() ; itr != best_card.end() ; ++itr)
        {
            if(itr->second < pos)
                itr->second++;
        }
        best_card[find_card] = 1 ;
        cout<<pos<<" ";
    }
    
    return 0 ;
}