#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S="";
    int n;
    cin>>n;
    int arr[n],i,left=0,right=n-1,cur;
    for(i=0;i<n;i++)
        cin>>arr[i];
    if(arr[left]<=arr[right])
    {
       S+='L';
       left++;
    }
    else
    {
        S+='R';
        right--;
    }
    cur=min(arr[0],arr[n-1]);
    while(left<=right)
    {
       if(arr[left]>cur && arr[right]>cur)
       {
           if(arr[left]<=arr[right])
           {
               S+='L';
               cur=arr[left];
               left++;
           }
           else
           {
               S+='R';
               cur=arr[right];
               right--;
           }
       }
       else if(arr[left]>cur)
       {
           S+='L';
           cur=arr[left];
           left++;
       }
       else if(arr[right]>cur)
       {
           S+='R';
           cur=arr[right];
           right--;
       }
       else
        break;
    }
    cout<<S.length()<<endl;
    cout<<S;
    return 0;
}

