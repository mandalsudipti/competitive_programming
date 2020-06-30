#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , k ;
    cin>>n>>k;
    vector<vector<long long int>>arr(n,vector<long long int>(3,0));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    sort(arr.begin(),arr.end());
    
    priority_queue<long long int>Alice ;
    priority_queue<long long int>Bob;
    vector<long long int>extra;
    
    long long int total_cost = 0 , A_cnt=0 ,B_cnt=0 ;
    
    int i;
    for(i=0;i<n && (min(A_cnt,B_cnt)<k);i++)
    {
        if(arr[i][1] && arr[i][2])
        {
            total_cost+=arr[i][0];
            if(A_cnt>=k)
            {
                total_cost-=Alice.top() ;
                Alice.pop();
                A_cnt--;
            }
            A_cnt++;
            
            if(B_cnt>=k)
            {
                total_cost-=Bob.top();
                Bob.pop();
                B_cnt--;
            }
            B_cnt++;
        }
        else if(A_cnt<k && arr[i][1]==1)
        {
            total_cost+=arr[i][0];
            A_cnt++;
            Alice.push(arr[i][0]);
        }
        else if(B_cnt<k && arr[i][2]==1)
        {
            total_cost+=arr[i][0];
            B_cnt++;
            Bob.push(arr[i][0]);
        }
    }
    for(;i<n;i++)
    {
        if(arr[i][1] && arr[i][2] &&!Alice.empty() && !Bob.empty() && (Alice.top()+Bob.top()>arr[i][0]))
        {
            total_cost+=arr[i][0];
            total_cost-=(Alice.top()+Bob.top());
            Alice.pop();
            Bob.pop();
        }
    }
    
    (A_cnt>=k && B_cnt>=k) ? cout<<total_cost : cout<<"-1";
    
    return 0;
}
