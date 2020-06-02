#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int h , c ,tmp ;
        cin>>h>>c>>tmp;
        if(tmp<=(long double)(h+c)/(long double)(2) )
        {
            cout<<"2"<<endl;
            continue;
        }
        int M = (h-tmp)/(2*tmp - h - c) ;
        if((h-tmp)%(2*tmp - h -c)==0)
            cout<<(2*M)+1<<endl;
        else
        {
            //cout<<M<<endl;
            long double t1 = (long double)((h+c)*M+h)/(long double)(2*M+1);
            M++;
            long double t2 = (long double)((h+c)*M+h)/(long double)(2*M+1);
            //cout<<abs(t1-(double)tmp)<<" "<<abs(t2-(double)tmp)<<endl;
            if( abs(t1-(double)tmp)<=abs(t2-(double)tmp) )
                M--;
            cout<<(2*M)+1<<endl;
        }
    }
    return 0;
}

