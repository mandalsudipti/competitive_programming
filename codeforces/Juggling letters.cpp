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
        vector<long long int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            string S;
            cin>>S;
            for(int i=0;i<S.length();i++)
                freq[S[i]-'a']++;
        }
        
        bool possible = true ;
        for(int i=0;i<26;i++)
        {
            if(freq[i]%n!=0)
            {
                possible = false;
                break;
            }
        }
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}