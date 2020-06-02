#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int A[n],B[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    if(n==1)
    {
        cout<<max(A[0],B[0]);
        return 0;
    }
    else if(n==2)
    {
        cout<<max(A[0]+B[1],B[0]+A[1]);
        return 0;
    }
    long long int arr1[n] , arr2[n] ;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            arr1[i]=A[i];
            arr2[i]=B[i];
        }
        else
        {
            arr1[i]=B[i];
            arr2[i]=A[i];
        }
    }
    for(int i=2;i<n;i++)
    {
        arr1[i-1] = max(arr1[i-1]+arr1[i-2],arr2[i-2]);
        arr2[i-1] = max(arr2[i-1]+arr2[i-2],arr1[i-2]);
    }
    cout<<max(arr1[n-1]+arr1[n-2],arr2[n-1]+arr2[n-2]);
    return 0;
}
