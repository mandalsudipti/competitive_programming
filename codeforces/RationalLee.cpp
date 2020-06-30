#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k , cnt_one=0;
        cin>>n>>k;
        vector<long long int>number(n);
        vector<long long int>person(k);
        for(int i=0;i<n;i++)
            cin>>number[i];
        for(int i=0;i<k;i++)
        {
            cin>>person[i];
            if(person[i]==1)
                cnt_one++;
        }
        sort(number.begin(),number.end());
        sort(person.begin(),person.end(),greater<long long int>());
        long long int sum = 0 , idx=0;
        for(int i=0;i<k;i++)
        {
            if(person[i]-1>=1)
            {
                sum+=number[idx];
                idx+=(person[i]-1);
            }
        }
        for(int i=n-1;i>=idx;i--)
        {
            if(cnt_one>0)
            {
                sum+=number[i]*2;
                cnt_one--;
            }
            else
                sum+=number[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}