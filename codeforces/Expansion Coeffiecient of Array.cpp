#include<bits/stdc++.h>
using namespace std;

int main()
{
    int len,i;
    cin>>len;
    int arr[len+1],min_ratio=1000000000;
    for(i=1;i<=len;i++)
        cin>>arr[i];
    for(i=1;i<=len;i++)
    {
        min_ratio = min(min_ratio,arr[i]/max(i-1,len-i));
    }
    cout<<min_ratio;
    return 0;
}