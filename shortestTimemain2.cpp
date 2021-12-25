#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,st,et,a,b,wt[100],temp2;
    float s1=0, s2=0,avw;
    vector<pair<int,int>>v;
    vector<pair<int,int>>store;
    cin>>n;
    int p[n];
    for(i=0; i<n; ++i)
    {
        cin>>a>>b;
        p[i] = i+1;
        v.push_back(make_pair(a,b));
        store.push_back(make_pair(a,b));
    }
    a = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(v[a].first>v[i].first)
        {
            a = i;
        }
    }

    int l = 99999;

    for(int i = 0 ; i<n ; i++)
    {
        if(l>v[i].first && v[i].first!=v[a].first)
        {
            l = i;

        }
    }

    int scndArrive = v[l].first-v[a].first;

    //for the first time arrived process
    if(v[a].second != scndArrive)
    {
        store[a].second = v[a].second - scndArrive;
    }
    else
    {
        store[a].second = 0;
    }
    temp2 = store[a].first;
    st = v[a].first;
    et = st+scndArrive;

    cout<<"Grant Chart: "<<endl;
    cout<<"P"<<p[a]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<" ("<<"0ms has been executed before)"<<endl;
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

    for(int j = 0 ; j < n ; j++)
    {
        if(store[j].second!=0)
        {
            st=et;
            et=st+store[j].second;
            int tmp=store[j].second,ne;
            store[j].second = 0;
            ne = v[j].second-tmp;
            cout<<"P"<<p[j]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<" ("<<(ne)<<"ms has been executed before)"<<endl;

            wt[j] = st-ne-store[j].first;

        }

        s1+=wt[j];
    }
    avw = s1/n;
    cout<<endl;
    cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)\n";

    for(i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"              "<<v[i].first<<"                "<<v[i].second<<"                  "<<wt[i]<<endl;
    }
    cout<<"Average Waiting Time: "<<avw<<endl;
}
