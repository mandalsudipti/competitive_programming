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
        long long int sum=0 , pre_max , cur ;
        for(int i=0;i<n;i++)
        {
            cin>>cur;
            if(i==0)
            {
                pre_max=cur;
                continue;
            }
            if(pre_max*cur>0)
                pre_max=max(pre_max,cur);
            else
            {
                sum+=pre_max;
                pre_max=cur;
            }
        }
        sum+=pre_max;
        cout<<sum<<endl;
    }
    return 0;
}
