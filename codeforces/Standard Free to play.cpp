#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int height , n ;
        cin>>height>>n;
        vector<int>arr(n);
        for(int i=n-1;i>=0;i--)
            cin>>arr[i];
        int idx=n-1,cnt=0;
        while(idx>0)
        {
            if(arr[idx-1]<height-1)
            {
                height=arr[idx-1]+1;
            }
            idx--;
            if(idx>=0)
            {
                height-=2;
                if(idx-1>=0 && arr[idx-1]==height)
                    idx--;
                else
                {
                    if(height>0)
                        cnt++;
                    if(idx-1>=0)
                        height=arr[idx-1]+1;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}







