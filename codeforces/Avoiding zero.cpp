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
        int sum = 0 ;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        
        if(sum==0)
            cout<<"NO"<<endl;
        else 
        {
            sort(arr.begin(),arr.end(),greater<int>());
            if(sum>0)
            {
                cout<<"YES"<<endl;
                for(int i=0;i<arr.size();i++)
                    cout<<arr[i]<<" ";
                cout<<endl;
            }
            else
            {
                reverse(arr.begin(),arr.end());
                cout<<"YES"<<endl;
                for(int i=0;i<n;i++)
                    cout<<arr[i]<<" ";
                cout<<endl;
            }
            
        }
    }
    
    return 0;
}



