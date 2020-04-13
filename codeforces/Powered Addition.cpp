#include<bits/stdc++.h>
using namespace std;
int  MSB(long long int num)
{
    int cnt=-1;
    while(num!=0)
    {
        cnt++;
        num=num>>1;
    }
    return cnt;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long int maximum = arr[0] ; 
        int add_power=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>maximum)
                maximum=arr[i];
            else
            {
                add_power = max(add_power,MSB(maximum-arr[i])+1);
            }
        }
        cout<<add_power<<endl;
    }
    return 0;
}
