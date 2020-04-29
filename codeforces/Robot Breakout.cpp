#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int left , up , right , down , x , y ;
    vector<vector<int>>range;
    while(n--)
    {
        vector<int>cur;
        cin>>x>>y>>left>>up>>right>>down;
        left==1?cur.push_back(-100000):cur.push_back(x);
        up==1?cur.push_back(100000):cur.push_back(y);
        right==1?cur.push_back(100000):cur.push_back(x);
        down==1?cur.push_back(-100000):cur.push_back(y);
        range.push_back(cur);
    }
    int left_max=range[0][0] , up_min=range[0][1] , right_min=range[0][2] , down_max=range[0][3] ;
    for(int i=1;i<range.size();i++)
    {
        left_max = max(left_max,range[i][0]);
        up_min = min(up_min,range[i][1]);
        right_min=min(right_min,range[i][2]);
        down_max = max(down_max,range[i][3]);
    }
    if(left_max>right_min || up_min<down_max)
        cout<<"0"<<endl;
    else
        cout<<"1"<<" "<<left_max<<" "<<up_min<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}