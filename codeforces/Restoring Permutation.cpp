#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int arr[2*n+5],B[n+1],number[500],i,j;
        memset(number,0,sizeof(number));
        for(i=1;i<=n;i++)
        {
            cin>>B[i];
            arr[2*i-1]=B[i];
            number[B[i]]=1;
        }
        for(j=1;j<=n;j++)
        {
            for(i=arr[2*j-1]+1;i<500;i++)
            {
                if(number[i]==0)
                {
                    arr[2*j]=i;
                    number[i]=1;
                    break;
                }
            }
        }
        bool flag=true;
        for(i=1;i<=2*n;i++)
        {
            if(arr[i]>2*n)
            {
                cout<<"-1\n";
                flag=false;
                break;
            }
        }
        if(flag)
        {
            for(i=1;i<=2*n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
