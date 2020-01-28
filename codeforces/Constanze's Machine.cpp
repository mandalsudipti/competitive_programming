#include<bits/stdc++.h>
using namespace std;
long long int getway(long long int len)
{
    long long int res[len]={0},i,mod=1e9+7;
    res[0]=1;
    res[1]=1;
    for(i=2;i<=len;i++)
    {
        res[i]=res[i-1]+res[i-2];
        res[i]=res[i]%mod;
    }
    return res[len];
}
int main()
{
    string arr;
    long long int way=1,sublen=1,i,mod=1e9+7;
    cin>>arr;
    for(i=0;i<arr.length();i++)
    {
        if(arr[i]=='m'|| arr[i]=='w')
        {
            cout<<"0";
            return 0;
        }
    }
    for(i=1;i<arr.length();i++)
    {
        if(arr[i]==arr[i-1]&&(arr[i]=='n'||arr[i]=='u'))
            sublen++;
        if(sublen>=2&&(arr[i]!=arr[i-1] || i==arr.length()-1))
        {
            //cout<<"length of substring->"<<sublen<<endl;
            way=way*getway(sublen);
            way=way%mod;
            sublen=1;
        }
    }
    cout<<way%mod;
    return 0;
}





