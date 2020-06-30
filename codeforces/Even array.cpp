#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int val , even_bad=0 , odd_bad=0;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            if(val%2!=i%2)
                i%2==1?odd_bad++:even_bad++;
        }
        if(even_bad==odd_bad)
            cout<<even_bad<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}