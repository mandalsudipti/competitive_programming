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
        int prefix = 0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==1)
                prefix++;
            else
                break;
        }
        if(prefix%2==0)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }
    return 0;
}