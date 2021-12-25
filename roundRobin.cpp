#include<bits/stdc++.h>
using namespace std;

queue <int>q;
vector <pair<int,int>> store;
void showqueue(queue <int>p,int r[])
{
    if(p.empty())
    {
        cout<<"Queue Is Empty"<<endl;
    }
    else
    {
        cout<<"Ready Queue: "<<endl;
        while(!p.empty())
        {
            int h = p.front();
            p.pop();
            cout<<"[P"<<r[h]<<"] ";

        }
    }

    cout<<endl<<endl;

}

void searchProcess(int st,int clk)
{
    for(int j = st; j <=clk ; j++)
        for(int i = 0 ; i < store.size(); i++)
        {
            if(store[i].first == j)
            {
                q.push(i);

            }
        }
}
int main()
{
    vector <pair<int,int>> v;
    int n,a,b,at,bt,tq,st,et,tmp,clk = 0,remain,swt=0,stt=0;
    float avw,avt;
    cin>>n;
    int p[n],wt[n],tt[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        store.push_back(make_pair(a,b));
        p[i] = i+1;
    }
    cin>>tq;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            if(store[j].first>store[j+1].first)
            {
                tmp = store[j].first;
                store[j].first = store[j+1].first;
                store[j+1].first=tmp;

                tmp = store[j].second;
                store[j].second = store[j+1].second;
                store[j+1].second=tmp;

                tmp = v[j].first;
                v[j].first = v[j+1].first;
                v[j+1].first=tmp;

                tmp = v[j].second;
                v[j].second = v[j+1].second;
                v[j+1].second=tmp;

                tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
            }
        }

    }

    q.push(0);
    st = 0;
    remain = n;
    while(remain!=0)
    {
        int tmp2 = q.front();
        if(store[tmp2].second <=tq )
        {
            et = st+store[tmp2].second;
            store[tmp2].second = 0;
            remain--;
            q.pop();
            clk = et;
            searchProcess(st+1,clk);
            cout<<"P"<<p[tmp2]<<" start : "<<st<<" & end : "<<et<<endl;
            tt[tmp2] = et-v[tmp2].first;
            wt[tmp2] = tt[tmp2]-v[tmp2].second;
            st = et;
            showqueue(q,p);
        }
        else
        {
            q.pop();
            et = st+tq;
            store[tmp2].second -= tq;
            clk = et;
            searchProcess(st+1,clk);
            q.push(tmp2);
            cout<<"P"<<p[tmp2]<<" start : "<<st<<" & end : "<<et<<endl;
            tt[tmp2] = et-v[tmp2].first;
            wt[tmp2] = tt[tmp2]-v[tmp2].second;

            st = et;
            showqueue(q,p);

        }
    }


    cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnarround-time(s)\n";

    for(int i=0; i<n; i++)
    {
        swt+=wt[i];
        stt+=tt[i];
        cout<<"P"<<p[i]<<"              "<<v[i].first<<"                "<<v[i].second<<"                  "<<wt[i]<<"                 "<<tt[i]<<endl;
    }

    avw= float(swt)/float(n);
    avt = float(stt)/float(n);
cout<<"Average Waiting Time: "<<avw<<endl;
cout<<"Average Turnarround Time: "<<avt<<endl;

}
