#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long int get_weight(vector<ll>&red , vector<ll>&green , vector<ll>&blue)
{
    ll ans = -1;
    for(int i=0;i<red.size();i++)
    {
        ll g[2]={-1,-1} , b[2]={-1,-1} ;
        int idx = lower_bound(green.begin(),green.end(),red[i]) - green.begin() ;
        if(idx>0)
            g[0] = green[idx-1];
        if(idx<green.size())
            g[1] = green[idx];
        if(g[1]==red[i])
            g[0]=g[1];
            
        idx = lower_bound(blue.begin(),blue.end(),red[i]) - blue.begin();
        if(idx>0)
            b[0]=blue[idx-1];
        if(idx<blue.size())
            b[1] = blue[idx];
        if(b[1]==red[i])
            b[0]=b[1];
            
        if(g[0]!=-1 && b[1]!=-1)
        {
            long long int x = (red[i]-g[0])*(red[i]-g[0]) + (red[i]-b[1])*(red[i]-b[1]) + (g[0]-b[1])*(g[0]-b[1]);
            ans==-1 ? ans = x : ans = min(ans,x);
            //cout<<x<<" "<<ans<<endl;
        }
        if(g[1]!=-1 && b[0]!=-1)
        {
            long long int x = (red[i]-g[1])*(red[i]-g[1]) + (red[i]-b[0])*(red[i]-b[0]) + (g[1]-b[0])*(g[1]-b[0]);
            ans==-1 ? ans = x : ans = min(ans,x);
            //cout<<x<<" "<<ans<<endl;
        }
        //cout<<red[i]<<" "<<g[0]<<" "<<g[1]<<" "<<b[0]<<" "<<b[1]<<endl;
    }
    return ans;
}

void solve()
{
    int r , g , b  ;
    cin>>r>>g>>b;
    vector<ll>red(r);
    vector<ll>green(g);
    vector<ll>blue(b);
    
    for(int i=0;i<r;i++)
        cin>>red[i];
    for(int i=0;i<g;i++)
        cin>>green[i];
    for(int i=0;i<b;i++)
        cin>>blue[i];

    sort(red.begin(),red.end());
    sort(green.begin(),green.end());
    sort(blue.begin(),blue.end());
    
    long long int x = get_weight(red,green,blue) , y = get_weight(green,red,blue) , z = get_weight(blue,red,green);
    long long int ans = -1 ;
    if(x!=-1)
        ans==-1 ? ans=x : ans = min(ans,x);
    if(y!=-1)
        ans==-1 ? ans=y : ans=min(ans,y);
    if(z!=-1)
        ans==-1 ? ans=z : ans=min(ans,z);
    cout<<ans<<endl;
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