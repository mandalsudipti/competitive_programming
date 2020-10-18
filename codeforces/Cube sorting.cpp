#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool possible = false ;
        for(int i=1;i<n;i++)
        {
            if(arr[i]<arr[i-1])
                continue;
            else
            {
                possible = true;
                break;
            }
        }
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}