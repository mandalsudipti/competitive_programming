#include<bits/stdc++.h>
using namespace std;

void find_room(long long int letter , long long int arr[],int len)
{
    long long int left=0 , right=len-1 ,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]>=letter && (mid==0 ||arr[mid-1]<letter))
        {
            cout<<mid+1<<" ";
            if(mid==0)
                cout<<letter<<endl;
            else
                cout<<letter-arr[mid-1]<<endl;
            return ;
        }
        else if(arr[mid]>letter)
            right=mid-1;
        else if(arr[mid]<letter)
            left=mid+1;
    }
}
int main()
{
    int n , m,i;
    cin>>n>>m;
    long long int room[n] , letter[m];
    for(i=0;i<n;i++)
    {
        cin>>room[i];
        if(i>0)
            room[i]+=room[i-1];
    }
    for(i=0;i<m;i++)
    {
        cin>>letter[i];
    }
    for(i=0;i<m;i++)
        find_room(letter[i],room,n);
    return 0;
}