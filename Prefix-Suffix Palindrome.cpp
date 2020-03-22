#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string S;
    cin>>S;
    int left=0,right=S.length()-1;
    string l_palindrome,r_palindrome,first="";
    while(left<right)
    {
        if(S[left]==S[right])
        {
            first+=S[left];
            left++;
            right--;
        }
        else
        {
            break;
        }
    } // first step
    int l=left , r=right;
    for(int i=r;i>=l;i--)
    {
        if(S[i]==S[left])
        {
            string T= S.substr(left,i-left+1) , X;
            X=T;
            reverse(T.begin(),T.end());
            if(X==T)
            {
                l_palindrome=X;
                break;
            }
        }
    } // left palindrome
    
    l=left; r=right;
    for(int i=l;i<=r;i++)
    {
        if(S[i]==S[right])
        {
            string T=S.substr(i,right-i+1) , X;
            X=T;
            reverse(T.begin(),T.end());
            if(X == T)
            {
                r_palindrome = X;
                break;
            }
        }
    } // right palindrome 
    
    string ans=first;
    if(l_palindrome.length()>=r_palindrome.length())
        ans=ans+l_palindrome;
    else
        ans=ans+r_palindrome;
    reverse(first.begin(),first.end());
    ans+=first;
    
    cout<<ans<<endl;
}

int main()
{
    int n ;
    cin>>n;
    while(n--)
        solve();
    return 0;
}