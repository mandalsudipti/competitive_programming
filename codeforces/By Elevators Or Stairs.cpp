#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,overhead ;
    cin>>n>>overhead;
    int arr1[n] , arr2[n] , i;
    for(i=1;i<n;i++)
        cin>>arr1[i];
    for(i=1;i<n;i++)
        cin>>arr2[i];
    int stair[n] , elevator[n];
    stair[0]=elevator[0]=0;
    stair[1]=arr1[1];
    elevator[1]=arr2[1]+overhead;
    for(i=2;i<n;i++)
    {
        stair[i]= arr1[i]+ min(stair[i-1] , elevator[i-1]);
        elevator[i]=arr2[i]+ min(stair[i-1]+overhead , elevator[i-1]);
    }
    for(i=0;i<n;i++)
        cout<<min(stair[i],elevator[i])<<" ";
    return 0;
}
