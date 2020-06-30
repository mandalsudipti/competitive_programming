#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        string S;
        cin>>S;
        vector<pair<int,int>>segment;
        int start=0,end=0;
        for(int i=1;i<n;i++)
        {
            if(S[i]==S[i-1])
                end++;
            else
            {
                segment.push_back(make_pair(start,end));
                start=end=i;
            }
        }
        segment.push_back(make_pair(start,n-1));
        string ans;
        if(S[0]=='1')
        {
            int x = segment.size()/2;
            if(x>=1)
                ans+='0';
            if(segment.size()%2)
                for(int i=segment.back().first;i<=segment.back().second;i++)
                    ans+='1';
        }
        else
        {
            for(int i=segment[0].first;i<=segment[0].second;i++)
                ans+='0';
            int x = (segment.size()-1)/2;
            if(x>=1)
                ans+='0';
            if((segment.size()-1)%2)
                for(int i=segment.back().first;i<=segment.back().second;i++)
                    ans+='1';
        }
        cout<<ans<<endl;
    }
    return 0;
}