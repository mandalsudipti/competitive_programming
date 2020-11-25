#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , w ;
        cin>>n>>w;
        vector<long long int>arr(n);
        long long int low = (w/2) + (w%2) , high = w ;
        int idx = -1 ;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>=low && arr[i]<= high)
                idx = i ;
        }
        if(idx!=-1)
        {
            cout<<"1"<<endl;
            cout<<idx + 1 <<endl;
        }
        else
        {
            long long int cur_sum = 0 ;
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                if(arr[i]<low)
                {
                    cur_sum+=arr[i];
                    ans.push_back(i);
                }
                if(cur_sum>= low && cur_sum<=high)
                    break;
            }
            
            if(ans.size()==0 || cur_sum < low)
                cout<<"-1"<<endl;
            else
            {
                cout<<ans.size()<<endl;
                for(int i=0;i<ans.size();i++)
                    cout<<ans[i] + 1 <<" ";
                cout<<endl;
            }
        }
    }
    
    return 0;
}

