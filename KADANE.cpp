#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int size)
{
   int msf = a[0];
   int cmx = a[0];
   int oldcmx=a[0],indi;
   for (int i = 1; i < size; i++)
   {
        oldcmx=cmx;
        cmx = max(a[i], cmx+a[i]);
        msf = max(msf, cmx);
        if(msf==cmx && oldcmx!=cmx)
        {
            indi=i;
        }
   }
   int j=indi;
   int sum=0;
   while(j>=0 && sum<msf)
   {
       sum+=a[j];
       j--;
   }
   cout<<a[j+1]<<" "<<a[indi]<<endl;
   return msf;
}
int main()
{
    int a[]={-1,3,-2,5,-6,1};
    cout<<kadane(a,6);
    return 0;
}
