#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        vector<int>arr(n);
        vector<pair<int,int>>last_occur(x,make_pair(-1,-1));
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            i==0? arr[i]=arr[i]%x:arr[i]=(arr[i]+arr[i-1])%x;
            last_occur[arr[i]].first=i;
            last_occur[arr[i]].second=arr[i];
        }
        sort(last_occur.begin(),last_occur.end());
        int substract = 0 , len = 0;
        for(int i=0;i<n;i++)
        {
            if(i>0)
                substract = arr[i-1];
            for(int j=x-1;j>=0;j--)
            {
                if(last_occur[j].first<i)
                    break;
                if((last_occur[j].second- substract+x)%x!=0)
                {
                    len = max(len , (last_occur[j].first-i+1));
                    break;
                }
            }
        }
        if(len==0)
            cout<<"-1"<<endl;
        else
            cout<<len<<endl;
    }
    return 0;
}
