#include<bits/stdc++.h>
using namespace std;
const int range = 1000005;
int main()
{
    vector<int>freq(range,0);
    int n ;
    cin>>n;
    long long int arr[n+1];
    long long int sum = 0 ;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        freq[arr[i]]++;
    }
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        sum-=arr[i];
        if(sum%2==1)
        {
            sum+=arr[i];
            continue;
        }
        freq[arr[i]]--;
        long long int x = sum/2 ;
        if(x>0 && x<range && freq[x]>0)
            ans.push_back(i);
        sum+=arr[i];
        freq[arr[i]]++;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}


