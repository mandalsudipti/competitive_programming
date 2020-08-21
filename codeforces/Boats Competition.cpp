#include<bits/stdc++.h>
using namespace std;

void get_freq(vector<int>weight , vector<int>&weight_sum,int total_weight)
{
    for(int i=1;i<weight.size();i++)
    {
        if(i>total_weight)
            break;
        int y = total_weight - i ;
        if(y>=weight.size()||y<1)
            continue;
        if(i!=y)
        {
            int l = min(weight[i],weight[y]);
            weight_sum[total_weight]+=l;
            weight[i]-=l;
            weight[y]-=l;
        }
        else
        {
            int x = weight[i]/2;
            weight_sum[total_weight]+=x;
            weight[i]-=x;
            weight[y]-=x;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>weight(n+1,0);
        int w;
        for(int i=0;i<n;i++)
        {
            cin>>w;
            weight[w]++;
        }
        vector<int>weight_sum(2*n+10,0);
        for(int i=2;i<weight_sum.size();i++)
        {
            get_freq(weight,weight_sum,i);
        }
            
        int max_freq = 0 ;
        for(int i=2;i<weight_sum.size();i++)
        {
            if(weight_sum[i]>max_freq)
            {
                max_freq = weight_sum[i];
            }
        }
        cout<<max_freq<<endl;
    }
    
    return 0;
}
