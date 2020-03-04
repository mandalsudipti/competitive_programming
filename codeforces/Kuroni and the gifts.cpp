#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int A[n] , B[n] , i;
        for(i=0;i<n;i++)
            cin>>A[i];
        for(i=0;i<n;i++)
            cin>>B[i];
        sort(A,A+n);
        sort(B,B+n);
        for(i=0;i<n;i++)
            cout<<A[i]<<" ";
        cout<<endl;
        for(i=0;i<n;i++)
            cout<<B[i]<<" ";
        cout<<endl;
    }
    return 0;
}