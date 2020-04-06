#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    int opening_brace=-1 , first_colon=-1 , second_colon=-1 , closing_braces=-1 ;
    int cnt =0 ;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]=='[')
        {
            opening_brace=i;
            break;
        }
        else
            cnt++;
    }
    if(opening_brace==-1)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=opening_brace+1;i<S.length();i++)
    {
        if(S[i]==':')
        {
            first_colon=i;
            break;
        }
        else
            cnt++;
    }
    if(first_colon==-1)
    {
        cout<<"-1";
        return 0;
    }
    
    for(int i=S.length()-1;i>first_colon;i--)
    {
        if(S[i]==']')
        {
            closing_braces=i;
            break;
        }
        else
            cnt++;
    }
    if(closing_braces==-1)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=closing_braces-1;i>first_colon;i--)
    {
        if(S[i]==':')
        {
            second_colon=i;
            break;
        }
        else
            cnt++;
    }
    if(second_colon==-1)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=first_colon+1;i<second_colon;i++)
    {
        if(S[i]!='|')
            cnt++;
    }
    cout<<S.length()-cnt;
    
    return 0;
}
