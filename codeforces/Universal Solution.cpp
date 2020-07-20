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
        map<char,int>freq;
        for(int i=0;i<S.length();i++)
            freq[S[i]]++;
        
        char ch = freq.begin()->first ;
        int f = freq.begin()->second ;
        for(auto itr=freq.begin();itr!=freq.end();++itr)
        {
            if(itr->second>f)
            {
                ch = itr->first ;
                f = itr->second;
            }
        }
        
        if(ch=='R')
            ch='P';
        else if(ch=='P')
            ch='S';
        else
            ch='R';
            
        for(int i=0;i<S.length();i++)
            cout<<ch;
        cout<<endl;
    }
    return 0;
}