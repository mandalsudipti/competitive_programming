#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[2*n+1],i;
        arr[0]=0;
        for(i=1;i<=2*n;i++)
            cin>>arr[i];
        map<long long int ,int > suffix ;
        int suffix_1=0 , suffix_2=0 ;
        for(i=2*n;i>n;i--)
        {
            if(arr[i]==2)
                suffix_2++;
            else
                suffix_1++;
            suffix[suffix_1-suffix_2]=i ;
        }
        
        int max_berry=0 , prefix_1=0 , prefix_2=0 ;
        for(i=0;i<=n;i++)
        {
            prefix_1+=(arr[i]==1);
            prefix_2+=(arr[i]==2);
            if(prefix_2==prefix_1)
                max_berry=max(max_berry,i);
            if(suffix[prefix_2-prefix_1]!=0)
            {
                int choose_berry= i+( 2*n-( suffix[prefix_2-prefix_1] -1 ));
                //cout<<choose_berry<<endl;
                max_berry = max(max_berry , choose_berry);
            }
        }
        cout<<2*n-max_berry<<endl;
    }
    return 0;
}
