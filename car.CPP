#include<iostream>
using namespace std;
struct save
{
int p1,p2,user;
}s[100];
char a[100][100];
class parkcar
{
int t,i,j,l,k,num,temp,count,slotnum,runner;
int m,n;
public:
parkcar()
{
t=0;
}
int park(int ,int );
int remove();
};

int parkcar:: park(int m,int n)
{
if(n*m>t)
{
printf("\e[1;1H\e[2J");
cout<<"Current Slot status"<<'\n';
cout<<"Note: N -> Not occupied"<<'\t'<<"X -> Occupied\n"<<'\n';
count=1;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
cout<<count<<" "<<a[i][j]<<'\t';
count++;
}
cout<<'\n';
}
cout<<"\n\nEnter the slot number where you wish to park you car ";
cin>>slotnum;
runner=slotnum;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{   
    if(runner>0)
    runner--;
    if(runner==0)
    {
        l=i;
        k=j;
        runner --;
    }  
}
}
printf("\e[1;1H\e[2J");
if(l*k>m*n || k>n-1 || l>m-1 || slotnum >count )
cout <<"There doesn't exist such slot";
else if(a[l][k]!='N')
{
cout<<"Sorry.This slot is occupied.Try a different one."<<'\n';
}
else
{
for(i=0;i<m*n;i++)
{
if(s[i].p1=='\0'&&s[i].p2=='\0')
{
num=rand()%999+100;
cout<<"Your user id is: "<<num<<'\n';
s[i].user=num;
a[l][k]='X';
s[i].p1=l;
s[i].p2=k;
cout<<"Your car is parked :)"<<'\n';
t++;
break;
}
}
}
}
else
    cout<<"All slots are full . TRY AGAIN LATER";

return 0;
}



//to remove the car
int parkcar::remove()
{
cout<<"Enter your user id: "<<'\n';
cin>>temp;
if(temp==s[i].user)
{
l=s[i].p1;
k=s[i].p2;
a[l][k]='N';
printf("\e[1;1H\e[2J");
cout<<"Your car is unparked :)"<<'\n'<<"Visit Again!!!";
t--;
}
else
{
cout<<"Oops!Wrong user ID.Try again."<<'\n';
}

return 0;
}
// Main function




int main()
{
parkcar car;
int ch,m,n,i,j;
printf("\e[1;1H\e[2J");
cout<<"Enter the number of slots you have as a multiple of two numbers\n (rows and columns)\n";
cin>>m>>n;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
a[i][j]='N';
}
}
while(1)
{
cout<<"\nWhat do you wish to do?"<<endl;
cout<<"1. Enter  2.Leave  3.exit"<<endl;
cin>>ch;
switch (ch)
{
case 1:car.park(m,n);break;
case 2:car.remove();break;
case 3:exit(0);
default: cout<<"Invalid input";
}
}
return 0;
}