#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    
    int AB = 0 , BA = 0 , overlap = 0 ;
    int i = 0 ;
    
    while(i<S.length()-1)
    {
        if(i+2<S.length() && S[i]=='A' && S[i+1]=='B' && S[i+2]=='A')
        {
            overlap++;
            i+=3;
        }
        else if(i+2<S.length() && S[i]=='B' && S[i+1]=='A' && S[i+2]=='B')
        {
            overlap++;
            i+=3;
        }
        else if(S[i]=='A' && S[i+1]=='B')
        {
            AB++;
            i+=2;
        }
        else if(S[i]=='B' && S[i+1]=='A')
        {
            BA++;
            i+=2;
        }
        else
            i++;
    }
    
    if(overlap>=2 || (AB>=1 && BA>=1) || (AB>=1 && overlap>=1) ||(BA>=1 && overlap>=1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
        
    return 0;
}