#include<bits/stdc++.h>
using namespace std;

void change(vector<int>&arr , int idx , int num)
{
    int start = idx ;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=0)
        {
            start = i ;
            break;
        }
    }
    
    for(int i=start;i<=idx;i++)
    {
        if(arr[i]<arr[i-1])
            break;
        else
        {
            int tmp = arr[i] - arr[i-1] ;
            tmp = min(tmp,num);
            arr[i]-=tmp;
            num = tmp ;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        int num = arr[0];
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=num)
            {
                num = arr[i];
                arr[i] = 0 ;
            }
            else
                break;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i+1]-arr[i]<0)
            {
                change(arr,i,num);
                break;
            }
        }
        
        bool flag = true ;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}