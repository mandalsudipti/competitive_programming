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
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i+=2)
            cout<<arr[i+1]<<" "<<(-1)*arr[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}