#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    cout<<8*(n+1)-n<<endl;
    int row = 2*n+2;
    bool left = false;
    for(int i=0;i<=row;i++)
    {
        if(i==0 || (i==row && n%2==0))
        {
            for(int j=0;j<3;j++)
                cout<<j<<" "<<i<<endl;
            continue;
        }
        if(i==row && n%2==1)
        {
            for(int j=2;j<=4;j++)
                cout<<j<<" "<<i<<endl;
            continue;
        }
        if(i%2)
        {
            if(!left)
            {
                cout<<"0"<<" "<<i<<endl;
                cout<<"2"<<" "<<i<<endl;
                left=true;
            }
            else
            {
                cout<<"2"<<" "<<i<<endl;
                cout<<"4"<<" "<<i<<endl;
                left=false;
            }
        }
        else
        {
            for(int j=0;j<5;j++)
                cout<<j<<" "<<i<<endl;
        }
    }
    return 0;
}
