#include<bits/stdc++.h>
using namespace std;

int main()
{
    const int num[]={4,8,15,16,23,42};
    map<int,int> freq;
    int i ,j, n;
    for(i=0;i<6;i++)
    {
        freq[num[i]]=0;
    }
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
    {
        if(arr[i]==4)
            freq[4]++;
        else
        {
            int val=arr[i];
            for(j=1;j<6;j++)
            {
                if(val==num[j])
                    break;
            }
            if(freq[num[j-1]]>freq[val])
                freq[val]++;
        }
    }
    cout<<n-(freq[42]*6);
    return 0;
}


