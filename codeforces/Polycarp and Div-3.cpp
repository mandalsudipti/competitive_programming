#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    int idx=-1 , cnt=0;
    for(int i=0;i<S.length();i++)
    {
        if(i==0)
        {
            if((S[i]-48)%3==0)
            {
                cnt++;
                idx=1;
            }
            else
                idx=0;
            continue;
        }
        if((S[i]-48)%3==0)
        {
            cnt++;
            idx=i+1;
        }
        else
        {
            if(i-idx==2)
            {
                cnt++;
                idx=i+1;
            }
            else if(idx==i-1 && (S[i]+S[i-1]-96)%3==0)
            {
                cnt++;
                idx=i+1;
            }
        }
    }
    cout<<cnt;
    
    return 0;
}