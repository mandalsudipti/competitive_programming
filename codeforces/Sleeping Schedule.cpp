#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , h , l , r;
    cin>>n>>h>>l>>r;
    
    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    long long int mat[n+1][h];
    memset(mat,0,sizeof(mat));
    for(int start=l;start<=r;start++)
        mat[n][start]=1;
    for(int i=n-1;i>=1;i--)
    {
        for(int start=0;start<h;start++)
        {
            long long int nxt_a = (start+arr[i+1])%h;
            long long int nxt_b = (start+arr[i+1]-1+h)%h;
            if(mat[i+1][nxt_a]>mat[i+1][nxt_b])
                mat[i][start]= mat[i+1][nxt_a]+ (l<=start && start<=r);
            else
                mat[i][start]=mat[i+1][nxt_b]+(l<=start && start<=r);
        }
    }
    cout<<max(mat[1][arr[1]],mat[1][arr[1]-1]);
    return 0;
}
