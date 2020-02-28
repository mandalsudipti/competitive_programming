#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , day ;
        cin>>n>>day;
        int arr[n],i;
        for(i=0;i<n;i++)
            cin>>arr[i];
        int sum=arr[0];
        for(i=1;i<n;i++)
        {
            sum=sum + min(day/i,arr[i]);
            day= day - min((day/i),arr[i])*i;
            if(day==0)
                break;
        }
        cout<<sum<<endl;
    }
    return 0;
}