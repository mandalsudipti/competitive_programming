#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ,val;
        cin>>n;
        set<int>arr;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            arr.insert(val);
        }
        cout<<arr.size()<<endl;
    }
    return 0;
}