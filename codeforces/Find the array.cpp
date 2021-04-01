#include<bits/stdc++.h>
using namespace std;

bool is_valid(vector<int>& arr , vector<int>& ans)
{
    long long int arr_sum = 0 , diff_sum = 0 ;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        arr_sum+=arr[i];
        diff_sum+=(abs(arr[i] - ans[i]));
    }
    
    if(diff_sum * 2 <= arr_sum)
        return true;
    else
        return false;
}

int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        vector<int>ans1(n);
        vector<int>ans2(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            if(i%2 == 0)
            {
                ans1[i] = arr[i] ;
                ans2[i] = 1 ;
            }
            else
            {
                ans1[i] = 1 ;
                ans2[i] = arr[i];
            }
        }
        
        if(is_valid(arr,ans1))
            for(int i = 0 ; i < n ; i++)
                cout<<ans1[i]<<" ";
        else
            for(int i = 0 ; i < n ; i++)
                cout<<ans2[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}