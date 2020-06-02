#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int x1 , y1 , x2 , y2 ;
        cin>>x1>>y1>>x2>>y2;
        cout<<(x2-x1)*(y2-y1)+1<<endl;
    }
    return 0;
}
