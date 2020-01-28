#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        map<char,int> alpha;
        for(char x='a';x<='z';x++)
            alpha.insert({x,0});
        string S;
        cin>>S;
        int cnt=1,i;
        if(S.length()==1)
            cout<<S<<endl;
        else
        {
            for(i=0;i<S.length()-1;i++)
            {
                if(S[i]==S[i+1])
                    cnt++;
                if((S[i]!=S[i+1])||(i==S.length()-2))
                {
                    //cout<<cnt;
                    if(cnt%2!=0 && alpha[S[i]]==0)
                    {
                        alpha[S[i]]=1;
                    }
                    cnt=1;
                }
            }
            if(S[S.length()-1]!=S[S.length()-2])
                {
                    //include it
                    //cout<<"1";
                    alpha[S[S.length()-1]]=1;
                }
            for(char x='a';x<='z';x++)
            {
                if(alpha[x]==1)
                    cout<<x;
            }
            cout<<endl;
        }
    }
    return 0;
}
