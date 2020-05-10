#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int k;
        cin>>k;
        int days[8];
        for(int i=1;i<=7;i++)
            cin>>days[i];
        vector<long long int>gap;
        int start=0;
        for(int i=1;i<=7;i++)
        {
            if(days[i]==1)
            {
                if(start==0)
                    start=i;
                else
                {
                    gap.push_back(i-start-1);
                    start=i;
                }
            }
        }
        //cout<<start<<endl;
        gap.push_back(7-start);
        for(int i=1;i<=7;i++)
        {
            if(days[i]==0)
                gap[gap.size()-1]++;
            else
                break;
        }
        
        //for(int i=0;i<gap.size();i++)
            //cout<<gap[i]<<endl;
        long long int  day_required=0 , tmp ,sum=0 , ans = INT_MAX;
        for(int i=0;i<gap.size();i++)
            sum+=gap[i];
        
        for(int i=0;i<gap.size();i++)
        {
            day_required=0;
            tmp=k-1;
            for(int j=i;j<gap.size();j++)
            {
                if(tmp==0)
                    break;
                day_required+=gap[j];
                tmp--;
            }
            long long int full_cycle = tmp / gap.size();
            day_required += (full_cycle*sum);
            tmp = tmp - full_cycle*gap.size();
            for(int j=0;j<tmp;j++)
                day_required+=gap[j];
            ans = min(ans,day_required);
        }
        cout<<ans+k<<endl;
    }
    return 0;
}