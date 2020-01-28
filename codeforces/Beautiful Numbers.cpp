#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int i , pos[n+1],val,left,right,ans[n+1],diff;
        for(i=1;i<=n;i++)
        {
            cin>>val;
            pos[val]=i;
        }
        left=right=pos[1];
        ans[1]=1;
        ans[n]=1;
        for(i=2;i<n;i++)
        {
            if(pos[i]>right)
                right=pos[i];
            else if(pos[i]<left)
                left=pos[i];
            diff=right-left;
            if(diff<i)
                ans[i]=1;
            else
                ans[i]=0;
        }
        for(i=1;i<=n;i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}