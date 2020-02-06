#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    string S;
    cin>>n>>S;
    
    vector<int> color(n);
    for(i=0;i<n;i++)
        color[i]=-1;
    for(i=0;i<n;i++)
    {
        if(color[i]==-1)
            color[i]=0;
        for(j=i+1;j<n;j++)
        {
            if(S[j]<S[i] && color[i]==1)
            {
                cout<<"NO";
                return 0;
            }
            else if (S[j]<S[i] && color[i]==0)
            {
                color[j]=1;
            }
        }
    }
    cout<<"YES\n";
    for(i=0;i<n;i++)
        cout<<color[i];
    return 0;
}
