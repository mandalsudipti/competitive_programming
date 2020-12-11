#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    while(n--)
    {
        string S ;
        cin>>S;
        sort(S.begin() , S.end()) ;
        bool flag = true ;
        for(int i=0;i<S.length()-1;i++)
        {
            if(S[i+1] - S[i] != 1)
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}