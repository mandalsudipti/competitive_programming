#include<bits/stdc++.h>
using namespace std;

int main()
{
    long double x , y ;
    cin>>x>>y;
    long double left = y*log(x);
    long double right = x*log(y);
    
    if(left < right)
        cout<<"<"<<endl;
    else if(left > right)
        cout<<">"<<endl;
    else
        cout<<"="<<endl;
        
    return 0;
}