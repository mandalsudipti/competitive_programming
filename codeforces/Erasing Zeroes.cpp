#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S ;
        int left=-1 , right=-1 , cnt=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='1' && left==-1 && right==-1)
            {
                left=i;
                right=i;
            }
            else if (S[i]=='1')
                right=i;
        }
        if(left==-1)
            cout<<"0\n";
        else
        {
            for(int i=left;i<=right;i++)
            {
                if(S[i]=='0')
                    cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}