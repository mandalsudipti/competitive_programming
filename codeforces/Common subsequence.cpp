#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        set<int>val;
        int x ;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            val.insert(x);
        }
        bool flag = false;
        int num = -1 ;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            if(val.find(x)!=val.end())
            {
                flag = true ;
                num = x ;
            }
        }
        if(!flag)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            cout<<"1"<<" "<<num<<endl;
        }
    }
    return 0;
}