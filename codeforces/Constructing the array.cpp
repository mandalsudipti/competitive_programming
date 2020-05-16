#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    vector<priority_queue<int>>len(n+1);
    vector<int>arr(n+1,0);
    int idx = (n-1+1)%2==0?(1+n-1)/2:(1+n)/2;
    arr[idx]=1;
    if(idx-1>=1)
        len[idx-1].push(-1);
    if(idx+1<=n && n-idx>=1)
        len[n-idx].push((idx+1)*(-1));
    int max_len = n/2;
    for(int op=2;op<=n;op++)
    {
        for(int i=max_len;i>=1;i--)
        {
            if(len[i].size()>0)
            {
                //cout<<i<<" "<<len[i].top()<<endl;
                int x = (len[i].top())*(-1);
                x = i%2==0?(x+(x+i-1)-1)/2:(x+(x+i-1))/2;
                arr[x]=op;
                len[i].pop();
                int left , right , l_idx , r_idx ;
                if(i%2==0)
                {
                    left = i/2 -1 ;
                    right = i/2;
                }
                else
                {
                    left=i/2;
                    right=i/2;
                }
                r_idx=x+1;
                l_idx = x - left ;
                if(l_idx>=1 && l_idx<=n)
                    len[left].push(l_idx*(-1));
                if(r_idx>=1 && r_idx<=n)
                    len[right].push(r_idx*(-1));
                for(int l=max_len;l>=max(left,right);l--)
                {
                    if(len[l].size()!=0)
                    {
                        max_len=l;
                        break;
                    }
                }
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
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
