#include<bits/stdc++.h>
using namespace std;
void queen_attack(int mat[][1000],int n,int qx,int qy)
{
    int i,j,x,y;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            mat[i][j]=0;
    }
    for(i=0;i<n;i++)
    {
        mat[i][qy]=1;
        mat[qx][i]=1;
    }
    x=qx;
    y=qy;
    while(x>=0 && y<n)
        mat[x--][y++]=1;
    x=qx;
    y=qy;
    while(x>=0 && y>=0)
        mat[x--][y--]=1;
    x=qx;
    y=qy;
    while(x<n && y<n)
        mat[x++][y++]=1;
    x=qx;
    y=qy;
    while(x<n && y>=0)
        mat[x++][y--]=1;
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }*/
    
}
int main() //1033A
{
    int n;
    cin>>n;
    int mat[n][1000],qx,qy,sx,sy,dx,dy,lx,ly,rx,ry,i,j;
    cin>>qx>>qy>>sx>>sy>>dx>>dy;
    qx=qx-1;
    qy=qy-1;
    if(sy<dy)
    {
        lx=sx-1;
        ly=sy-1;
        rx=dx-1;
        ry=dy-1;
    }
    else
    {
        lx=dx-1;
        ly=dy-1;
        rx=sx-1;
        ry=sy-1;
    }
    //cout<<"lx->"<<lx<<" ly->"<<ly<<endl;
    queen_attack(mat,n,qx,qy);
    int prex[1000000],prey[1000000],len=0;
    bool flag=true;
    while(ly<ry || lx!=rx)
    {
        if(ly+1<=ry && mat[lx][ly+1]==0)
        {
            prex[len]=lx;
            prey[len++]=ly;
            mat[lx][++ly]=1;
            //cout<<"right ";
        }
        else if(lx-1>=rx && mat[lx-1][ly]==0)
        {
            prex[len]=lx;
            prey[len++]=ly;
            mat[--lx][ly]=1;
            //cout<<"up ";
        }
        else if(lx+1<=rx && mat[lx+1][ly]==0)
        {
            prex[len]=lx;
            prey[len++]=ly;
            mat[++lx][ly]=1;
            //cout<<"down ";
        }
        else if(lx-1>=0 && ly+1<=ry && mat[lx-1][ly+1]==0)
        {
            prex[len]=lx;
            prey[len++]=ly;
            mat[--lx][++ly]=1;
            //cout<<"dup ";
        }
        else if(lx+1<n && ly+1<=ry && mat[lx+1][ly+1]==0 )
        {
            prex[len]=lx;
            prey[len++]=ly;
            mat[++lx][++ly]=1;
            //cout<<"ddown ";
        }
        else if(len==0)
        {
            cout<<"NO";
            flag=false;
            break;
        }
        else
        {
            len--;
            lx=prex[len];
            ly=prey[len];
        }
    }
    if(flag)
    {
        cout<<"YES";
    }
    return 0;
}