#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        long long int sum = 0 ;
        vector<int>arr(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%n != 0)
            cout<<"-1"<<endl;
        else
        {
            long long int avg = sum / n ;
            int cnt = 0 ;
            for(int i = 0 ; i < n ; i++)
            {
                if(arr[i] > avg)
                    cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0 ;
}