#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        
        vector<int>A(n);
        vector<int>B(n);
        
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<n;i++)
            cin>>B[i];
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end(),greater<int>());
        
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(A[i]+B[i]>x)
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}