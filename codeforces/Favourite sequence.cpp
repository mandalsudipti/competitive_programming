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
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
            
        int left = 0 , right = n-1 , cnt = 0 ;
        bool flag = true ;
        
        while(cnt < n)
        {
            if(flag)
            {
                cout<<arr[left]<<" ";
                left++;
                flag = false;
            }
            else
            {
                cout<<arr[right]<<" ";
                right--;
                flag = true;
            }
            cnt++;
        }
        cout<<endl;
    }
    
    return 0;
}