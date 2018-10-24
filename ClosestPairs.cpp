#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
};
int compx(const void *a,const void*b)
{
    Point*p1=(Point*)a;
    Point*p2=(Point*)b;
    return p1->x-p2->x;
}
int compy(const void *a,const void*b)
{
    Point*p1=(Point*)a;
    Point*p2=(Point*)b;
    return p1->y-p2->y;
}
float brute(Point P[],int n)
{
    int i,j,k;
    float mi=999999;
    for(int i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y))<mi)
               mi=sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y));
        }
    }
    return mi;
}
float stripclosest(Point P[],int n,float delta)
{
    float mi=delta;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;abs(P[i].y-P[j].y)<mi && j<n;j++)
        {
            if(sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y))<mi)
               mi=sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y));
        }
    }
    return mi;
}
float closestutil(Point Px[],Point Py[],int n)
{
    if(n<=3)
        return brute(Px,n);
    int mid=n/2;
    Point Pyl[mid+1];
    int yli=0;
    Point Pyr[mid+1];
    int yri=0;
    for(int i=0;i<n;i++)
    {
        if(Py[i].x<Px[mid].x)
        {
            Pyl[yli]=Py[i];
            yli++;
        }
        else
        {
            Pyr[yri]=Py[i];
            yri++;
        }
    }
    float dl,dr;
    dl=closestutil(Px,Pyl,mid);
    dr=closestutil(Px+mid,Pyr,n-mid);
    Point strip[n];
    int si=0;
    float delta=min(dl,dr);
    for(int i=0;i<n;i++)
    {
        if(abs(Px[mid].x-Px[i].x<delta))
        {
            strip[si]=Px[i];
            si++;
        }
    }
    return stripclosest(strip,n,delta);
}
float closest(Point P[],int n)
{
    Point Px[n],Py[n];
    for(int i=0;i<n;i++)
    {
        Px[i]=P[i];
        Py[i]=P[i];
    }
    qsort(Px,n,sizeof(Point),compx);
    qsort(Py,n,sizeof(Point),compy);
    return closestutil(Px,Py,n);
}
int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest(P, n));
    return 0;
}
