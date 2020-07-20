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
        vector<int>arr(n);
        vector<int>left_min(n,0);
        vector<int>right_min(n,0);
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i==0)
                left_min[i] = 0;
            else
                arr[left_min[i-1]] < arr[i-1] ? left_min[i] = left_min[i-1] : left_min[i] = i-1 ;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                right_min[i] = i ;
            else
                arr[right_min[i+1]] < arr[i+1] ? right_min[i] = right_min[i+1] : right_min[i] = i+1 ;
        }
            
        bool possible = false;
        for(int i=1;i<n-1;i++)
        {
            //cout<<arr[i]<<" "<<arr[left_min[i]]<<" "<<arr[right_min[i]]<<endl;
            if(arr[i]>arr[left_min[i]] && arr[i]>arr[right_min[i]])
            {
                possible = true;
                cout<<"YES"<<endl;
                cout<<left_min[i]+1<<" "<<i+1<<" "<<right_min[i]+1<<endl;
                break;
            }
        }
        
        if(!possible)
            cout<<"NO"<<endl;
    }
    return 0;
}
