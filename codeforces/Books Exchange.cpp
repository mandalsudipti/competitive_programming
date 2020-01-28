#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        //int i;
        int arr[N],myday[N],day,val,i;
        for(i=1;i<=N;i++)
            cin>>arr[i];
        for(i=1;i<=N;i++)
        {
            day=1;
            val=arr[i];
            while(val!=i)
            {
                val=arr[val];
                day++;
            }
            myday[i]=day;
        }
        for(i=1;i<=N;i++)
            cout<<myday[i]<<" ";
        cout<<endl;
    }
    return 0;
}


