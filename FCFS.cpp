#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,a,b,ct[100],wt[100],tt[100],temp;
    float s1=0, s2=0,avw,avt;
    vector<pair<int,int>>v;

    cin>>n;
    int p[n];

    for(i=0; i<n; ++i)
    {
        cin>>a>>b;
        p[i] = i+1;
        v.push_back(make_pair(a,b));
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(v[j].first>v[j+1].first)
            {
                temp=v[j].first;
                v[j].first=v[j+1].first;
                v[j+1].first=temp;

                temp=v[j].second;
                v[j].second=v[j+1].second;
                v[j+1].second=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;


            }
        }
    }
    int x = 0;
    for(i = 0 ; i<n ; ++i)
    {
        ct[i] = x+v[i].second;
        x+=v[i].second;
    }

    for(i = 0 ; i < n ; ++i)
    {
        tt[i] = ct[i] - v[i].first;
        s1+= tt[i];
    }

    for(i = 0 ; i<n ; ++i)
    {
        wt[i] = tt[i]-v[i].second;
        s2+=wt[i];
    }
    int st=0,et;
    for(i = 0; i<n ; ++i)
    {
        et = st+v[i].second;
        cout<<"P"<<p[i]<<" start "<<st<<"s & end "<<et<<"s"<<endl;
        st = et;
    }

    avw = s1/n;
    avt = s2/n;
    cout<<"Process  Arrival-time(s)  Burst-time(s)  Turnaround-time(s)   Waiting-time(s)\n";

    for(i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"              "<<v[i].first<<"                "<<v[i].second<<"                  "<<tt[i]<<"               "<<wt[i]<<endl;
    }
    cout<<endl<<"Total Turnarround time: "<<s1<<endl
        <<"Total Waiting time: "<<s2<<endl;

    cout<<endl<<"Average Turnarround time: "<<avw<<endl
        <<"Average Waiting time: "<<avt<<endl;


}
