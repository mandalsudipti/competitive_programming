#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string S;
    cin>>S;
    int required=n/3 , cnt_zero=0 , cnt_one = 0 , cnt_two =0 ;
    for(int i=0;i<n;i++)
    {
        if(S[i]=='0')
            cnt_zero++;
        else if(S[i]=='1')
            cnt_one++;
        else
            cnt_two++;
    }
    int i=0;
    while(cnt_zero<required)
    {
        if(S[i]=='1' && cnt_one>required)
        {
            cnt_one--;
            S[i]='0';
            cnt_zero++;
        }
        else if(S[i]=='2' && cnt_two>required)
        {
            cnt_two--;
            S[i]='0';
            cnt_zero++;
        }
        i++;
    }
    i=0;
    while(cnt_one<required && i<n)
    {
        if(i<n && S[i]=='2' && cnt_two>required)
        {
            S[i]='1';
            cnt_one++ ;
            cnt_two--;
        }
        i++;
    }
    
    i=n-1;
    while(cnt_two<required)
    {
        if(S[i]=='0' && cnt_zero>required)
        {
            S[i]='2';
            cnt_two++;
            cnt_zero--;
        }
        else if(S[i]=='1' && cnt_one>required)
        {
            S[i]='2';
            cnt_one--;
            cnt_two++;
        }
        i--;
    }
    i=n-1;
    while(cnt_one<required && i>=0)
    {
        if(i>=0 && S[i]=='0' && cnt_zero>required)
        {
            S[i]='1';
            cnt_zero--;
            cnt_one++;
        }
        i--;
    }
    if(cnt_one<required)
        cout<<"1"<<endl;
    else if(cnt_zero<required)
        cout<<"0"<<endl;
    else if(cnt_two<required)
        cout<<"2"<<endl;
    cout<<S;
    return 0;
}
