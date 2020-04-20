#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k;
    cin>>n>>k;
    vector<vector<int>> freq_op(200005,vector<int>(2,0));
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        int x=arr[i] ;
        freq_op[x][0]++;
        int op=0 ;
        while(x>0)
        {
            x/=2;
            op++;
            if(freq_op[x][0]<k)
            {
                freq_op[x][0]++;
                freq_op[x][1]+=op;
            }
        }
    }
    
    int minimum = INT_MAX ;
    for(int i=0;i<freq_op.size();i++)
    {
        //cout<<i<<" "<<freq_op[i][0]<<" "<<freq_op[i][1]<<endl;
        if(freq_op[i][0]>=k)
            minimum = min(minimum,freq_op[i][1]);
    }
    cout<<minimum;
    return 0;
}