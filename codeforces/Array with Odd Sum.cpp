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
        int val,i,cnt_odd=0 , cnt_even=0;
        for(i=0;i<n;i++)
        {
          cin>>val;
          if(val%2==0)
            cnt_even++;
          else
            cnt_odd++;
        }
        if(cnt_odd%2==1)
            cout<<"YES\n";
        else if(cnt_odd==0)
            cout<<"NO\n";
        else if (cnt_odd%2==0)
        {
            if(cnt_even>=1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}