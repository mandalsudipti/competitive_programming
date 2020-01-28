#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ppl , packet,i,val;
    cin>>ppl>>packet;
    int arr[100]={0};
    for(i=0;i<packet;i++)
    {
        cin>>val;
        arr[val]++;
    }
    if(ppl>packet)
    {
        cout<<"0";
        return 0;
    }
    sort(arr,arr+100);
    int day=1 , max_ppl=packet;
    while(true)
    {
        if(max_ppl<ppl)
            break;
        day++;
        max_ppl=0;
        for(i=0;i<100;i++)
        {
            max_ppl+=arr[i]/day;
        }
    }
    if(max_ppl<ppl)
        cout<<--day;
    else
        cout<<day;
    return 0;
}
