#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int len , i,mid;
        cin>>len;
        int arr[len];
        for(i=0;i<len;i++)
            cin>>arr[i];
        i=0;
        while(i<len)
        {
            if(arr[i]>=i)
                i++;
            else
                break;
        }
        if(i==0)
        {
            cout<<"No\n";
        }
        else
        {
            mid=i-1;
            if(mid==len-1)
                cout<<"Yes\n";
            else
            {
                if(len-i<=arr[mid])
                {
                    bool flag=true;
                    for(i=mid+1;i<len;i++)
                    {
                        if(arr[i]<len-(i+1))
                        {
                            cout<<"No\n";
                            flag=false;
                            break;
                        }
                    }
                    if(flag)
                        cout<<"Yes\n";
                }
                else
                    cout<<"No\n";
            }
        }
    }
    return 0;
}