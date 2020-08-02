#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node , edge ;
    cin>>node>>edge;
    long long int minimum = node-1 ;
    if(edge<minimum)
    {
        cout<<"Impossible";
        return 0;
    }
    vector<pair<int,int>>ans;
    int cnt = 0 ;
    for(int i=1;i<=node;i++)
    {
        if(cnt>=edge)
            break;
        if(i==1)
        {
            for(int j=2;j<=node;j++)
            {
                ans.push_back(make_pair(1,j));
                cnt++;
            }
            continue;
        }
        for(int j=i+1;j<=node;j++)
        {
            if(cnt>=edge)
                break;
            if(__gcd(j,i)==1)
            {
                ans.push_back(make_pair(i,j));
                cnt++;
            }
        }
    }
    if(ans.size()!=edge)
        cout<<"Impossible";
    else
    {
        cout<<"Possible\n";
        for(int i=0;i<edge;i++)
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
