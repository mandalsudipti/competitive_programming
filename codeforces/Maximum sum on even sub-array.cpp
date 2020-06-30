#include<bits/stdc++.h>
using namespace std;

long long int max_subarray(vector<long long int>&pair_diff)
{
    long long int maximum =  INT_MIN , cur_max = 0 ;
        for(int i=0;i<pair_diff.size();i++)
        {
            cur_max+=pair_diff[i];
            if(cur_max>maximum)
                maximum = cur_max;
            if(cur_max<0)
                cur_max=0;
        }
    return maximum;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        long long int arr[n] , sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i%2==0)
                sum+=arr[i];
        }
        vector<long long int>pair_diff;
        for(int i=0;i<n;i+=2)
        {
            if(i+1>=n)
                continue;
            pair_diff.push_back(arr[i+1]-arr[i]);
        }
        long long int maximum = max_subarray(pair_diff);
        vector<long long int>x;
        for(int i=1;i<n;i+=2)
        {
            if(i+1<n)
            {
                x.push_back(arr[i]-arr[i+1]);
            }
        }
        maximum = max(maximum , max_subarray(x));
        if(maximum>0)
            sum+=maximum;
        //cout<<maximum<<endl;
        cout<<sum<<endl;
    }
    return 0;
}