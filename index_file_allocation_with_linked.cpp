#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> index[100];
    int mb[100]= {0},count,i,j,k,in,nb,b;
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
    mb[in]=1;



    cout<<"Allocated"<<endl<<"File indexed"<<endl;

    for(i=0; i<index[in].size(); i++)
    {
        if(mb[index[in][i]]==0)
        {
            mb[index[in][i]] = 1;

            cout<<in<<"------>"<<index[in][i]<<" : "<<mb[index[in][i]]<<endl;
        }
        else
        {
//            index[in].push_back((index[in][i]+1));
                 cout<<index[in][i]<<" Block is already allocated "<<endl;
                index[in][i] = index[in][i]+1;
                i--;



        }
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
