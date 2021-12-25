#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
using namespace std;
int main()
{
    int n,nr,rp;

    cout<<"Enter The Number of process: "<<endl;
    cin>>n;
    cout<<"Enter The Number of Resources: "<<endl;
    cin>>nr;
    bool hasProcessed[n] = {false};
    rp=n;
    int p[n],alo[n][nr],mn[n][nr],av[n][nr],rn[n][nr],safe[n],totalRes[nr],sum[nr]= {0,0,0};
    for(int i = 0 ; i<nr ; i++)
    {
        cin>>totalRes[i];
    }

    for(int i =0 ; i < n ; i++)
    {
        p[i] = i+1;
        cout<<"For Process: "<<p[i]<<" Allocation"<<endl;

        for(int j = 0; j < nr ; j++)
        {
            cin>>alo[i][j];
            sum[j]+=alo[i][j];
//            cout<<"Sum of "<<j<<" "<<sum[j]<<endl;
            av[i][j] = 0;

        }
        cout<<"and Max Need"<<endl;
        for(int j = 0; j < nr ; j++)
        {
            cin>>mn[i][j];
        }

        for(int j = 0; j < nr ; j++)
        {
            rn[i][j] = mn[i][j]-alo[i][j];
        }
    }
    cout<<"total allocation: "<<endl;
    for(int i = 0 ; i < nr ; i++)
    {
        av[0][i] =  totalRes[i]-sum[i];
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    cout<<"Process\t\tAllocation\tMax Need\tAvailable\tRemaining Need"<<endl;
    for(int i =0 ; i < n ; i++)
    {
        cout<<"p"<<p[i]<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<alo[i][j];
            if(j!=nr-1)
                cout<<" ";
        }
        cout<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<mn[i][j];
            if(j!=nr-1)
                cout<<" ";
        }
        cout<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<av[i][j];
            if(j!=nr-1)
                cout<<" ";
        }
        cout<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<rn[i][j];
            if(j!=nr-1)
                cout<<" ";
        }

        cout<<endl;

    }

    int tmp = 0,j=0,ac = 0 ;

    while(rp>0)
    {
        for(int i =0; i < n; i++)
        {
            ac = 0;
            for(int k = 0 ; k < nr ; k++)
            {
                if(rn[i][k]<=av[tmp][k])
                {
                    ac++;
                }


            }

            if(hasProcessed[i]!=true && ac==nr)
            {
                hasProcessed[i] = true;

                rp--;
                tmp++;
                for(int l = 0 ; l < nr ; l++)
                {
                    av[tmp][l] = av[tmp-1][l]+alo[i][l];
                }
                safe[j] = p[i];
                cout<<"p"<<safe[j]<<" is safe"<<endl;
                j++;
                ac = 0;
            }


        }


    }

    cout<<"Process\t\tAllocation\tMax Need\tAvailable\tRemaining Need"<<endl;
    for(int i =0 ; i < n ; i++)
    {
        cout<<"p"<<p[i]<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<alo[i][j];
            if(j!=nr-1)
                cout<<" ";
        }
        cout<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<mn[i][j];
            if(j!=nr-1)
                cout<<" ";
        }
        cout<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<av[i][j];
            if(j!=nr-1)
                cout<<" ";
        }
        cout<<"\t\t";
        for(int j = 0; j < nr ; j++)
        {
            cout<<rn[i][j];
            if(j!=nr-1)
                cout<<" ";
        }

        cout<<endl;

    }
    cout<<"Safe Sequence Process: "<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"[p"<<safe[i]<<"]";
    }
    return 0;

}
