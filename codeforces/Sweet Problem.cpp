#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int arr[3],i,day;
        for(int i=0;i<3;i++)
            cin>>arr[i];
        sort(arr,arr+3);
        if(arr[2]>=arr[0]+arr[1])
            cout<<arr[0]+arr[1]<<endl;
        else //arr[2]<arr[0]+arr[1]
        {
            day=arr[2]-arr[1]; // make arr[2]=arr[1] while eat from arr[2] and arr[0]
            arr[2]=arr[2]-day;
            arr[0]=arr[0]-day;
            //make arr[0] and arr[1] equal
            if(arr[0]!=arr[1])
            {
                day+=arr[1]-arr[0];
                arr[2]=arr[2]-(arr[1]-arr[0]);
                arr[1]=arr[1]-(arr[1]-arr[0]);
            }
            if(arr[0]==1)
                day+=1;
            else if(arr[0]>=2)
                day+=(arr[0]+arr[1]+arr[2])/2;
            cout<<day<<endl;
        }
    }
}
