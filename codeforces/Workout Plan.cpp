#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , initial_strength ;
    cin>>n>>initial_strength;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long int gain , price[n];
    cin>>gain;
    for(int i=0;i<n;i++)
        cin>>price[i];
    priority_queue<long long int> sorted_price ;
    long long int total_price = 0 ;
    for(int i=0;i<n;i++)
    {
        sorted_price.push(price[i]*(-1));
        if(arr[i]>initial_strength)
        {
            long long int required = (arr[i]-initial_strength)/gain + ((arr[i]-initial_strength)%gain!=0) ;
            if(required>sorted_price.size())
            {
                cout<<"-1";
                return 0;
            }
            initial_strength+=(required*gain);
            while(required>0)
            {
                long long int tmp = sorted_price.top()*(-1);
                total_price+=tmp;
                sorted_price.pop();
                required--;
            }
        }
    }
    cout<<total_price;
    return 0;
}
