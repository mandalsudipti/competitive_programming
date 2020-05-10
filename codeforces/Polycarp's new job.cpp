#include<bits/stdc++.h>
using namespace std;

void swap(int *x , int *y)
{
    int t = *x ;
    *x = *y ;
    *y = t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    int A_max = 0 , B_max = 0;
    cin>>T;
    while(T--)
    {
        char ch;
        int x , y ;
        cin>>ch>>x>>y;
        if(ch=='+')
        {
            if(x<y)
                swap(&x,&y);
            A_max = max(x,A_max);
            B_max = max(y,B_max);
        }
        else if(ch=='?')
        {
            if(A_max>max(x,y) || B_max>min(x,y))
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    return 0;
}
