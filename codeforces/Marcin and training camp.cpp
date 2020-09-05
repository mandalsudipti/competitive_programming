#include<bits/stdc++.h>
using namespace std;

bool possible(set<long long int>&ele , long long int num)
{
    for(auto itr=ele.begin();itr!=ele.end();++itr)
    {
        long long int tmp = (*itr) , x = num;
        bool flag = true ;
        for(int i=0;i<61;i++)
        {
            if(tmp==0 && x==0)
                break;
            if(tmp%2==0 && x%2==1)
            {
                flag = false;
                break;
            }
            tmp = tmp/2;
            x = x/2;
        }
        if(flag)
        {
            ele.insert(num);
            return true;
        }
    }
    return false;
}

int main()
{
    int n ;
    cin>>n;
    vector<vector<long long int>>arr(n,vector<long long int>(2));
    map<long long int , int>freq;
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0];
        freq[arr[i][0]]++;
    }
    
    for(int i=0;i<n;i++)
        cin>>arr[i][1];
        
    long long int total_cost = 0 ;
    set<long long int>ele;
    for(int i=0;i<n;i++)
    {
        if(freq[arr[i][0]]>1)
        {
            total_cost+=arr[i][1] ;
            ele.insert(arr[i][0]);
        }
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        if(freq[arr[i][0]]==1 && possible(ele,arr[i][0]))
        {
            total_cost+=arr[i][1];
        }
    }
    
    cout<<total_cost<<endl;
    
    return 0;
}