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
        int prince[n+1],princess[n+1],len,val;
        memset(prince,0,sizeof(prince));
        memset(princess,0,sizeof(princess));
        for(int i=1;i<=n;i++)
        {
            cin>>len;
            for(int j=1;j<=len;j++)
            {
                cin>>val;
                if(princess[i]==0 && prince[val]==0)
                {
                    prince[val]=1;
                    princess[i]=1;
                }
            }
            
        }
        bool optimal=true;
        int i=1;
        while(i<=n)
        {
            if(princess[i]==0)
            {
                for(int j=1;j<=n;j++)
                {
                    if(prince[j]==0)
                    {
                        optimal=false;
                        cout<<"IMPROVE\n";
                        cout<<i<<" "<<j<<endl;
                        i=n+1;
                        break;
                    }
                }
            }
            i++;
        }
        if(optimal)
            cout<<"OPTIMAL\n";
    }
    return 0;
}
