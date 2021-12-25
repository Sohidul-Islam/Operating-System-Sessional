#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,st=0,et,b,ct[100],wt[100],temp2,pri;
    float s1=0, s2=0,avw,avt;
    vector<pair<int,int>>v;
    vector<pair<int,int>>store;
    cin>>n;
    int p[n];
    for(i=0; i<n; ++i)
    {
        cin>>b>>pri;
        p[i] = i+1;
        v.push_back(make_pair(b,pri));
        store.push_back(make_pair(b,pri));
    }

     int temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if( store[j].second > store[j+1].second)
            {
                temp = store[j].first;
                store[j].first = store[j+1].first;
                store[j+1].first = temp;

                temp = store[j].second;
                store[j].second = store[j+1].second;
                store[j+1].second = temp;

                temp = v[j].first;
                v[j].first = v[j+1].first;
                v[j+1].first = temp;

                temp = v[j].second;
                v[j].second = v[j+1].second;
                v[j+1].second = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    cout<<"Grant Chart: "<<endl;
    et = st+store[0].first;
    store[0].first = 0;
    wt[0] = 0;
    cout<<"P"<<p[0]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<endl;

    i = 0;
    for(int j = 0 ; j < n ; j++)
    {
        if(store[j].first!=0)
        {
            st=et;
            et=st+store[j].first;
            store[j].first = 0;
            cout<<"P"<<p[j]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<endl;
            wt[j] = st;
        }

        s1+=wt[j];
    }
    avw = s1/n;

    cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)\n";

    for(i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"              "<<v[i].first<<"                "<<v[i].second<<"                  "<<wt[i]<<endl;
    }
    cout<<"Average Waiting Time: "<<avw<<endl;
}
