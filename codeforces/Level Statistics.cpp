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
        bool possible=true;
        int x , y , pre_x=0 ,pre_y=0;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            if(x-pre_x<0 || y-pre_y<0 || x-pre_x<y-pre_y)
                possible=false;
            pre_y=y;
            pre_x=x;
        }
        if(possible)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

