#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int num = 4*n , cnt = 0 ;
        while(cnt<n)
        {
            cout<<num<<" ";
            num-=2;
            cnt++;
        }
        cout<<endl;
    }
    
    return 0;
}
