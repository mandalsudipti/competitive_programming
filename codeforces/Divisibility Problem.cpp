#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k;
        cin>>n>>k;
        if(n%k==0)
            cout<<"0\n";
        else
            {
                long long int tmp = ((n/k)+1)*k-n;
                cout<<tmp<<endl;
            }
    }
    return 0;
}