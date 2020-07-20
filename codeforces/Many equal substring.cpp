#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k ;
    cin>>n>>k;
    string S,tmp;
    cin>>S;
    tmp = S ;
    int max_prefix = 0 , idx ;
    
    for(int i=1;i<n;i++)
    {
        idx = 0 ;
        bool matched =  true ;
        for(int j=i;j<n;j++)
            if(S[j]!=tmp[idx++])
                matched = false;
        if(matched)
        {
            max_prefix = (n-i) ;
            break;
        }
    }
    string append ;
    for(int i = max_prefix;i<n;i++)
        append+=S[i];
        
    for(int i=1;i<k;i++)
        S+=append;
        
    cout<<S;
    
    return 0;
}