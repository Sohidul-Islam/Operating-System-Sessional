#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> index[100];
    int mb[100]= {0},count,i,j,k=0,in,nb,b;
    char ch;


do_again:
    {
        cout<<"Enter the index block: "<<endl;
        cin>>in;
        if(mb[in]==0)
        {
            cout<<"Enter the number of blocks and the number of files needed for "<<in<<" the index:"<<endl;
            cin>>nb;

        }
        else
        {
            cout<<in<<" is already allocated"<<endl;
            goto do_again;
        }
    }

    for(i=0; i<nb; i++)
    {
        cin>>b;
        index[in].push_back(b);
    }
    count=0;
    k = 0;

    mb[in]=1;
    for(i=0; i<nb; i++)
    {
        if(mb[index[in][i]]==0)
        {
            for(int j = 0 ; j < nb; j++)
            {
                if(index[in][j] == index[in][j])
                {
                    k++;
                }
            }
            if(k!=0)
            {
                ++count;
            }
            else
            {
                break;
            }


        }
    }


    if(count==nb)
    {
        cout<<"Allocated"<<endl<<"File indexed"<<endl;

        for(i=0; i<index[in].size(); i++)
        {
            if(mb[index[in][i]]==0)
            {
                mb[index[in][i]] = 1;

                cout<<in<<"------>"<<index[in][i]<<" : "<<mb[index[in][i]]<<endl;
            }
        }

    }
    else
    {
        cout<<"Index Already Allocated"<<endl;
        mb[in]=0;
        goto do_again;
    }

    cout<<"Do you want to enter more? (y/n): ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        goto do_again;
    }
    else
    {
        exit(0);
    }

}
