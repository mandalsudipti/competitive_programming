#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int val;
    int positive_cnt=0 , negetive_cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(val>0)
            positive_cnt++;
        else if(val<0)
            negetive_cnt++;
    }
    if(positive_cnt>=(n/2)+(n%2!=0))
        cout<<"1";
    else if(negetive_cnt>=(n/2)+(n%2!=0))
        cout<<"-1";
    else
        cout<<"0";
    return 0;
}