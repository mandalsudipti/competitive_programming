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
        long long int grp = k/(n-1) + (k%(n-1ll)!=0);
        long long int idx = k - (n-1)*(grp-1);
        long long int val = (idx)+(n*(grp-1));
        //if(val==0)
            //val=idx+1;
        cout<<val<<endl;
    }
    return 0;
}