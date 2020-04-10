#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<long long int>arr(n+1,0);
    vector<long long int>prefix_sum(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }
    int end_point=0; 
    long long int ans=0;
    map<long long , int> freq;
    map<long long , int>last_occur;
    freq[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(freq[prefix_sum[i]]!=0) //it has occured before
        {
            end_point= max(end_point,last_occur[prefix_sum[i]]+2);
        }
        freq[prefix_sum[i]]=i;
        last_occur[prefix_sum[i]]=i;
        int distance = (end_point==0?i:i- end_point+1);
        ans+=(distance>0?distance:0);
    }
    cout<<ans<<endl;
    return 0;
}