#include<bits/stdc++.h>
using namespace std;

bool bit_set(int num , int pos)
{
    return ((num & (1<<pos))!=0);
}

void swap (int arr[],int i , int j)
{
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}

int main()
{
    int n;
    cin>>n;
    int arr[n],i,j;
    for(i=0;i<n;i++)
        cin>>arr[i];
    vector<int> bit_freq(32,0);
    for(i=0;i<n;i++)
    {
        for(j=0;j<32;j++)
        {
            if(bit_set(arr[i],j))
                bit_freq[j]++;
        }
    }
    int max_or =0 ;
    for(i=0;i<n;i++)
    {
        int maximum=0;
        for(j=0;j<32;j++)
        {
            if(bit_set(arr[i],j) && bit_freq[j]==1)
                maximum|=(1<<j);
        }
        if(maximum>max_or)
        {
            swap(arr,i,0);
            max_or = maximum;
        }
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
