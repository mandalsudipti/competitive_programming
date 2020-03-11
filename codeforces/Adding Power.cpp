#include<bits/stdc++.h>
using namespace std;

bool base_k(long long int num , int k , vector<int>&ans)
{
    vector<int>arr;
    while(num!=0)
    {
        int x = num%k;
        if(x>1)
            return false;
        arr.push_back(num%k);
        num=num/k;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==1)
            ans.push_back(i);
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k , i;
        cin>>n>>k;
        long long int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        vector<int>ans;
        bool possible=true;
        for(i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                possible=base_k(arr[i],k,ans);
                if(!possible)
                {
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(possible)
        {
            sort(ans.begin(),ans.end());
        
            for(i=1;i<ans.size();i++)
            {
                if(ans[i]==ans[i-1])
                {
                possible=false;
                cout<<"NO"<<endl;
                break;
                }
            }
            if(possible)
                cout<<"YES"<<endl;
        }
    }
    return 0;
}