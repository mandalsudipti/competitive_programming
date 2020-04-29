#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S , T ;
    cin>>S>>T;
    vector<vector<int>>loc(26);
    for(int i=0;i<S.length();i++)
    {
        loc[S[i]-97].push_back(i);
    }
    vector<vector<int>>range(T.length(),vector<int>(2,0));
    range[0][0]= loc[T[0]-97][0];
    range[T.length()-1][1] = loc[T[T.length()-1]-97].back();
    
    for(int i=1;i<T.length();i++)
    {
        int x = upper_bound(loc[T[i]-97].begin(),loc[T[i]-97].end(),range[i-1][0]) - loc[T[i]-97].begin() ;
        range[i][0] = loc[T[i]-97][x] ;
    }
    for(int i=T.length()-2;i>=0;i--)
    {
        int x = lower_bound(loc[T[i]-97].begin(),loc[T[i]-97].end(),range[i+1][1]) - loc[T[i]-97].begin() ;
        range[i][1] = loc[T[i]-97][x-1] ;
    }
    
    /*for(int i=0;i<range.size();i++)
    {
        cout<<range[i][0]<<" "<<range[i][1]<<endl;
    }*/
    
    vector<int>substring_len ;
    substring_len.push_back(range[0][1]);
    substring_len.push_back(S.length() - range[range.size()-1][0] -1);
    for(int i=1;i<range.size();i++)
    {
        int x = range[i][1] - range[i-1][0] - 1;
        substring_len.push_back(x);
    }
    int max_len = substring_len[0];
    for(int i=1;i<substring_len.size();i++)
    {
        max_len = max( max_len , substring_len[i]);
    }
    cout<<max_len<<endl;
    return 0;
}