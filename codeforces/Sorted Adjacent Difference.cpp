#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int ans[n];
        int left=0 , right=n-1 , idx=n-1;
        while(left<=right)
        {
            ans[idx--]=arr[right];
            if(right!=left)
                ans[idx--]=arr[left];
            left++;
            right--;
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
