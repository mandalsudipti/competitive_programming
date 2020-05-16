#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k;
        cin>>n>>k;
        int freq = n/k , rem = n%k ;
        string S;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<freq;j++)
                S+=('a'+i);
        }
        for(int i=0;i<rem;i++)
            S+=('a'+i);
        cout<<S<<endl;
    }
    return 0;
}