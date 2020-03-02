#include<bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    cin>>len;
    string S;
    cin>>S;
    int i ,j , cnt=0;
    
    for(i=24;i>=0;i--)
    {
        j=0;
        if(S.length()==1)
            break;
        while(j<S.length() && j>=0)
        {
            if(S[j]-'a'==i)
            {
                //cout<<S[j]<<endl;
                if(j==0 && S[j+1]-S[j]==1)
                {
                    cnt++;
                    S.erase(S.begin()+j+1);
                    //cout<<S<<endl;
                }
                else if(j==S.length()-1 && S[j-1]-S[j]==1)
                {
                    cnt++;
                    S.erase(S.begin()+j-1);
                    j--;
                    //cout<<S<<endl;
                }
                else if(S[j-1]-S[j]==1)
                {
                    cnt++;
                    S.erase(S.begin()+j-1);
                    j--;
                    //cout<<S<<endl;
                }
                else if(S[j+1]-S[j]==1)
                {
                    cnt++;
                    S.erase(S.begin()+j+1);
                    //cout<<S<<endl;
                }
                else
                    j++;
            }
            else
                j++;
        }
    }
    cout<<cnt;
    return 0;
}


