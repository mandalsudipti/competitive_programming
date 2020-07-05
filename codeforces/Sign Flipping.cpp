#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i%2==0 && arr[i]>0)
                arr[i]=arr[i]*(-1);
            if(i%2==1 && arr[i]<0)
                arr[i]=arr[i]*(-1);
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}
