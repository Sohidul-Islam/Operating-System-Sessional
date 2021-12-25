#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>store2;

int priority(vector<pair<int,int>>store,int pri[],int s);
int searchprocess(vector<pair<int,int>>store,int pri[],int s);

int main()
{
    int n,i,j,st=0,et=0,a,b,wt[100],temp2,tb=0;
    float s1=0, s2=0,avw,avt;

    vector<pair<int,int>>v;
    vector<pair<int,int>>store;
    cin>>n;
    bool isArrived[n];
    int p[n],pri[n];
    for(i=0; i<n; ++i)
    {
        cin>>a>>b>>pri[i];
        p[i] = i+1;
        isArrived[i] = false;
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
    cout<<"Process  Arrival-time(s)  Burst-time(s)      Priority\n";
     for(i=0; i<n; i++)
    {

        cout<<"P"<<p[i]<<"              "<<store[i].first<<"                "<<store[i].second<<"                "<<pri[i]<<endl;
    }

    cout<<"Grant Chart: "<<endl;
    int clk = 0;
    while(i<=25)
    {


        i=i+1;

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

        cout<<"Return "<<a<<endl;
        return a;
    }
}

int searchprocess(vector<pair<int,int>>store,int pri[],int s){

for(int i = 0; i<store.size() ; i++){
        if(store[i].first==s){
        store2.push_back(make_pair(store[i].first,i));
        }
}
}
