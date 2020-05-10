#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int len;
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++)
        {
            cin>>arr[i];
        }
        int start=arr[0];
        bool possible = true;
        for(int i=1;i<len;i++)
        {
            if(arr[i]<start)
                start=arr[i];
            else if(arr[i]>start)
            {
                if(arr[i]-start!=1)
                {
                    possible=false;
                    break;
                }
                else
                    start=arr[i];
            }
        }
        if(possible)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}