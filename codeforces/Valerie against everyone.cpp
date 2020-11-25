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
            
        bool flag = false;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                flag = true ;
                break;
            }
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}