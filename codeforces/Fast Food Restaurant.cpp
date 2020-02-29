#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int arr[3],i,cnt=0;
        for(i=0;i<3;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+3,greater<int>());
        for(i=0;i<3;i++)
        {
            if(arr[i]>0)
            {
                cnt++;
                arr[i]--;
            }
        }
        for(i=0;i<3;i++)
        {
            if(arr[i]>0 && arr[(i+1)%3]>0)
            {
                cnt++;
                arr[i]--;
                arr[(i+1)%3]--;
            }
        }
        if(arr[0]>0 && arr[1]>0 && arr[2]>0)
            cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}