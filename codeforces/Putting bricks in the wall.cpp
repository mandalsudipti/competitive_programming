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
        vector<string>grid(n);
        for(int i=0;i<n;i++)
            cin>>grid[i];
            
        char start1 = grid[0][1] , start2 = grid[1][0] , end1 = grid[n-1][n-2] , end2 = grid[n-2][n-1] ;
        
        if(start1 == '0' && start2 == '0')
        {
            if(end1 == '0' && end2 == '0')
            {
                cout<<"2"<<endl;
                cout<<n<<" "<<n-1<<endl;
                cout<<(n-1)<<" "<<n<<endl;
            }
            else if(end1 == '1' && end2 == '1')
                cout<<"0"<<endl;
            else
            {
                cout<<"1"<<endl;
                if(end1 == '0')
                    cout<<n<<" "<<n-1<<endl;
                else
                    cout<<(n-1)<<" "<<n<<endl;
            }
        }
        else if(start1 == '1' && start2 == '1')
        {
            if(end1 == '1' && end2 == '1')
            {
                cout<<"2"<<endl;
                cout<<n<<" "<<n-1<<endl;
                cout<<(n-1)<<" "<<n<<endl;
            }
            else if(end1 == '0' && end2 == '0')
                cout<<"0"<<endl;
            else
            {
                cout<<"1"<<endl;
                if(end1 == '1')
                    cout<<n<<" "<<n-1<<endl;
                else
                    cout<<(n-1)<<" "<<n<<endl;
            }
        }
        else
        {
            if(end1 == '0' && end2 =='0')
            {
                cout<<"1"<<endl;
                if(start1 == '0')
                    cout<<"1"<<" "<<"2"<<endl;
                else
                    cout<<"2"<<" "<<"1"<<endl;
            }
            else if(end1 == '1' && end2 == '1')
            {
                cout<<"1"<<endl;
                if(start1 == '1')
                    cout<<"1"<<" "<<"2"<<endl;
                else
                    cout<<"2"<<" "<<"1"<<endl;
            }
            else
            {
                cout<<"2"<<endl;
                if(start1 == '1')
                    cout<<"1"<<" "<<"2"<<endl;
                else
                    cout<<"2"<<" "<<"1"<<endl;
                    
                if(end1 == '0')
                    cout<<n<<" "<<n-1<<endl;
                else
                    cout<<n-1<<" "<<n<<endl;
            }
        }
    }
    
    return 0;
}
