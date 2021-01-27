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
        vector<long long int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        set<int>distance ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
                distance.insert(arr[j] - arr[i]);
        }
        
        cout<<distance.size()<<endl;
    }
    
    return 0;
}