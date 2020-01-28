#include<bits/stdc++.h>
using namespace std;
bool perfect(long long int num , int idx)
{
    long long int sum=0,number=num;
    while(num>0)
    {
        sum+=num%10;
        num=num/10;
    }
    if(sum==10)
    {
        //cout<<idx<<"->"<<number<<endl;
        return true;
    }
    else
        return false;
}
int main()
{
    int i=0,k;
    cin>>k;
    long long int num=19;
    while(i<10001)
    {
        if(perfect(num,i+1))
        {
            i++;
            if(i==k)
            {
                cout<<num;
                return 0;
            }
        }
        num++;
    }
    
    return 0;
}
