#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , a , b , c, d;
        cin>>n>>a>>b>>c>>d;
        long long int min_weight = n*(a-b) ;
        long long int max_weight = n*(a+b) ;
        if(min_weight<= (c-d) && max_weight>= (c-d))
            cout<<"Yes"<<endl;
        else if (min_weight<= (c+d) && max_weight>=(c+d))
            cout<<"Yes"<<endl;
        else if((c-d)<=min_weight && (c+d)>=max_weight)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
