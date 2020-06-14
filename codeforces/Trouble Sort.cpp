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
        vector<int>A(n);
        vector<int>sorted_arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            sorted_arr[i] = A[i] ;
        }
        sort(sorted_arr.begin(),sorted_arr.end());
        int zero = -1 , one = -1 , val ;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            val==0?zero=i:one=i;
        }
        if(A==sorted_arr)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            if(one!=-1 && zero!=-1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}