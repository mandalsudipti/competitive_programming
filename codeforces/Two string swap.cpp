#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    string S , T ;
    cin>>S>>T;
    int left = -1  , right = n , cnt = 0 ;
    while(left<right)
    {
        left++;
        right--;
        //cout<<left<<" "<<right<<endl;
        if(left>=n || right<0 || left>right)
            break;
        
        if(left==right)
        {
            if(S[left]!=T[left])
                cnt++;
            continue;
        }
        
        if((S[left]==S[right] && T[left]==T[right]) || (S[left]==T[left] && S[right]==T[right]) || (S[left]==T[right] && S[right]==T[left]))
            continue;
        else if(S[left]==T[left] || S[left]==T[right] || S[right]==T[left] || S[right]==T[right] || T[left]==T[right])
            cnt++;
        else
            cnt+=2;
    }
    
    cout<<cnt<<endl;
    
    return 0;
}


