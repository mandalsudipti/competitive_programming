#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    vector<int>even_pos;
    vector<int>odd_pos;
    for(int i=1;i<=2*n;i++)
    {
        int val;
        cin>>val;
        val%2==0?even_pos.push_back(i):odd_pos.push_back(i);
    }
    int pair=0;
    for(int i=0;i<even_pos.size();i+=2)
    {
        if(i+1<even_pos.size())
        {
            cout<<even_pos[i]<<" "<<even_pos[i+1]<<endl;
            pair++;
            if(pair>=n-1)
                break;
        }
    }
    for(int i=0;i<odd_pos.size();i+=2)
    {
        if(pair>=n-1)
            break;
        if(i+1<odd_pos.size())
        {
            cout<<odd_pos[i]<<" "<<odd_pos[i+1]<<endl;
            pair++;
        }
    }
    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}