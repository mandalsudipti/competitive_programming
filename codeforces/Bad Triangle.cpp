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
        int n ;
        cin>>n;
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        if(arr[n-1]>=arr[0]+arr[1])
        {
            cout<<1<<" "<<2<<" "<<n<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
