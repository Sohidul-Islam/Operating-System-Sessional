#include<bits/stdc++.h>
using namespace std;
int priority(vector<pair<int,int>>store,int pri[],int s);

int main()
{
    int n,i,j,st=0,et=0,a,b,wt[100],temp2,tb=0;
    float s1=0, s2=0,avw,avt;
    vector<pair<int,int>>v;
    vector<pair<int,int>>store;
    cin>>n;
    int p[n],pri[n];
    for(i=0; i<n; ++i)
    {
        cin>>a>>b>>pri[i];
        p[i] = i+1;
        v.push_back(make_pair(a,b));
        store.push_back(make_pair(a,b));
        tb+=b;
    }

    int max = pri[0];
    int temp;
    for(i = 0; i < n; i++)
    {
        if(pri[i]<max) max = pri[i];

        for(j = 0; j < n-i-1; j++)
        {
            if( store[j].first > store[j+1].first)
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

                temp = pri[j];
                pri[j] = pri[j+1];
                pri[j+1] = temp;
            }
        }
    }

    cout<<"After Sorting: "<<endl;
    cout<<"Process  Arrival-time(s)  Burst-time(s)  Priority-time(s)\n";
    for(i=0; i<n; i++)
    {

        cout<<"P"<<p[i]<<"              "<<store[i].first<<"                "<<store[i].second<<"                "<<pri[i]<<endl;
    }

    cout<<"Grant Chart: "<<endl;
    i = 0;
    while(i!=tb)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(et>store[n-1].first)
            {
                int a = priority(store,pri,n-1);
                if(store[a].second!=0)
                {
                    et = st+store[a].second;
                    pri[a]=INT_MAX;
                    cout<<"P"<<p[a]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<"(Previous Execution Time: "<<(v[a].second-store[a].second)<<")"<<endl;
                    wt[a] = st-(v[a].second-store[a].second)-store[a].first;
                    store[a].second =0;
                    st=et;
                }
            }
            else if(store[j].first!=store[j+1].first)
            {
                int a = priority(store,pri,j);

                if(store[a].second!=0 && pri[a]!=max)
                {

                    int tmp = (store[j+1].first-st);

                    if(tmp>=store[a].second)
                    {

                        et = et+store[a].second;
                        wt[a] = st-(v[a].second-store[a].second)-store[a].first;
                        cout<<"P"<<p[a]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<"(Previous Execution Time: "<<(v[a].second-store[a].second)<<")"<<endl;
                        store[a].second = store[a].second - store[a].second;
                        pri[a] = INT_MAX;
                    }
                    else
                    {

                        et = et+(store[j+1].first-st);
                        wt[a] = st-(v[a].second-store[a].second)-store[a].first;
                        cout<<"P"<<p[a]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<"(Previous Execution Time: "<<(v[a].second-store[a].second)<<")"<<endl;
                        store[a].second =store[a].second - (store[j+1].first-st);
                    }



                    st=et;

                }

                else if(store[a].second!=0)
                {
                    et = st+store[a].second;
                    pri[a]=INT_MAX;
                    cout<<"P"<<p[a]<<" start: "<<st<<"ms & end: "<<et<<"ms"<<"(Previous Execution Time: "<<(v[a].second-store[a].second)<<")"<<endl;
                    wt[a] = st-(v[a].second-store[a].second)-store[a].first;
                    store[a].second = 0;
                    st=et;

                }

            }

        }

        i=et;

    }

    cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)\n";

    for(i=0; i<n; i++)
    {
        s1+=wt[i];
        cout<<"P"<<p[i]<<"              "<<v[i].first<<"                "<<v[i].second<<"                  "<<wt[i]<<endl;
    }
    avw = s1/n;
    cout<<"Average Waiting Time: "<<avw<<endl;
}


int priority(vector<pair<int,int>>store,int pri[],int s)
{
    int mxpr = pri[0],a = 0;
    if(s==0 && store[s].second!=0)
    {
        return 0;
    }
    else
    {

        for(int i = 0 ; i<=s ; i++ )
        {

            if(pri[i]<mxpr && store[i].second!=0)
            {
                mxpr = pri[i];
                a = i;
            }

        }


        return a;
    }
}
