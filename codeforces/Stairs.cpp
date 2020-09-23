#include<bits/stdc++.h>
using namespace std;

const long long int range = 1e18+5 ;

int main()
{
    vector<long long int>nice_col ;
    vector<long long int>nice_cell;
    
    nice_cell.push_back(1);
    nice_col.push_back(1) ;
    
    long long int idx = 1 ;
    while( nice_cell.back() + ((2*idx+1)*(2*idx+2))/2<=range)
    {
        nice_col.push_back(idx + (idx+1));
        nice_cell.push_back( nice_cell.back() + ((2*idx+1)*(2*idx+2))/2);
        
        idx+=(idx+1);
    }
    
    int T;
    cin>>T;
    while(T--)
    {
        long long int num;
        cin>>num;
        
        int x = lower_bound(nice_cell.begin(),nice_cell.end(),num) - nice_cell.begin() ;
        if(x>=nice_cell.size() || nice_cell[x]>num)
            x--;
        cout<<x+1<<endl;
    }
    
    return 0;
}