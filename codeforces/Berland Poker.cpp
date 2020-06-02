#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , m , k ;
        cin>>n>>m>>k;
        int card = (n/k) ;
        int other_joker = 0 ;
        if(m-card>0)
            other_joker = (m-card)/(k-1) + ((m-card)%(k-1)!=0) ;
        cout<< min(card,m)- other_joker<<endl;
    }
    return 0;
}