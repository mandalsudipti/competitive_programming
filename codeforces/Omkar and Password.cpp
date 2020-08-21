#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        bool flag = true ;
        for(int i=1;i<n;i++)
        {
            if(arr[i]!=arr[0])
            {
                flag = false;
                break;
            }
        }
        if(!flag)
            cout<<"1"<<endl;
        else
            cout<<n<<endl;
    }
    return 0;
}