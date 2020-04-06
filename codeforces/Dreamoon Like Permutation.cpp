#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    int arr[n+1],i,left_missing=1, right_missing ,cnt=0;
    vector<int>left(n+2,0);
    vector<int>right(n+2,0);
    vector<pair<int,int>>ans;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        right[arr[i]]++;
    }
    for(i=1;i<=n+1;i++)
    {
        if(right[i]==0)
        {
            right_missing=i;
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            continue ;
        }
        else
        {
            left[arr[i]]++;
            right[arr[i]]--;
            if(right[arr[i]]<=0 && arr[i]<right_missing)
                right_missing=arr[i];
            if(arr[i]==left_missing)
            {
                for(int j=left_missing+1;j<=n+1;j++)
                {
                    if(left[j]==0)
                    {
                        left_missing=j;
                        break;
                    }
                }
            }
            if(left_missing==i+1 && right_missing==(n-i)+1)
            {
                cnt++;
                ans.push_back(make_pair(i,n-i));
            }
        }
    }
    cout<<cnt<<endl;
    for(i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
