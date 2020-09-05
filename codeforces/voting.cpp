#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    string S;
    cin>>S;
    
    set<int>D;
    set<int>R;
    for(int i=0;i<n;i++)
        S[i]=='D' ? D.insert(i) : R.insert(i) ;
        
    int idx = 0 ;
    while(D.size()>0 && R.size()>0)
    {
        if(S[idx]=='D')
        {
            auto itr = R.lower_bound(idx) ;
            if(itr!=R.end())
            {
                S[(*itr)]='*';
                R.erase(itr);
            }
            else
            {
                S[*(R.begin())]='*';
                R.erase(R.begin());
            }
        }
        else if(S[idx]=='R')
        {
            auto itr = D.lower_bound(idx);
            if(itr!=D.end())
            {
                S[(*itr)]='*';
                D.erase(itr);
            }
            else
            {
                S[(*D.begin())]='*';
                D.erase(D.begin());
            }
        }
        idx = (idx+1)%n;
    }
    
    if(D.size()>=1)
        cout<<"D"<<endl;
    else
        cout<<"R"<<endl;
        
    return 0;
}
