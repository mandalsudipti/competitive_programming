#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<pair<int,int>>points(4*n+1);
    map<int,int>X_freq;
    map<int,int>Y_freq;
    int x , y;
    for(int i=0;i<4*n+1;i++)
    {
        cin>>x>>y;
        points[i]=make_pair(x,y);
        X_freq[x]++;
        Y_freq[y]++;
    }
    
    int x_min=100 , x_max=-1 , y_min=100 , y_max=-1;
    for(auto itr=X_freq.begin();itr!=X_freq.end();++itr)
    {
        if(itr->second>=n)
        {
            x_min = min(x_min,itr->first);
            x_max = max(x_max,itr->first);
        }
    }
    for(auto itr=Y_freq.begin();itr!=Y_freq.end();++itr)
    {
        if(itr->second>=n)
        {
            y_min = min(y_min,itr->first);
            y_max = max(y_max,itr->first);
        }
    }
    //cout<<x_min<<" "<<x_max<<" "<<y_min<<" "<<y_max<<endl;
    for(int i=0;i<4*n+1;i++)
    {
        int x = points[i].first , y = points[i].second ;
        if((x==x_max || x==x_min) && y>=y_min && y<=y_max)
        {
            continue;
        }
        else if((y==y_max || y==y_min) && x>=x_min && x<=x_max)
        {
            continue;
        }
        else
        {
            cout<<x<<" "<<y;
            break;
        }
    }
    return 0;
}
