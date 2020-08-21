#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    bool finite = true ;
    long long int cnt = 0 ;
    for(int i=1;i<n;i++)
    {
        if(arr[i]+arr[i-1]==5)
        {
            finite = false;
            break;
        }
        cnt+=(arr[i]+arr[i-1]);
    }
    for(int i=0;i+2<n;i++)
    {
        if(arr[i]==3 && arr[i+1]==1 && arr[i+2]==2)
            cnt--;
    }
    if(finite)
    {
        cout<<"Finite"<<endl;
        cout<<cnt;
    }
    else
        cout<<"Infinite";
        
    return 0;
}
