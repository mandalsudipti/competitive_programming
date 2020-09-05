#include<bits/stdc++.h>
using namespace std;

bool sort_by_endurance(const vector<long long int>&A , vector<long long int>&B)
{
    if(A[1]==B[1])
    {
        return A[0]<B[0];
    }
    else
        return A[1]<B[1];
}

void build_tree(int root , vector<long long int>&monster , vector<long long int>&tree , int left , int right)
{
    if(left==right)
    {
        tree[root] = monster[left];
        return;
    }
    
    int mid = (left+right)/2 ;
    build_tree(2*root , monster , tree , left , mid);
    build_tree(2*root + 1 , monster , tree , mid+1 , right);
    
    tree[root] = max(tree[2*root + 1] , tree[2*root]);
}

long long int get_max(int root , vector<long long int>&tree , int left , int right , int query_left , int query_right)
{
    if(left>query_right || right<query_left)
        return 0;
        
    if(query_left<=left && query_right>=right)
        return tree[root];
        
    int mid = (left+right)/2 ;
    long long int x = get_max(2*root , tree , left , mid , query_left , query_right);
    long long int y = get_max(2*root + 1 , tree , mid+1 , right , query_left , query_right);
    
    return max(x,y);
}

void solve()
{
    int n ;
    cin>>n;
    vector<long long int>monster(n+1);
    for(int i=1;i<=n;i++)
        cin>>monster[i];
        
    vector<long long int>tree(4*(n+10));
    build_tree(1,monster,tree,1,n);
    
    int m;
    cin>>m;
    vector<vector<long long int>>hero(m+1,vector<long long int>(2));
    for(int i=1;i<=m;i++)
        cin>>hero[i][0]>>hero[i][1];
        
    sort(hero.begin(),hero.end(),sort_by_endurance);
    
    vector<long long int>max_power_for_endurance(n+5,0);
    
    for(int i=1;i<=m;i++)
        max_power_for_endurance[hero[i][1]] = max(hero[i][0] , max_power_for_endurance[hero[i][1]]) ;
    
    for(int i=n-1;i>=1;i--)
        max_power_for_endurance[i] = max(max_power_for_endurance[i+1] , max_power_for_endurance[i]) ;
        
    long long int days = 0 ;
    
    for(int i=1;i<=n;days++)
    {
        if(max_power_for_endurance[n-i+1]>= get_max(1,tree,1,n,i,n))
        {
            days++;
            break;
        }
        
        int left = 0 , right = n - i + 1 ;
        while(right - left > 1)
        {
            int mid = (left+right)/2 ;
            if(max_power_for_endurance[mid]>= get_max(1,tree,1,n,i,i+mid-1))
                left = mid ;
            else 
                right = mid ;
                
        }
        
        if(left==0)
        {
            cout<<"-1"<<endl;
            return;
        }
        
        i = i + left ;
    }
    
    cout<<days<<endl;
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