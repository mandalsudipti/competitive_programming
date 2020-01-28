#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ,N,arr[100],i;
    bool flag;
    cin>>T;
    while(T--)
    {
        flag=true;
        cin>>N;
        for(i=0;i<N;i++)
            cin>>arr[i];
        sort(arr,arr+N);
        for(i=0;i<N-1;i++)
        {
            if(arr[i+1]-arr[i]==1)
            {
                cout<<"2"<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
        cout<<"1"<<endl;
    }
    return 0;
}

