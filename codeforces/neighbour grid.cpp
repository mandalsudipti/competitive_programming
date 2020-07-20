#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        int row , col , x;
        cin>>row>>col;
        bool possible = true ;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>x;
                int y = (i>0) + (i<row-1) + (j>0) + (j<col-1) ;
                if(x>y)
                    possible = false;
            }
        }
        if(!possible)
            cout<<"NO"<<"\n";
        else
        {
            cout<<"YES"<<"\n";
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    int y = (i>0) + (i<row-1)+(j>0)+(j<col-1);
                    cout<<y<<" ";
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}