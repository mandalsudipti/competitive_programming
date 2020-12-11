#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    sort(arr.begin() , arr.end());
    bool flag = true ;
    vector<int>A;
    vector<int>B;
    
    for(int i=0;i<n;i++)
    {
        if(A.size() == 0 || arr[i] > A.back())
            A.push_back(arr[i]);
            
        else if(B.size() == 0 || arr[i] > B.back())
            B.push_back(arr[i]);
        else
        {
            flag = false;
            break;
        }
    }
    
    if(!flag)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        sort(B.begin() , B.end() , greater<int>());
        
        cout<<A.size()<<endl;
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";
        cout<<endl;
        cout<<B.size()<<endl;
        for(int i=0;i<B.size();i++)
            cout<<B[i]<<" ";
        cout<<endl;
        
        return 0;
    }
}