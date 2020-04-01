#include<bits/stdc++.h>
using namespace std;

bool sort_by_second(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}

int main()
{
    int colored[1005];
    memset(colored,0,sizeof(colored));
    int color = 1;
    for(int i=2;i<=1000;i++)
    {
        if(!colored[i])
        {
            for(int j=i;j<=1000;j+=i)
            {
                if(colored[j]==0)
                    colored[j]=color;
            }
        }
        color++;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int len , val ,idx=1;
        cin>>len;
        vector<pair<int,int>>arr_color(len);
        for(int i=0;i<len;i++)
        {
            cin>>val;
            arr_color[i]=make_pair(i,colored[val]);
        }
        sort(arr_color.begin(),arr_color.end(),sort_by_second);
        int cur=arr_color[0].second;
        for(int i=0;i<arr_color.size();i++)
        {
            if(i==0)
                arr_color[i].second=idx;
            else if(arr_color[i].second==cur)
                arr_color[i].second=idx;
            else
            {
                cur=arr_color[i].second;
                arr_color[i].second= (++idx);
            }
                
        }
        cout<<arr_color[arr_color.size()-1].second<<endl;
        sort(arr_color.begin(),arr_color.end());
        for(int i=0;i<arr_color.size();i++)
            cout<<arr_color[i].second<<" ";
        cout<<endl;
    }
    return 0;
}