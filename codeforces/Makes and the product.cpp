#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    map<int,long long int>freq;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    
    auto itr = freq.begin() ;
    long long int a = itr->second ;
    if(a>=3)
    {
        cout<<(a*(a-1)*(a-2))/6;
        return 0;
    }
    (itr)++;
    long long int b = itr->second ;
    if(a+b>=3)
    {
        if(a==1)
            cout<<(b*(b-1))/2;
        else
            cout<<b;
        return 0;
    }
    
    (itr)++;
    long long int c = itr->second;
    cout<<c;
    
    return 0;
}
