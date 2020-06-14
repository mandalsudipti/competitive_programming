#include<bits/stdc++.h>
using namespace std;

bool not_order(int arr[] , int n , int idx)
{
    for(int i=idx+1;i<n;i++)
    {
        if(arr[i]-arr[i-1]!=1)
            return true;
    }
    return false;
}

int find(int num , int arr[] , int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
            return i;
    }
    return 0;
}

int main()
{
    int n ;
    cin>>n;
    int A[n] , B[n] ;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    int move = 0 , start = -1 , end = n-1;
    for(int i=0;i<n;i++)
    {
        start = i;
        if(B[i]==1 && not_order(B,n,i))
            move = i ;
        else if(B[i]==1 && !not_order(B,n,i))
        {
            move = find(B[n-1]+1,B,n) ;
            start = move ;
            end = i-1 ;
        }
    }
    vector<int>diff;
    for(int i=start;i<=end;i++)
    {
        if(B[i]-B[start]<i-start)
            diff.push_back((i-start)-(B[i]-B[start]));
    }
    int x  = 0 ;
    for(int i=0;i<diff.size();i++)
    {
        move+=min(0,diff[i]-x) ;
        x = max(diff[i],x);
    }
    cout<<move<<endl;
    
    return 0;
}
