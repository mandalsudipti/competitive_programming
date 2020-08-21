#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int r , g , b , w ;
        cin>>r>>g>>b>>w ;
        int odd = (r%2) + (g%2) + (b%2) ;
        if(odd==0 || odd==3)
            cout<<"Yes"<<endl;
        else if(odd==1 && (w%2==0))
            cout<<"Yes"<<endl;
        else if(odd==2 && (w%2)==1)
        {
            if((r>0 && r%2==0) || (g>0 && g%2==0) || (b>0 && b%2==0))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}