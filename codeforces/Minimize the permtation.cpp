#include<bits/stdc++.h>
using namespace std;

void swap(int *a , int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int arr[n+1] ;
        vector<bool>is_op(n+1,false);
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(arr[j]>arr[j+1] && is_op[j]==false)
                {
                    swap(&arr[j],&arr[j+1]);
                    is_op[j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}

