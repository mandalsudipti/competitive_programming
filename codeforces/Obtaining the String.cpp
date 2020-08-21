#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    string S , T ;
    cin>>S>>T;
    
    vector<int>freq(26,0);
    for(int i=0;i<S.length();i++)
        freq[S[i]-'a']++;
    for(int i=0;i<T.length();i++)
        freq[T[i]-'a']--;
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        {
            cout<<"-1";
            return 0;
        }
    }
    vector<int>move;
    for(int i=0;i<n;i++)
    {
        if(S[i]==T[i])
            continue;
        char find = T[i] ;
        for(int j=i+1;j<n;j++)
        {
            if(S[j]==find)
            {
                for(int k=j-1;k>=i;k--)
                {
                    swap(S[k],S[k+1]);
                    move.push_back(k);
                }
                break;
            }
        }
    }
    
    cout<<move.size()<<endl;
    for(int i=0;i<move.size();i++)
        cout<<move[i]+1<<" ";
    
    return 0;
}