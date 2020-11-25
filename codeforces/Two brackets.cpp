#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        vector<int>open_A;
        vector<int>close_A;
        vector<int>open_B;
        vector<int>close_B;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
                open_A.push_back(i);
            else if(S[i]==')')
                close_A.push_back(i);
            else if(S[i]=='[')
                open_B.push_back(i);
            else
                close_B.push_back(i);
        }
        
        int cnt = 0 ,left = 0 ,right = 0;
        while(left < open_A.size() && right < close_A.size())
        {
            if(open_A[left] < close_A[right])
            {
                cnt++;
                //cout<<open_A[left]<<" "<<close_A[right]<<endl;
                left++;
                right++;
            }
            else
                right++;
            
        }
        //cout<<"--------------\n";
        left = 0 ;
        right = 0 ;
        while(left < open_B.size() && right < close_B.size())
        {
            if(open_B[left] < close_B[right])
            {
                cnt++;
                //cout<<open_B[left]<<" "<<close_B[right]<<endl;
                left++;
                right++;
            }
            else
                right++;
        }
        
        cout<<cnt<<endl;
        
    }
    
    return 0;
}