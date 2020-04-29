#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n ,val;;
    cin>>n;
    set<int>entered ;
    set<int>cur_state;
    vector<int>partition;
    if(n==1)
    {
        cout<<"-1";
        return 0;
    }
    
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        if(val<0)
        {
            if(cur_state.find(abs(val))!=cur_state.end() )
                cur_state.erase(cur_state.find(abs(val)));
            else
            {
                cout<<"-1";
                return 0;
            }
            if(cur_state.size()==0)
            {
                partition.push_back(i);
                entered.clear();
            }
        }
        else if(val>0)
        {
            if(cur_state.find(val)!=cur_state.end() || entered.find(val)!=entered.end())
            {
                cout<<"-1";
                return 0;
            }
            else
            {
                cur_state.insert(val);
                entered.insert(val);
            }
        }
    }
    
    if(cur_state.size()!=0)
    {
        cout<<"-1";
        return 0;
    }
        
    cout<<partition.size()<<endl;
    for(int i=0;i<partition.size();i++)
    {
        if(i==0)
        {
            cout<<partition[i]<<" ";
            continue;
        }
        cout<<partition[i]-partition[i-1]<<" ";
    }
    
    return 0;
}
