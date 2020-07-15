#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>

struct timeval t1,t2,t3,t4;
using namespace std;
unsigned long long c=0;
void merge(unsigned long long a[], unsigned long long low, unsigned long long high, unsigned long long mid)
{

unsigned long long i, j, k, temp[high-low+1];
i = low;
k = 0;
j = mid + 1;



while (i <= mid && j <= high)
{
if (a[i] < a[j])
{
temp[k] = a[i];
c++;
i++;
}
else
{
temp[k] = a[j];
c++;
j++;
}
k++;
}
 
while (i <= mid)
{
temp[k] = a[i];

k++;
i++;
}
 

while (j <= high)
{
temp[k] = a[j];

k++;
j++;
}

 

for (i = low; i <= high; i++)
{
a[i] = temp[i-low];
}
}
 

void mergesort(unsigned long long a[], unsigned long long low, unsigned long long high)
{
unsigned long long mid;
if (low < high)
{
mid=(low+high)/2;

mergesort(a, low, mid);
mergesort(a, mid+1, high);
 

merge(a, low, high, mid);
}
}
 
int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end, start1, end1;
	 
srand((unsigned)time(0));
unsigned long long n, i;
cout<<"\nEnter the number of data element to be sorted: ";
cin>>n;
 
unsigned long long b[n],d[n];
for(i = 0; i < n; i++)
{

b[i]=((rand()%10000)+i+5);
}

gettimeofday (&t1,NULL);
start = std::chrono::system_clock::now();
mergesort(b, 0, n-1);
end = std::chrono::system_clock::now();
gettimeofday (&t2,NULL);
cout<<"\nSorted list ";
/*for (i = 0; i < n; i++)
{     
	 cout<<" "<<b[i];

}   
*/

for(unsigned long int m=0;m<n;m++)
    {
        d[m]=b[(n-1)-m];
        
    }

gettimeofday (&t3,NULL);
start1 = std::chrono::system_clock::now();
mergesort(b, 0, n-1);
end1 = std::chrono::system_clock::now();
gettimeofday (&t4,NULL);


std::chrono::duration<double>elapsed_seconds=end-start;
std::chrono::duration<double>elapsed_seconds1=end1-start1;

std::cout<<"\n\nTime taken for mergesort is (seconds using chrono) :"<<elapsed_seconds.count();
std::cout<<"\n\nTime taken for mergesort is (microseconds using chrono) :"<<((elapsed_seconds.count())*1000000);

cout<<"\n\nTime taken for mergesort is (seconds using timeval) :"<<abs(float(t1.tv_sec-t2.tv_sec));
cout<<"\n\nTime taken for mergesort is (microseconds using timeval) :"<<abs(float(t1.tv_usec-t2.tv_usec));


std::cout<<"\n\nTime taken for mergesort in worst case is (seconds using chrono) :"<<elapsed_seconds1.count();
std::cout<<"\n\nTime taken for mergesort in worst case is (microseconds using chrono) :"<<((elapsed_seconds1.count())*1000000);

cout<<"\n\nTime taken for mergesort in worst case is (seconds using timeval) :"<<abs(float(t4.tv_sec-t3.tv_sec));
cout<<"\n\nTime taken for mergesort in worst case is (microseconds using timeval) :"<<abs(float(t4.tv_usec-t3.tv_usec));


cout<<"\n\nThe number of data excahnges are :"<<c;

 
return 0;
}
