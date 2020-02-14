#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n],i,minimum=-1 , maximum=-1;
        
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]!=-1)
            {
                if(i-1>=0 && arr[i-1]==-1)
                {
                    if(minimum==-1 && maximum==-1)
                    {
                        minimum=arr[i];
                        maximum=arr[i];
                    }
                    else if(arr[i]<minimum)
                        minimum=arr[i];
                    else if(arr[i]>maximum)
                        maximum=arr[i];
                }
                else if (i+1<n && arr[i+1]==-1)
                {
                    if(minimum==-1 && maximum==-1)
                    {
                        minimum=arr[i];
                        maximum=arr[i];
                    }
                    else if(arr[i]<minimum)
                        minimum=arr[i];
                    else if(arr[i]>maximum)
                        maximum=arr[i];                    
                }
            }
        }
        //cout<<"minimum"<<minimum<<" maximum"<<maximum<<endl;
        int avg = (max ( 0,(minimum+maximum)/2));
        int max_diff=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==-1)
                arr[i]=avg;
        }
        for(i=1;i<n;i++)
        {
            max_diff = max ( max_diff , abs(arr[i]-arr[i-1]));
        }

        cout<<max_diff<<" "<<avg<<endl;
    }
    return 0;
}


