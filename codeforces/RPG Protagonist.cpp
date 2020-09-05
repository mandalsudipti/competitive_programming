#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int p , f , cnt_s , cnt_w , s , w ;
    cin>>p>>f>>cnt_s>>cnt_w>>s>>w;
    
    if(s>w)
    {
        swap(s,w);
        swap(cnt_s,cnt_w);
    }
    
    long long int max_cnt = 0 ;
    for(long long int i=0;i<=cnt_s;i++)
    {
        if(i*s>p)
            continue;
        long long int cnt = i ;
        long long int p1 = p - (cnt*s) , cnt_s1 = cnt_s - cnt ;
        
        cnt+=min(cnt_w , p1/w) ;
        long long int cnt_w1 = cnt_w - min(cnt_w , p1/w) ;
        
        cnt+=min(cnt_s1 , f/s);
        long long int f1 = f - s*min(cnt_s1 , f/s) ;
        cnt+=min(cnt_w1 , f1/w) ;
        
        max_cnt = max(max_cnt , cnt);
    }
    cout<<max_cnt<<endl;
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

