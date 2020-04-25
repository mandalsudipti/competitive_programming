#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x;
        cin>>n;
        x=n/2;
        if(x%2==1)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            long long int even_sum=0,odd_sum=0;
            vector<int>arr(n);
            int y=2;
            for(int i=0;i<n/2;i++)
            {
                arr[i]=y;
                y+=2;
                even_sum+=arr[i];
            }
            int x=1;
            for(int i=n/2;i+1<n;i++)
            {
                arr[i]=x;
                x+=2;
                odd_sum+=arr[i];
            }
            arr[n-1]=even_sum-odd_sum;
            for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}