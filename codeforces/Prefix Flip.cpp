#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        string A, B;
        cin>>A>>B;
        vector<int>ans;
        int step = 0 , left = 0 , right = n-1 , prefix_len = n;
        for(int i=B.length()-1;i>=0;i--)
        {
            char ch = B[i] ;
            ++step ;
            if(step%2==1)
            {
                char x = A[left] ;
                left++;
                if(ch==x)
                    ans.push_back(1);
                ans.push_back(prefix_len);
                prefix_len--;
            }
            else
            {
                char x ;
                A[right]=='1' ? x='0' : x='1';
                right--;
                if(ch==x)
                    ans.push_back(1);
                ans.push_back(prefix_len);
                prefix_len--;
            }
        }
        cout<<ans.size()<<" ";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}