#include<bits/stdc++.h>
using namespace std;
long long int sq_root(long long int n)
{
    long long int left=0 ,right=n,mid , ans;
    if(n==0 || n==1)
        return n;
    while(right>=left)
    {
        mid=(left+right)/2;
        if(mid*mid==n)
            return mid;
        else if(mid*mid<n)
        {
             left=mid+1;
             ans=mid;
        }
        else if(mid*mid>n)
            right=mid-1;
    }
    return ans;
}
int main()
{
    long long int n;
    cin>>n;
    long long int row ,col;
    row=sq_root(n);
    if(row*row==n)
        col=row;
    else if(row*row<n)
        col=row+1;
    if(row*col<n)
        row+=1;
    cout<<row+col;
    return 0;
}