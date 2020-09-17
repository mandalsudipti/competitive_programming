#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<long long int>arr(n+1);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cout<<"1"<<" "<<"1"<<endl;
    cout<<(-1)*arr[1]<<endl;
    if(n>1)
    {
        cout<<"1"<<" "<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            if(i==1)
                cout<<"0"<<" ";
            else
                cout<<(-1)*n*arr[i]<<" ";
        }
        cout<<endl;
        
        cout<<"2"<<" "<<n<<endl;
        for(int i=2;i<=n;i++)
            cout<<(n-1)*arr[i]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"1"<<" "<<"1"<<endl;
        cout<<"0"<<endl;
        cout<<"1"<<" "<<"1"<<endl;
        cout<<"0"<<endl;
    }
    return 0;
}
