#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>type(n);
        int cnt = 1 ;
        for(int i=0;i<n;i++)
        {
            cin>>type[i];
            if(i>0 && type[i]==type[0])
                cnt++;
        }
        if(cnt==n)
        {
            cout<<"1"<<endl;
            for(int i=0;i<n;i++)
                cout<<"1 ";
            cout<<endl;
            continue;
        }
            
        vector<int>ans(n);
        for(int i=0;i<n;i++)
            i%2==0 ? ans[i] = 1 : ans[i]=2 ;
            
        if(type[0]!=type[n-1] && ans[0]==ans[n-1])
        {
            if(type[n-1]==type[n-2])
                ans[0]==1 ? ans[n-1]=2 : ans[n-1]=1;
            else
            {
                bool find = false;
                for(int j=n-2;j>0;j--)
                {
                    if(type[j]==type[j-1])
                    {
                        find = true;
                        for(int k=j;k<n;k++)
                            ans[k]==2 ? ans[k]=1 : ans[k] =2;
                        break;
                    }
                }
                if(!find)
                    ans[n-1]=3;
            }
        }
        int max_color = 0;
        for(int i=0;i<n;i++)
            max_color = max(max_color,ans[i]);
        cout<<max_color<<endl;
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
