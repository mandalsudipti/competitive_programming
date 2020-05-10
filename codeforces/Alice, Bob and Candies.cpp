#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int a=0 , b=0 , Alice = 0, Bob=0;
        int left=0,right=n-1 , move=0;
        while(left<=right)
        {
            Alice=0;
            if(left<=right)
                move++;
            while(Alice<=Bob && left<=right)
            {
                Alice+=arr[left];
                a+=arr[left++];
            }
            Bob=0;
            if(left<=right)
                move++;
            while(Bob<=Alice && left<=right)
            {
                Bob+=arr[right];
                b+=arr[right--];
            }
        }
        cout<<move<<" "<<a<<" "<<b<<endl;
    }
    return 0;
}
