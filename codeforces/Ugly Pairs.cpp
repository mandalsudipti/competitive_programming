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
        vector<int>freq(26,0);
        for(int i=0;i<S.length();i++)
            freq[S[i]-'a']++;
        string ans ;
        char pre ='0';
        bool possible = true;
        for(int i=0;i<26;i++)
        {
            if(pre=='0' && freq[i]>0)
            {
                while(freq[i]>0)
                {
                    char x = (i+'a');
                    ans+=x;
                    freq[i]--;
                }
                pre = (i+'a');
            }
            else if(freq[i]>0 && (i-(pre-'a'))!=1)
            {
                while(freq[i]>0)
                {
                    char x = (i+'a');
                    ans+=x;
                    freq[i]--;
                }
                pre=(i+'a');
            }
        }
        
        for(int i=25;i>=0;i--)
        {
            if(freq[i]>0 && abs((ans[0]-'a')-i)!=1)
            {
                while(freq[i]>0)
                {
                    char x = (i+'a');
                    ans = x+ans;
                    freq[i]--;
                }
            }
            else if(freq[i]>0 && abs(i-(ans.back()-'a'))!=1)
            {
                while(freq[i]>0)
                {
                    char x = i+'a';
                    ans+=x;
                    freq[i]--;
                }
            }
            else if(freq[i]>0)
            {
                cout<<"No answer"<<endl;
                possible = false;
                break;
            }
        }
        if(possible)
            cout<<ans<<endl;
    }
    return 0;
}



