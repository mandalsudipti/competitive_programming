#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n ;
        cin>>n;
        vector<long long int>increment ;
        if(n==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        n--;
        increment.push_back(1);
        int start = 2 ;
        while(n-start>=0)
        {
            increment.push_back(start);
            n-=start;
            start = start * 2 ;
        }
        if(n>0)
        {
            int idx =  upper_bound(increment.begin(),increment.end(),n) - increment.begin();
            increment.insert(increment.begin()+idx,n);
        }
        cout<<increment.size()-1<<endl;
        for(int i=1;i<increment.size();i++)
        {
            cout<<increment[i] - increment[i-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}