#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k;
    long long int sum=0;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    string S;
    cin>>S;
    int start=0 , end=0 , i=1;
    for(i=1;i<n;i++)
    {
        if(S[i]==S[start])
            end++; 
        if(S[i]!=S[start]|| i==n-1)
        {
            //cout<<start<<" ";
            sort(arr+start,arr+end+1,greater<int>());
            for(int j=start;j<=min(end,start+k-1);j++)
               { sum+=arr[j]; }
            start=end+1;
            end=start;
            //cout<<start<<" "<<i<<endl;
        }
    }
    if(S[n-1]!=S[n-2])
        sum+=arr[n-1];
    cout<<sum;
    return 0;
}
