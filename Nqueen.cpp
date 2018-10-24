#include<bits/stdc++.h>
using namespace std;
int col[10];
int bd[10];
int fd[10];
int mat[4][4];
int issafe(int i,int j)
{
    if(col[j]==0)
    {
        if(bd[4+i-j]==0)
        {
            if(fd[i+j]==0)
                {return 1;}
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}
int nqueen(int rowi)
{
    if(rowi==4)
        return 1;
    int i,j,k;
    for(int co=0;co<4;co++)
    {
        if(issafe(rowi,co))
        {
            mat[rowi][co]=1;
            col[co]=1;
            fd[rowi+co]=1;
            bd[rowi-co+4]=1;
            if(nqueen(rowi+1))
                return 1;
            mat[rowi][co]=0;
            col[co]=0;
            fd[rowi+co]=0;
            bd[rowi-co+4]=0;
        }
    }
    return 0;
}
int main()
{
    int n=4;
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            mat[i][j]=0;
    }
    if(!nqueen(0))return 0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
