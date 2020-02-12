#include<bits/stdc++.h>
using namespace std;
bool match_all(int X , int m , vector<int>A , vector<int>B)
{
    for(int i=0;i<A.size();i++)
        A[i]=(A[i]+X)%m ;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=B[i])
            return false;
    }
    return true ;
}

int main()
{
    int n , m;
    cin>>n>>m;
    vector<int>A(n);
    vector<int>B(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        A[i]=A[i]%m ;
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    sort(B.begin(),B.end());
    int smallest = 1000000000 ;
    for(int i=0;i<n;i++)
    {
        int X = (B[i]-A[0]+m)%m;
        if ( match_all(X, m, A ,B))
            smallest = min(smallest , X);
    }
    cout<<smallest<<endl;
    return 0;
}