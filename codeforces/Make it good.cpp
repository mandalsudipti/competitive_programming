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
        multiset<int>present;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            present.insert(arr[i]);
        }
        
        int prefix = -1, left = 0 , right = n-1;
        
            while(present.size()>0)
            {
                int find = *(present.begin());
                //cout<<find<<endl;
                while(arr[left]!=find && arr[right]!=find && left<=right)
                {
                    //cout<<find<<endl;
                    present.erase(present.lower_bound(arr[left]));
                    prefix = left ;
                    left++;
                }
                if(arr[left]==arr[right])
                    right--;
                else if(left<n && arr[left]==find)
                    left++;
                else if(right>=0 && arr[right]==find)
                    right--;
                    
                present.erase(present.begin());
            }
        cout<<prefix+1<<endl;
    }   
    
    return 0;
}

