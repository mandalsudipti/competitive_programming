#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        long long int arr[n] , sum=0 , xor_val=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            xor_val=xor_val^arr[i];
        }
        cout<<"2"<<endl;
        cout<<xor_val<<" "<<sum+xor_val<<endl;
    }
    return 0;
}