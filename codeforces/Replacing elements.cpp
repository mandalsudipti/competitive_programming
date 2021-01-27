#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n , d ;
        cin>>n>>d ;
        vector<int>arr(n);
        
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        sort(arr.begin() , arr.end());
        
        if(arr.back() <= d || (arr[0] + arr[1]) <= d)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}