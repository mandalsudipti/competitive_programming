#include<bits/stdc++.h>
using namespace std;

long long int get_int(string S)
{
    long long int num = 0 ;
    reverse(S.begin(),S.end());
    for(long long int i=0;i<S.length();i++)
        if(S[i]=='1')
            num+=(1ll<<i);
    return num;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , m ;
        cin>>n>>m;
        set<long long int>deleted_num;
        long long int mid = ((1ll<<m)-1)/2 , left = ((1ll<<m)-1)/2  , right = (1ll<<m) - (mid+1);
        //cout<<mid<<" "<<left<<" "<<right<<endl;
        while(n--)
        {
            string S;
            cin>>S;
            long long int num = get_int(S);
            deleted_num.insert(num);
            //cout<<num<<endl;
            if(num<mid)
            {
                left--;
                if(right-left>1)
                {
                    mid++;
                    while(deleted_num.find(mid)!=deleted_num.end())
                        mid++;
                    left++;
                    right--;
                    //cout<<mid<<endl;
                }
            }
            else if(num>mid)
            {
                if(right-left==1)
                {
                    right--;
                }
                else
                {
                    left--;
                    mid--;
                    while(deleted_num.find(mid)!=deleted_num.end())
                        mid--;
                }
                //cout<<mid<<endl;
            }
            else
            {
                if(right-left==0)
                {
                    mid--;
                    while(deleted_num.find(mid)!=deleted_num.end())
                        mid--;
                    left--;
                }
                else 
                {
                    mid++;
                    while(deleted_num.find(mid)!=deleted_num.end())
                        mid++;
                    right--;
                }
                //cout<<mid<<endl;
            }
        }
        string S;
        while(mid>0)
        {
            S+=((mid%2)+48);
            mid = mid/2 ;
        }
        reverse(S.begin(),S.end());
        while(S.length()<m)
            S='0'+S;
        cout<<S<<endl;
    }
    return 0;
}

