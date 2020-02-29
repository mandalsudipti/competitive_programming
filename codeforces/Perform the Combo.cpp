#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int len , error ;
    cin>>len>>error;
    string S;
    cin>>S;
    int arr[error] , letter[26] ,itr, i;
    itr=error+1;
    memset(letter,0,sizeof(letter));
    for(i=0;i<error;i++)
        cin>>arr[i];
    sort(arr,arr+error);
    for(i=0;i<error;i++)
    {
        if(i==0 || arr[i]!=arr[i-1])
        {
            int pre = (i==0?0:arr[i-1]);
            for(int j=pre;j<arr[i];j++)
            {
                letter[S[j]-'a']+=itr-i;
            }
        }
    }
    for(i=arr[error-1];i<S.length();i++)
    {
        letter[S[i]-'a']++;
    }
        
    for(i=0;i<26;i++)
        cout<<letter[i]<<" ";
    cout<<"\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}