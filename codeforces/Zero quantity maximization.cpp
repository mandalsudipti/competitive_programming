#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    long double A[n],B[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    map<long double,int>freq;
    int any_num = 0 ;
    for(int i=0;i<n;i++)
    {
        if(A[i]==0 && B[i]==0)
            any_num++;
        else if(A[i]==0 && B[i]!=0)
            continue;
        else if(A[i]!=0 && B[i]==0)
            freq[0]++;
        else
            freq[A[i]/B[i]]++;
    }
    int max_freq=0;
    for(auto itr=freq.begin();itr!=freq.end();++itr)
    {
        if(itr->second>max_freq)
            max_freq=itr->second;
    }
    cout<<max_freq+any_num<<endl;
    return 0;
}

