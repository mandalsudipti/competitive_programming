#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>ans;

void solve_diff(vector<pair<int,int>>&arr)
{
    int x = arr[1].first + 1 , y = arr[0].second  ;
    for(int i=x;i<=arr[2].first;i++)
        ans.push_back(make_pair(i,y));
        
    if(arr[2].second > y)
        for(int i=y + 1;i<=arr[2].second;i++)
            ans.push_back(make_pair(arr[2].first,i));
    else
        for(int i=y - 1 ; i>=arr[2].second ; i--)
            ans.push_back(make_pair(arr[2].first,i));
}

void solve_upper(vector<pair<int,int>>&arr)
{
    int x = arr[1].first + 1 , y = min(arr[1].second , arr[2].second);
    
    for(int i=x;i<=arr[2].first;i++)
        ans.push_back(make_pair(i,y));
        
    if(arr[2].second > arr[1].second)
        for(int i=y+1;i<=arr[2].second;i++)
            ans.push_back(make_pair(arr[2].first,i));
}

void solve_lower(vector<pair<int,int>>&arr)
{
    int x = arr[1].first + 1 , y = max(arr[1].second , arr[2].second);
    
    for(int i=x;i<=arr[2].first;i++)
        ans.push_back(make_pair(i,y));
        
    if(arr[2].second < arr[1].second)
        for(int i=y-1;i>=arr[2].second;i--)
            ans.push_back(make_pair(arr[2].first,i));
}

int main()
{
    vector<pair<int,int>>arr(3);
    int x , y ;
    for(int i=0;i<3;i++)
    {
        cin>>x>>y;
        arr[i] = make_pair(x,y);
    }
    sort(arr.begin(),arr.end());
    
    for(int i=arr[0].first;i<=arr[1].first;i++)
        ans.push_back(make_pair(i,arr[0].second));
        
    if(arr[1].second >= arr[0].second)
    {
        for(int i=arr[0].second+1 ;i<=arr[1].second ; i++)
            ans.push_back(make_pair(arr[1].first , i));
    }
    else
    {
        for(int i=arr[0].second - 1 ;i>=arr[1].second ; i--)
            ans.push_back(make_pair(arr[1].first , i));
    }
    
    if(arr[1].second <= arr[0].second && arr[2].second <= arr[0].second)
        solve_lower(arr);
    else if(arr[1].second >= arr[0].second && arr[2].second >= arr[0].second)
        solve_upper(arr);
    else
        solve_diff(arr);
        
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
        
    return 0;
}



