#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , b , a ;
    cin>>n>>b>>a;
    int maximum = a , cnt=0;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(a==0 && b==0)
            break;
        else
            cnt++;
        if(i==0)
        {
            a--;
            continue;
        }
        if(arr[i]==1)
        {
            if(a==maximum || b==0)
                a--;
            else
            {
                b--;
                a=min(maximum,a+1);
            }
        }
        else if(arr[i]==0)
        {
            if(a!=0)
                a--;
            else
                b--;
        }
    }
    cout<<cnt;
    return 0;
}
