#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        string A , B ;
        cin>>A>>B ;
        
        if(A.length() > B.length())
            swap(A,B);
            
        int max_len = 0 ;
        for(int len = 1 ; len <= A.length() ; len++)
        {
            for(int left = 0 ; left < A.length() ; left++)
            {
                if(left + len - 1 >= A.length())
                    break;
                string tmp_A = A.substr(left,len);
                
                for(int i = 0 ; i < B.length() ; i++)
                {
                    if(i + len-1 >= B.length())
                        break;
                    string tmp_B = B.substr(i,len) ;
                    if(tmp_A == tmp_B)
                        max_len = max(max_len , len);
                }
            }
        }
        
        cout<<A.length() + B.length() - (2*max_len)<<endl;
    }
    
    return 0 ;
}