#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int val , maximum=0 , sum =0 ;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        sum+=val;
        maximum = max(maximum , val);
    }
    if(sum%2==1 || maximum>(sum-maximum))
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
