#include<bits/stdc++.h>
using namespace std;

void swap(int *a , int *b)
{
    int tmp = *a ;
    (*a) = (*b) ;
    *b = tmp ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    vector<int>arr(n+1);
    vector<int>loc(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        loc[arr[i]]=i;
    }
    vector<pair<int,int>>swap_loc ;
    for(int i=1;i<=n;i++)
    {
        if(loc[i]==i)
            continue;
        int x = i , y = loc[i] , z = arr[i];
        swap(&arr[x],&arr[y]);
        swap(&loc[z],&loc[x]);
        
        if(x>y)
            swap(&x,&y);
            
        if(abs(x-y)>=n/2)
        {
            swap_loc.push_back(make_pair(x,y));
        }
        else if((x-1)>=n/2 && (y-1)>=n/2)
        {
            swap_loc.push_back(make_pair(1,x));
            swap_loc.push_back(make_pair(1,y));
            swap_loc.push_back(make_pair(1,x));
        }
        else if((n-x)>=n/2 && (n-y)>=n/2)
        {
            swap_loc.push_back(make_pair(n,x));
            swap_loc.push_back(make_pair(n,y));
            swap_loc.push_back(make_pair(n,x));
        }
        else
        {
            swap_loc.push_back(make_pair(x,n));
            swap_loc.push_back(make_pair(n,1));
            swap_loc.push_back(make_pair(1,y));
            swap_loc.push_back(make_pair(1,n));
            swap_loc.push_back(make_pair(x,n));
        }
    }
    cout<<swap_loc.size()<<"\n";
    for(int i=0;i<swap_loc.size();i++)
        cout<<swap_loc[i].first<<" "<<swap_loc[i].second<<"\n";
        
    return 0;
    
}


