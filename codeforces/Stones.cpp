#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int max_b = b - min(c/2,b) ;
        int cnt = min(max_b/2,a)*3+ min(c/2,b)*3;
        int tmp = b ;
        b = b- min(max_b/2,a)*2 - min(c/2,b) ;
        c = c - min(c/2,tmp)*2;
        a = a - min(max_b/2,a);
        while(c>=2 && b>=1)
        {
            cnt+=3;
            b--;
            c-=2;
        }
        while(b>=2 && a>=1)
        {
            cnt+=3;
            b-=2;
            a--;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

