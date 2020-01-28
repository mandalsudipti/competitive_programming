#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,i,j;
        long long int val;
        cin>>n;
        set<long long int > arr;
        for(i=0;i<n;i++)
        {
            cin>>val;
            if(val%2==0)
            {
                while(val%2==0)
                {
                    int x=arr.size();
                    arr.insert(val);
                    if(x==arr.size())
                        break;
                    else
                        val=val/2;
                }
            }
        }
        cout<<arr.size()<<endl;
    }
    return 0;
}
