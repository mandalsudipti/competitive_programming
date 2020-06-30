#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        int cnt=0;
        while(n%6==0 || n%6==3)
        {
            if(n%6==3)
            {
                cnt+=2;
                n=n/3;
            }
            else
            {
                cnt++;
                n=n/6;
            }
        }
        
        if(n!=1)
            cout<<"-1"<<endl;
        else
            cout<<cnt<<endl;
    }
    return 0;
}