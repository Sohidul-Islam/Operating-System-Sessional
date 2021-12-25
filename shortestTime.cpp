#include<bits/stdc++.h>

using namespace std;
int main()
{
      int n,temp,tt=0,min,d,i,j;
      float atat=0,awt=0,stat=0,swt=0;

      cout<<"enter no of process"<<endl;
      cin>>n;
      int a[n],p[n],b[n],e[n],tat[n],wt[n];

      for(i=0;i<n;i++)
      {
            cout<<"enter arival time ";       //input
            cin>>a[i];
            p[i] = i+1;
      }
      for(i=0;i<n;i++)
      {
            cout<<"enter brust time ";      //input
            cin>>b[i];
      }

      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=p[i];
                      p[i]=p[j];
                      p[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }

      for(int i = 0 ; i<n ; i++){
        cout<<a[i]<<" "<<b[i]<<endl;
      }

      min = a[0];
      for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];
                  d=i;
            }
      }

      cout<<"Min : "<<min<<endl;
      tt=min;
      if(b[d]==1){
       e[d]=tt+b[d];
      }
      else{
        e[d]=tt+1;
        b[d]=b[d]-1;
      }

      tt=e[d];
     cout<<"tt : "<<tt<<endl;
       for(int i = 0 ; i<n ; i++){
        cout<<a[i]<<" "<<b[i]<<endl;
      }

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-a[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];
            swt=swt+wt[i];
      }
      atat=stat/n;
      awt=swt/n;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<p[i]<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"awt="<<awt<<" atat="<<atat;  //average waiting time and turn around time
}
