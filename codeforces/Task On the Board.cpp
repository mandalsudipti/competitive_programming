#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    string S ;
    cin>>S;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int>freq(26,0);
    for(int i=0;i<S.length();i++)
    {
        freq[S[i]-'a']++;
    }
    
    vector<char>ans(n);
    int processed = 0 ;
    while(processed<n)
    {
        vector<int>zero ;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                zero.push_back(i);
        }
        for(int i=25;i>=0;i--)
        {
            if(freq[i]>=zero.size())
            {
                for(int j=0;j<zero.size();j++)
                {
                    ans[zero[j]] = i+'a';
                    arr[zero[j]] =-1 ;
                }
                freq[i] = 0 ;
                processed+=zero.size();
                break;
            }
            else
                freq[i] = 0;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==-1)
                continue;
            for(int j=0;j<zero.size();j++)
            {
                int pos = zero[j] ;
                arr[i]-=abs(i-pos);
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<ans[i];
    cout<<endl;
}

int main()
{
    int query ;
    cin>>query;
    while(query--)
    {
        solve();
    }
    return 0;
}

