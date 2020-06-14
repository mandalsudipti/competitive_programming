#include<bits/stdc++.h>
using namespace std;

long long int find_min( vector<pair<long long int,long long int>>&sorted_arr , int *l_idx , int start)
{
    int tmp = *l_idx;
    for(int i=tmp;i<sorted_arr.size();i++)
    {
        if(sorted_arr[i].second>=start)
        {
            (*l_idx) = i ;
            return sorted_arr[i].first;
        }
    }
    return -1;
}

long long int find_max(vector<pair<long long int,long long int>>&sorted_arr , int *r_idx , int start)
{
    int tmp = *r_idx ;
    for(int i=tmp;i>=0;i--)
    {
        if(sorted_arr[i].second>=start)
        {
            (*r_idx) = i;
            return sorted_arr[i].first;
        }
    }
    return -1;
}

int main()
{
    long long int n , p , q , r ;
    cin>>n>>p>>q>>r;
    
    long long int arr[n] , left_min[n] , left_max[n] , right_min[n] , right_max[n] ;
    vector<pair<long long int , long long int>>sorted_arr(n) ;
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sorted_arr[i] = make_pair(arr[i],i);
    }
    sort(sorted_arr.begin(),sorted_arr.end());
    
    int l_idx = 0 , r_idx = n-1 ;
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            left_max[i]=arr[0];
            left_min[i]=arr[0];
            right_max[i]=sorted_arr[r_idx].first;
            right_min[i]=sorted_arr[l_idx].first;
            continue;
        }
        arr[i]<left_min[i-1]?left_min[i]=arr[i]:left_min[i]=left_min[i-1];
        arr[i]>left_max[i-1]?left_max[i]=arr[i]:left_max[i]=left_max[i-1];
        
        arr[i-1]==right_min[i-1]? right_min[i]=find_min(sorted_arr,&l_idx,i):right_min[i]=right_min[i-1];
        arr[i-1]==right_max[i-1]? right_max[i] = find_max(sorted_arr,&r_idx,i):right_max[i]=right_max[i-1];
    }
    
    long long int max_val ;
    for(int i=0;i<n;i++)
    {
        long long int x = p*(p<0?left_min[i]:left_max[i]);
        x+=(q*arr[i]);
        x+= r * (r<0?right_min[i]:right_max[i]);
        if(i==0)
            max_val = x ;
        else
            max_val = max(max_val,x);
    }
    
    cout<<max_val<<endl;
}

