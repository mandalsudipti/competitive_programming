#include<bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    cin>>K;
    while(K--)
    {
        bool flag=true;
        int N,cnt=0,max=0;
        cin>>N;
        int arr[N],i,j;
        for(i=0;i<N;i++)
            cin>>arr[i];
        sort(arr,arr+N);
        //for(i=N-1;i>=0;i--) cout<<arr[i];
        for(i=N-1;i>=0;i--)
        {
            //cout<<arr[i]<<endl;
            cnt=0;
            for(j=N-1;j>=0;j--)
            {
                if(arr[j]>=arr[i])
                    cnt++;
                else
                    break;
            }
            //cout<<arr[i]<<"->"<<cnt<<endl;
            if(arr[i]<cnt)
                cnt=arr[i];
            if(max<cnt)
                max=cnt;
        }
        cout<<max<<endl;
    }
}