#include<bits/stdc++.h>
using namespace std;

int main()
{
    int segment , lim ;
    cin>>segment>>lim;
    vector<int>possible(lim+1,1);
    while(segment--)
    {
        int l ,  r ;
        cin>>l>>r;
        for(int i=l;i<=r;i++)
            possible[i]=0;
    }
    int cnt = 0 ;
    for(int i=1;i<=lim;i++)
        if(possible[i]==1)
            cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=lim;i++)
        if(possible[i])
            cout<<i<<" ";
            
    return 0;
}