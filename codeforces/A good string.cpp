#include<bits/stdc++.h>
using namespace std;
string S;

int make_same(int left , int right , char ch)
{
    int cnt = 0 ;
    for(int i=left;i<=right;i++)
        if(S[i]!=ch)
            cnt++;
            
    return cnt;
}

int make_good(int left , int right, char ch)
{
    if(left==right)
    {
        if(S[left]==ch)
            return 0;
        return 1;
    }
    
    int mid = (left+right)/2 ;
    
    int x = make_same(left,mid,ch) + make_good(mid+1,right,ch+1) ;
    int y = make_good(left,mid,ch+1) + make_same(mid+1,right,ch) ;
    
    return min(x,y);
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int len ;
        cin>>len;
        cin>>S;
        if(len==1)
        {
            S[0]=='a' ? cout<<"0"<<endl : cout<<"1"<<endl;
            continue;
        }
        int x = make_same(0,len/2 -1,'a') + make_good(len/2,len-1,'b');
        int y = make_good(0,len/2 -1,'b') + make_same(len/2,len-1,'a');
        cout<<min(x,y)<<endl;
    }
    return 0;
}