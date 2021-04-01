#include<bits/stdc++.h>
using namespace std;

void check(long long int val , int d)
{
    if(val < d)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(val%10 == d || val/10 == d)
    {
        cout<<"YES"<<endl;
        return;
    }
    while(val >= d)
    {
        val = val - d ;
        if(val % 10 == d)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int q , d ;
        cin>>q>>d;
        vector<long long int>arr(q);
        for(int i = 0 ; i < q ; i++)
        {
            cin>>arr[i];
            if(floor(log10(arr[i])+1) >= 3 || arr[i] >= (d*10)+d)
                cout<<"YES"<<endl;
            else
                 check(arr[i],d);
        }
    }
    
    return 0;
}

