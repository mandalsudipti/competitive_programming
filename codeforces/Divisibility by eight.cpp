#include<bits/stdc++.h>
using namespace std;

int two_digit(vector<vector<int>>&occur)
{
    for(int i=2;i<=12;i++)
    {
        int num = 8*i ;
        if(occur[num/10][0]!=-1 && occur[num/10][0]<occur[num%10][1])
            return num;
    }
    return 0;
}

int main()
{
    string S ;
    cin>>S;
    
    vector<vector<int>>occur(10,vector<int>(2,-1));
    for(int i=0;i<S.length();i++)
    {
        if(occur[S[i]-'0'][0]==-1)
            occur[S[i]-'0'][0] = occur[S[i]-'0'][1] = i ;
        else
            occur[S[i]-'0'][1] = i ;
    }
    
    if(occur[8][0]>-1||occur[0][0]>-1)
    {
        cout<<"YES"<<endl;
        if(occur[8][0]>-1)
            cout<<"8"<<endl;
        else
            cout<<"0"<<endl;
        return 0;
    }
    else if(two_digit(occur))
    {
        cout<<"YES"<<endl;
        cout<<two_digit(occur)<<endl;
        return 0 ;
    }
    else
    {
        for(int i=1;i<S.length();i++)
        {
            for(int j=1;j<10;j++)
            {
                if(occur[j][0]<i && occur[j][0]!=-1)
                {
                    int req = 8 - ((j*100 + (S[i]-'0')*10)%8) ;
                    if(occur[req][1]>i)
                    {
                        cout<<"YES"<<endl;
                        cout<<req + ((j*100)+(S[i]-'0')*10) ;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout<<"NO"<<endl;
    return 0;
}