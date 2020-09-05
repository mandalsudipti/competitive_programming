#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        int x ;
        cin>>x;
        vector<char>ans(S.length(),'2');
        
        bool possible = true ;
        for(int i=0;i<S.length();i++)
        {
            if(i-x<0)
            {
                if(i+x<S.length())
                    S[i]=='0' ? ans[i+x]='0' : ans[i+x] = '1' ;
                if(i+x>=S.length() && S[i]=='1')
                {
                    possible = false;
                    break;
                }
            }
            else
            {
                if(S[i]=='0')
                {
                    if((i-x>=0 && ans[i-x]=='1') || (i+x<S.length() && ans[i+x]=='1'))
                    {
                        possible = false ;
                        break;
                    }
                    else
                    {
                        if(i-x>=0)
                            ans[i-x]='0';
                        if(i+x<S.length())
                            ans[i+x]='0';
                    }
                        
                }
                else
                {
                    if(ans[i-x]=='0' && (i+x>=S.length() || ans[i+x]=='0'))
                    {
                        possible = false;
                        break;
                    }
                    else
                    {
                        if(ans[i-x]=='0')
                            ans[i+x] = '1';
                        else
                            ans[i-x] = '1';
                    }
                }
            }
        }
        
        if(!possible)
            cout<<"-1"<<endl;
        else
        {
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]=='2')
                    cout<<"1";
                else
                    cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}