#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int len , pipe_cost , pillar_cost ;
        cin>>len>>pipe_cost>>pillar_cost;
        string S;
        cin>>S;
        long long int arr[len+1];
        arr[0]=0;
        for(int i=0;i<S.length();i++)
        {
            arr[i+1]=S[i]-48;
            arr[i] = (arr[i]|(S[i]-48));
        }
        int left_one=-1 , right_one=-1 , cnt_one =0 , cnt_zero =0 ;
        for(int i=0;i<len+1;i++)
        {
            //cout<<arr[i]<<endl;
            if(arr[i]==1)
            {
                cnt_one++;
                if(left_one==-1)
                {
                    left_one=i;
                    right_one=i;
                }
                else
                    right_one=i;
            }
        }
        cnt_zero = (len+1)- cnt_one;
        int start=left_one;
        long long int total_cost = len*pipe_cost + (cnt_zero + 2*cnt_one)*pillar_cost + (cnt_one>0?2*pipe_cost:0) ;
        //cout<<total_cost<<endl;
        for(int i=left_one+1;i<=right_one;i++)
        {
            if(arr[i]==1)
            {
                if(i-start>=2)
                    total_cost+=min(2*pipe_cost , (i-start-1)*pillar_cost); 
                start=i;
            }
        }
        cout<<total_cost<<endl;
    }
    return 0;
}