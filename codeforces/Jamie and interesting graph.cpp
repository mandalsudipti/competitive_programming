#include<bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
    if(x<=1)
        return false;
        
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int nxt_prime(int x)
{
    x++;
    while(!is_prime(x))
        x++;
    return x;
}

int main()
{
    int node , edge ;
    cin>>node>>edge ;
    
    long long int shortest_path = nxt_prime(node-2)  ;
    
    long long int mst_cost = shortest_path ;
    
    cout<<shortest_path<<" "<<mst_cost<<endl;
    
    for(int i=1;i<node;i++)
    {
        if(i==1)
        {
            cout<<i<<" "<<i+1<<" "<<(mst_cost - (node-2))<<endl;
            continue;
        }
        cout<<i<<" "<<i+1<<" "<<1<<endl;
    }
    edge-=(node-1);

    for(int i=1;i<=node && edge>0;i++)
    {
        for(int j=i+2;j<=node && edge>0;j++)
        {
            cout<<i<<" "<<j<<" "<<mst_cost<<endl;
            edge--;
        }
    }
    
    return 0;
}