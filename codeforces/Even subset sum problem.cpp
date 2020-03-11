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
        int arr[n+1],i,even=-1,odd1=-1,odd2=-1;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            if(arr[i]%2==0)
                even=i;
            else
            {
                if(odd1==-1)
                    odd1=i;
                else
                    odd2=i;
            }
        }
        if(even!=-1)
        {
            cout<<"1\n";
            cout<<even<<endl;
        }
        else if(odd1!=-1 && odd2!=-1)
        {
            cout<<"2\n";
            cout<<odd1<<" "<<odd2<<endl;
        }
        else
            cout<<"-1\n";
    }
    return 0;
}

