#include<bits/stdc++.h>
using namespace std;

bool sortbycol(const pair<int,int>&A , const pair<int,int>&B)
{
    if(A.second == B.second )
        return A.first < B.first ;
    else
        return A.second < B.second ;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int col , blocked_cell ;
        cin>>col>>blocked_cell;
        
        vector<pair<int,int>>arr(blocked_cell , make_pair(-1,-1));
        for(int i = 0 ; i < blocked_cell ; i++)
        {
            cin>>arr[i].first>>arr[i].second ;
            arr[i].first--;
            arr[i].second--;
        }
            
        sort(arr.begin() , arr.end() , sortbycol) ;
        vector<pair<int,int>>state_pos ;
        
        int one_one = 0 , zero_one = 1 , one_zero = 2 ;
        int idx = 0 ;
        while(idx < arr.size())
        {
            if(idx + 1 < arr.size() && arr[idx].second == arr[idx+1].second)
            {
                state_pos.push_back(make_pair(one_one , arr[idx].second));
                idx++;
            }
            else if(arr[idx].first == 0)
                state_pos.push_back(make_pair(one_zero , arr[idx].second));
            else
                state_pos.push_back(make_pair(zero_one , arr[idx].second));
                
            idx++;
        }
        
        idx = 0 ;
        bool flag = true ;
        while(idx < state_pos.size())
        {
            if(state_pos[idx].first == one_one)
                idx++;
            else 
            {
                if(idx + 1 >= state_pos.size() || state_pos[idx + 1].first == one_one)
                {
                    flag = false ;
                    break;
                }
                else if(state_pos[idx].first == state_pos[idx+1].first && (state_pos[idx+1].second - state_pos[idx].second - 1)%2 == 1)
                {
                    flag = false ;
                    break;
                }
                else if(state_pos[idx].first != state_pos[idx+1].first && (state_pos[idx+1].second - state_pos[idx].second - 1)%2 == 0)
                {
                    flag = false ;
                    break;
                }
                else
                    idx+=2;
            }
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}