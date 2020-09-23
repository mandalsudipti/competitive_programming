#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int a , b ;
    cin>>a>>b;
    
    long long int idx = 0 ;
    while(true)
    {
        if(a+b<((idx+1)*(idx+2))/2)
            break;
        else
            idx++;
    }
    
    vector<long long int>arr1 ;
    vector<long long int>arr2 ;
    for(int i=idx;i>0;i--)
    {
        if(a>=i)
        {
            arr1.push_back(i);
            a-=i;
        }
        else
        {
            arr2.push_back(i);
            b-=i;
        }
    }
    
    cout<<arr1.size()<<"\n";
    for(int i=0;i<arr1.size();i++)
        cout<<arr1[i]<<" ";
    cout<<"\n";
    cout<<arr2.size()<<"\n";
    for(int i=0;i<arr2.size();i++)
        cout<<arr2[i]<<" ";
    cout<<"\n";
    
    return 0;
}

