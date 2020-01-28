#include<bits/stdc++.h>
using namespace std;

bool sortseg( const vector<int>& v1, const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

bool sortidx( const vector<int>& v1, const vector<int>& v2 ) { 
 return v1[2] < v2[2]; 
} 

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,i,min,max;
        bool flag=true;
        cin>>n;
        vector<vector<int>>vect(n,vector<int>(4,0));
        for(i=0;i<n;i++)
        {
            cin>>vect[i][0]>>vect[i][1]; //segment
            vect[i][2]=i; //index
        }
        sort(vect.begin(),vect.end(),sortseg);
        vect[0][3]=1; //group
        min=vect[0][0];
        max=vect[0][1];
        for(i=1;i<n;i++)
        {
            if(vect[i][0]<=max)
            {
                vect[i][3]=1;
                if(vect[i][1]>max)
                    max=vect[i][1];
            }
            else if(flag)
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"-1"<<endl;
        else
        {
            sort(vect.begin(),vect.end(),sortidx);
            for(i=0;i<n;i++)
            {
                if(vect[i][3]==0)
                    cout<<"2 ";
                else 
                    cout<<"1 ";
            }
            cout<<endl;
        }
    }
}