#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    string S , T ;
    cin>>S>>T;
    int cost=0;
    for(int i=0;i<S.length();i++)
    {
        if(i+1<S.length() && S[i]!=S[i+1] && S[i]!=T[i] && S[i+1]!=T[i+1])
        {
            S[i+1]=T[i+1];
            cost++;
        }
        
        else if(S[i]!=T[i])
            cost++;   
    }
    cout<<cost;
    return 0;
}