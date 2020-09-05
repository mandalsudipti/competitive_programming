#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    vector<vector<int>>freq_so_far(S.length(),vector<int>(26,0));
    for(int i=0;i<S.length();i++)
    {
        freq_so_far[i][S[i]-'a']++;
        if(i>0)
        {
            for(int j=0;j<26;j++)
                freq_so_far[i][j]+=freq_so_far[i-1][j];
        }
    }
    
    int query;
    cin>>query;
    
    while(query--)
    {
        int left, right ;
        cin>>left>>right;
        left--;
        right--;
        
        if(right-left+1==1)
            cout<<"Yes"<<endl;
        else
        {
            if(S[left]!=S[right])
                cout<<"Yes"<<endl;
            else
            {
                int cnt = 0 ;
                for(int j=0;j<26;j++)
                {
                    char x = j + 'a' ;
                    if(freq_so_far[right-1][j] - freq_so_far[left][j]>0 && (S[right]!=x) )
                        cnt++;
                }
                if(cnt>=2)
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }
        }
    }
    
    return 0;
}
