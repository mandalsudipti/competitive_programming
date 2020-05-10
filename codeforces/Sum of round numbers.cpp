#include<bits/stdc++.h>
using namespace std;

int power(int x , int y)
{
    if(y==0)
        return 1;
    while(y>1)
    {
        x=x*10;
        y--;
    }
    return x;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int cnt =0 ;
        vector<int>digit;
        while(n!=0)
        {
            digit.push_back(n%10);
            if(digit.back()!=0)
                cnt++;
            n=n/10;
        }
        cout<<cnt<<endl;
        int p = power(10,digit.size()-1);
        for(int i=digit.size()-1;i>=0;i--)
        {
            if(digit[i]!=0)
                cout<<digit[i]*p<<" ";
            p=p/10;
        }
        cout<<endl;
    }
}