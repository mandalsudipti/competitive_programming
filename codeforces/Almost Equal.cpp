#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    if(n%2==0)
    {
        cout<<"NO";
        return 0;
    }
    int nxt=1 ,i;
    vector<int> arr1;
    vector<int> arr2;
    for(i=1;i<=2*n;i+=2)
    {
        if(nxt==1)
        {
            arr1.push_back(i);
            arr2.push_back(i+1);
            nxt=2;
        }
        else if(nxt==2)
        {
            arr2.push_back(i);
            arr1.push_back(i+1);
            nxt=1;
        }
    }
    
    cout<<"YES"<<endl;
    for(i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    for(i=0;i<n;i++)
        cout<<arr2[i]<<" ";
        
    return 0;
}