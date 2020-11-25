#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        string S;
        cin>>n>>S;
        bool clockwise = false , anticlocwise = false ;
        set<int>valid ;
        
        for(int i=0;i<n;i++)
        {
            if(S[i]=='-')
            {
                valid.insert(i);
                valid.insert((i+1)%n);
            }
            else
                S[i]=='>' ? clockwise = true : anticlocwise = true ;
        }
        
        if(clockwise && anticlocwise)
            cout<<valid.size()<<endl;
        else
            cout<<n<<endl;
    }
    
    return 0;
}