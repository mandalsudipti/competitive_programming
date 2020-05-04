#include<bits/stdc++.h>
using namespace std;

int main()
{
    int spaceship , base ;
    cin>>spaceship>>base;
    long long int power[spaceship];
    vector<vector<long long int>>arr(base,vector<long long int>(2,0));
    
    for(int i=0;i<spaceship;i++)
        cin>>power[i];
        
    for(int i=0;i<base;i++)
        cin>>arr[i][0]>>arr[i][1];
        
    sort(arr.begin(),arr.end());
    vector<int>copy_arr(base);
    copy_arr[0]=arr[0][0];
    for(int i=1;i<base;i++)
    {
        copy_arr[i]=arr[i][0];
        arr[i][1]+=arr[i-1][1];
    }
    
    for(int i=0;i<spaceship;i++)
    {
        long long int x = power[i];
        int j = upper_bound(copy_arr.begin(),copy_arr.end(),x) - copy_arr.begin() ;
        if(j==0)
            cout<<"0"<<" ";
        else
            cout<<arr[j-1][1]<<" ";
    }
    return 0;
}