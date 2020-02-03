#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , position , controlled ,uncontrolled,i;
        cin>>n>>position>>controlled;
        vector<int> arr(n+1);
        for(i=1;i<=n;i++)
            cin>>arr[i];
        controlled=min(controlled,position-1);
        uncontrolled= (position-1)-controlled ;
        int best_ans=0;
        for(int c=0 ;c<=controlled;c++)
        {
            int best_c=1e9+5;
            for(int i=0;i<=uncontrolled;i++)
            {
                int prefix=(i+c);
                int suffix = n - (uncontrolled-i) - (controlled-c)+1;
                best_c=min(best_c, max(arr[prefix+1],arr[suffix-1]));
            }
            best_ans = max(best_ans,best_c);
        }
        cout<<best_ans<<endl;
    }
    return 0;
}