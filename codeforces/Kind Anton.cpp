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
        long long int A[n],B[n];
        int left_one=1000005, left_minus_one=1000005 ;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]==1 && left_one==1000005)
                left_one=i;
            if(A[i]==-1 && left_minus_one==1000005)
                left_minus_one=i;
        }
        for(int i=0;i<n;i++)
            cin>>B[i];
        bool possible = true;
        for(int i=0;i<n;i++)
        {
            if(A[i]>B[i] && left_minus_one>=i)
            {
                cout<<"NO"<<endl;
                possible=false;
                break;
            }
            if(A[i]<B[i] && left_one>=i)
            {
                cout<<"NO"<<endl;
                possible=false;
                break;
            }
        }
        if(possible)
            cout<<"YES\n";
    }
    return 0;
}