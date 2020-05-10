#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string S;
    cin>>n>>S;
    int depth_zero = 0 ,depth_one = 0 ;
    string ans;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            depth_one++;
            ans+='1';
            continue;
        }
        if(S[i]=='(')
        {
            if(depth_one<=depth_zero)
            {
                depth_one++;
                ans+='1';
            }
            else
            {
                depth_zero++;
                ans+='0';
            }
        }
        else if(S[i]==')')
        {
            if(depth_one>=depth_zero)
            {
                depth_one--;
                ans+='1';
            }
            else
            {
                depth_zero--;
                ans+='0';
            }
        }
    }
    cout<<ans;
    return 0;
}