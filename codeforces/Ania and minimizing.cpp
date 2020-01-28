#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int N,K,i,cnt=0;
    cin>>N>>K;
    string arr;
    cin>>arr;
    //cout<<arr;
    if(N==1 && K>0)
        cout<<"0";
    else if(N==1 && K==0)
        cout<<arr;
    else
    {
       if(arr[0]>'1' && K>0)
       {
           arr[0]='1';
           cnt++;
       }
       for(i=1;i<N;i++)
       {
           if(cnt==K)
                break;
           if(arr[i]!='0')
           {
               cnt++;
               arr[i]='0';
           }
       }
       //for(i=0;i<N;i++)
        //cout<<arr[i];
       cout<<arr;
    }
    return 0;
}
