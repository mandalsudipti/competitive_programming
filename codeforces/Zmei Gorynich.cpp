#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n , type ;
    cin>>type>>n;
    int damage , head ;
    int max_damage = 0 , max_diff = 0 ;
    for(int i=0;i<type;i++)
    {
        cin>>damage>>head;
        max_diff = max(max_diff,damage-head);
        max_damage = max(max_damage,damage) ;
    }
    if(n<=max_damage)
    {
        cout<<"1"<<endl;
        return;
    }
    if(max_diff<=0)
    {
        cout<<"-1"<<endl;
        return ;
    }
    int x = (n- max_damage)/max_diff + ((n - max_damage)%max_diff!=0) ;
    cout<<(x+1)<<endl;
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


