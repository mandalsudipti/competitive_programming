#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int u , v ;
    cin>>u>>v;
    
    if(u>v || u%2!=v%2)
    {
        cout<<"-1";
        return 0;
    }
    
    if(u==v)
    {
        if(u==0)
            cout<<"0"<<endl;
        else
            cout<<"1\n"<<u<<endl;
        return 0;
    }
    long long int x = (v-u)/2 ;
    if(u&x)
        cout<<"3\n"<<u<<" "<<x<<" "<<x<<endl;
    else
        cout<<"2\n"<<(u^x)<<" "<<x<<endl;
    
    return 0;
}