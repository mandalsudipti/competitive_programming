#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string S;
    cin>>S;
    int one=-1 , two=-1 , three=-1;
    int min_len = S.length()+10,len;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]=='1')
            one=i;
        else if(S[i]=='2')
            two=i;
        else
            three=i;
        if(one!=-1 && two!=-1 && three!=-1)
        {
            len=max(one,max(two,three)) - min(one,min(two,three))+1;
            min_len = min(len,min_len);
        }
    }
    if(min_len>S.length())
        cout<<"0"<<endl;
    else
        cout<<min_len<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}