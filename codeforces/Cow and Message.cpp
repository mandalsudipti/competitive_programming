#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    long long int letter[26][26]={};
    long long int freq[26]={0};
    for(int i=0;i<S.length();i++)
        freq[S[i]-'a']++;
        
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            long long int cnt=0;
            for(int k=S.length()-1;k>=0;k--)
            {
               
                if(S[k]-'a'==j)
                    cnt++;
                if(S[k]-'a'==i)
                {
                    letter[i][j]+=cnt;
                    if(i==j)
                        letter[i][j]--;
                }
            }
        }
    }
    
    long long int maximum =1 ;
    
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(letter[i][j]>maximum)
                maximum = letter[i][j];
        }
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]>maximum)
            maximum=freq[i];
    }
    cout<<maximum;
    return 0;
}
