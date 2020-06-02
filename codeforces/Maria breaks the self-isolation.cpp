#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n+1,0);
        int cnt = n ;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=n;i>=1;i--)
        {
            if(arr[i]>cnt)
                cnt--;
            else
                break;
        }
        cout<<(cnt+1)<<endl;
    }
    return 0;
}