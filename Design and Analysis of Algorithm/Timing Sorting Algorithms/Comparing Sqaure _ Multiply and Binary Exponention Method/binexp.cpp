#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
int counterx=0;
int countery=0;
int counterz=0;

unsigned long long int simple(unsigned long long int x,unsigned long long int y)
{
	unsigned long long int ans=1;
	for(unsigned long long int i=0;i<y;i++)
	{
		ans=ans*x;
		counterz++;
	}
	
	return ans;
}

unsigned long long int binexp(unsigned long long int x, unsigned long long int y)
{  
unsigned long long int ans=1;
unsigned long long int quotient=1, reminder;
while (quotient!=0) 
{
quotient=y/2;
if (y%2==0)
    reminder=0;

else reminder=1;
 
 
           
if(reminder==1)
	{
    ans=ans*x;
    counterx++;
	}
 
 
       
y=quotient;


x=x*x;
counterx++;
}
return ans;
}

int squaremul(unsigned long long int x,unsigned long long int y)
{
    unsigned long long int final=1;
    while(y>0)
    {
        if(y%2!=0)
        {
            final=final*x;
            countery++;
        }
        
        y=y/2;
        x=x*x;
        countery++;
    }   
        return final;
    
}

int main()
{
	
	std::chrono::time_point<std::chrono::system_clock> start, end, start1, end1,start2, end2
	;
    unsigned long long int a,b;
    cout<<"Enter base : ";
    cin>>a;
    cout<<"\nEnter exponent : ";
    cin>>b;
   start = std::chrono::system_clock::now();
   cout<<"\n"<<binexp(a,b);
   end = std::chrono::system_clock::now();
   
   start1 = std::chrono::system_clock::now();
   cout<<"\n"<<squaremul(a,b);
   end1 = std::chrono::system_clock::now();
   
   start2 = std::chrono::system_clock::now();
   cout<<"\n"<<simple(a,b);
   end2 = std::chrono::system_clock::now();
   
   
   
   std::chrono::duration<double>elapsed_seconds=end-start;
   std::chrono::duration<double>elapsed_seconds1=end1-start1;
   std::chrono::duration<double>elapsed_seconds2=end2-start2;
   
   cout<<"\nNo of multiplication in Binexp is :"<<countery;
   cout<<"\nNo of multiplication in Sqmul is :"<<counterx;
   cout<<"\nNo of multiplication in Simple is :"<<counterz;
   
   std::cout<<"\n\nTime taken for Binexp is (microseconds using chrono) :"<<((elapsed_seconds.count())*1000000);
   std::cout<<"\n\nTime taken for SqMulis (microseconds using chrono) :"<<((elapsed_seconds1.count())*1000000);
   std::cout<<"\n\nTime taken for Simple is (microseconds using chrono) :"<<((elapsed_seconds2.count())*1000000);
   
   
    
    return 0;
}
