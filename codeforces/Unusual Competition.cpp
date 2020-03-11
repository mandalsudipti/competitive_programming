#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    string S;
    cin>>S;
    int arr[N];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<N;i++)
    {
        if(i==0)
        {
            if(S[0]=='(')
                arr[0]=1;
            else
                arr[0]=-1;
        }
        else if(S[i]=='(')
            arr[i]=arr[i-1]+1;
        else
            arr[i]=arr[i-1]-1;
    }
    if(arr[N-1]!=0)
    {
        cout<<"-1";
        return 0;
    }
    int cnt=0 ;
    int i=0;
    while(i<N)
    {
        if(arr[i]<0)
        {
            int tmp=0;
            while(i<N)
            {
                tmp++;
                if(arr[i]==0)
                    break;
                i++;
                
            }
           // cout<<tmp<<endl;
            cnt+=tmp;
        }
        else
            i++;
    }
    cout<<cnt;
    return 0;
}