#include<bits/stdc++.h>
using namespace std;

int main()
{
    int query , x;
    cin>>query>>x;
    map <long long , int> is_present ;
    map <long long , int > freq_rem ;
    long long int mex=0;
    while(query--)
    {
        long long current ;
        cin>>current;
        current=current%x ;
        is_present[x*freq_rem[current]+current]=true;
        freq_rem[current]++;
        while(is_present[mex])
        {
            mex++;
        }
        cout<<mex<<"\n";
    }
    return 0;
}