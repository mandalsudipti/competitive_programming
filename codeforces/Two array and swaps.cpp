#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        int A[n],B[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<n;i++)
            cin>>B[i];
        sort(A,A+n);
        sort(B,B+n,greater<int>());
        int sum =0 ;
        
        int new_arr[2*k];
        for(int i=0;i<k;i++)
            new_arr[i]=B[i];
        for(int i=k;i<2*k;i++)
            new_arr[i]=A[i-k];
        sort(new_arr,new_arr+(2*k),greater<int>());
        for(int i=0;i<k;i++)
            sum+=new_arr[i];
        for(int i=k;i<n;i++)
            sum+=A[i];
        cout<<sum<<endl;
    }
    return 0;
}
