#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    vector<char>ans(n,'a');
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(freq[arr[i]]==1)
        {
            cnt++;
            cnt%2==1?ans[i]='A':ans[i]='B';
        }
    }
    bool possible = true ;
    if(cnt%2==1)
    {
        possible=false;
        for(int i=0;i<n;i++)
        {
            if(freq[arr[i]]>2)
            {
                ans[i]='B';
                possible=true;
                break;
            }
        }
    }
    if(!possible)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        if(ans[i]=='a')
            cout<<'A';
        else
            cout<<ans[i];
    }
    return 0;
}