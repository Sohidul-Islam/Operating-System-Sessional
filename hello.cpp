#include<bits/stdc++.h>
using namespace std;
int main(){
int n , p , c, r,t,count;
cout<<"Enter Amount"<<endl;
cin>>n;
count=n;
p = n;

while(n>=3){
    r = n%3;
    n= n/3;
    count+=n;
   n = n+r;
}

cout<<count;

}
