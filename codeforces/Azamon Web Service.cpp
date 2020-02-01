#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int i,j , smallest_idx=0;
    bool flag=true;
    string S , T;
    cin>>S>>T;
    for(i=0;i<S.length()-1;i++)
    {
        smallest_idx=i;
        for(j=i+1;j<S.length();j++)
        {
            if(S[j]<=S[smallest_idx])
            {
                smallest_idx=j;
            }
        }
        if(smallest_idx!=i && S[i]!=S[smallest_idx])
        {
            char tmp=S[smallest_idx];
                S[smallest_idx]=S[i];
                S[i]=tmp;
                break;
        }
    }
    //cout<<S<<endl;
    if(S.compare(T)<0)
        cout<<S<<endl;
    else
        cout<<"---"<<endl;
    
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

