


#include <iostream>

using namespace std;


int sq_mul(int base, int power)
{  
int ans=1;
int quotient=1, reminder;
while (quotient!=0) 
{
quotient=power/2;
if (power%2==0)
    reminder=0;

else reminder=1;
 
 
           
if(reminder==1)
    ans=ans*base;
 
 
       
power=quotient;


base=base*base;
}
return ans;
}


int main() 
{
int base,power,ans=1;
cout<<"Enter the base:";

cin>>base;

cout<<"\nEnter the power:";


cin>>power;
	
       
     
ans=sq_mul(base,power);
      
cout<<"\nAns: "<<ans;

return 0;
}



