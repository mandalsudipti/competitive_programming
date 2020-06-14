#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int a , b ;
        cin>>a>>b;
        long long int x , cnt_two = 0 ;
        if(a>=b && a%b==0)
        {
            x = a/b;
        }
        else if(b>a && b%a==0)
        {
            x = b/a;
        }
        else
        {
            cout<<"-1"<<endl;
            continue;
        }
        while(x%2==0)
        {
            cnt_two++;
            x=x/2;
        }
        if(x!=1)
            cout<<"-1"<<endl;
        else
        {
            long long int ans = (cnt_two/3);
            cnt_two = cnt_two%3 ;
            ans+= (cnt_two/2) + (cnt_two%2) ;
            cout<<ans<<endl;
        }
    }
    return 0;
}