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
        vector<long long int>arr(n);
        long long int maximum = 0 , sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            maximum = max(maximum , arr[i]);
            sum+=arr[i];
        }
        
        long long tmp =  ceil(double(sum)/(n-1));
        if(maximum*(n-1) - sum > 0)
            tmp = maximum ;
        long long res = tmp*(n-1) - sum ;
        cout<<res<<endl;
    }
    
    return 0;
}
