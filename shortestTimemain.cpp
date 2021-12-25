#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,st,et,a,b,ct[100],wt[100],tt[100];
    float s1=0, s2=0,avw,avt;
    vector<pair<int,int>>v;
    vector<pair<int,int>>store;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        store.push_back(make_pair(b,a));
    }
    a = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(v[a].first>v[i].first)
        {
            a = i;
        }
    }

    //for the first time arrived process
    if(v[a].second != 1)
    {
        store[a].first = v[a].second - 1;
    }
    else
    {
        store[j].first = 0;
    }

    st = v[a].first;
    et = st+1;


    cout<<"Before sorting : "<<endl;
    cout<<"_______________________________"<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"Arrival Time: "<<store[i].second<<" Burst Time: "<<store[i].first<<endl;
    }

    sort(store.begin(),store.end());
    cout<<"After sorting : "<<endl;
    cout<<"_______________________________"<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"Arrival Time: "<<store[i].second<<" Burst Time: "<<store[i].first<<endl;
    }

    i = 0;

    for(int j = 0 ; j < n ; j++)
    {
//        cout<<store[j].first<<" ";
        if(store[j].first!=0)
        {
            st=et;

            et=st+store[j].first;
            store[j].first = 0;
            if(store[j].second==0){

                wt[j] = st-1-store[j].second;
            }
            else{

              wt[j] = st-0-store[j].second;
            }

        }

        s1+=wt[j];
    }


    avw = s1/n;

cout<<"Average Waiting Time: "<<avw<<endl;

}

