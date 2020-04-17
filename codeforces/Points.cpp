#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    long long int X[n],Y[n];
    for(int i=0;i<n;i++)
    {
        cin>>X[i];
        cin>>Y[i];
    }
    
    long long int repeat_square = n-1;
    long long int sum_x =0 , sum_y =0 ,sum =0 ;
    for(int i=0;i<n;i++)
    {
        sum_x+=(repeat_square*X[i]*X[i]);
        sum_y+=(repeat_square*Y[i]*Y[i]);
    }
    long long int total_x =0 ,total_y=0;
    for(int i=0;i<n;i++)
    {
        total_y+=Y[i];
        total_x+=X[i];
    }
    for(int i=0;i<n;i++)
    {
        sum_x -= (X[i]*(total_x-X[i]));
        sum_y -= (Y[i]*(total_y-Y[i]));
    }
    sum = sum_x + sum_y ;
    cout<<sum;
    return 0;
}
