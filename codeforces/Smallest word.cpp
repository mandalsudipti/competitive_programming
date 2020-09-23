#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    vector<int>prefix_swap(S.length(),0);
    int idx = 0 ;
    
    for(int i=0;i<S.length();i++)
    {
        if(i+1<S.length() && S[i+1]!=S[idx])
        {
            prefix_swap[i] = 1 ;
            idx = i+1;
        }
    }
    
    if(S[S.length()-1]=='a')
        prefix_swap[prefix_swap.size()-1] = 1;
        
    for(int i=0;i<prefix_swap.size();i++)
        cout<<prefix_swap[i]<<" ";
        
    return 0;
}