#include<bits/stdc++.h>
using namespace std;

void find_divisor(long long int x , vector<long long int>&divisor)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
           divisor.push_back(i);
           if(i!=(x/i))
                divisor.push_back((x/i));
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<long long int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        long long int x = arr[0]*arr[n-1];
        bool possible=true;
        int left = 1 , right = n-2 ;
        while(right>=0 && left<=right)
        {
            if(arr[left]*arr[right]!=x)
            {
                possible=false;
                break;
            }
            left++;
            right--;
        }
        if(!possible)
            cout<<"-1"<<endl;
        else
        {
            vector<long long int>divisor;
            find_divisor(x,divisor);
            sort(divisor.begin(),divisor.end());
            if(arr==divisor)
                cout<<x<<endl;
            else
                cout<<"-1"<<endl;
        }
    }
    return 0;
}
