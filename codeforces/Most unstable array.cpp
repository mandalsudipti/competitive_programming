#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , sum ;
        cin>>n>>sum;
        if(n==1)
            cout<<"0"<<endl;
        else if(n==2)
            cout<<sum<<endl;
        else
            cout<<(sum*2)<<endl;
    }
    return 0;
}

