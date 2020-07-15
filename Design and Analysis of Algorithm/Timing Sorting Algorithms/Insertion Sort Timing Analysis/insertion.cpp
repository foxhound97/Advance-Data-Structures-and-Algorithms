

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <unistd.h>
#include <sys/time.h>

struct timeval t1,t2,t3,t4,t5,t6;



using namespace std;
using namespace std::chrono;


int insertion_sort(int a[], int n)
{   int i,j,key;
	int counter=0;
	

	

    for(i=0;i<n;i++)
    {
        key = a[i];
        j=i-1;
        
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            counter++;
            j--;
        }
        a[j+1]=key;

    }

    
    return (counter);
}

int main()
{
	
std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2, start3, end3;

	
	int g;
	cout<<"enter no of elements";
	cin>>g;
	
    srand((unsigned)time(0));
    int k;
    
    int b[g],c[g],d[g];
    int m;
    
    
    for(k=0;k<g;k++)
    {
        b[k]=((rand()%10000)+k+5);
        
    }
    
    gettimeofday (&t1,NULL);
    start1 = std::chrono::system_clock::now();
    int r = insertion_sort(b,g);
    end1 = std::chrono::system_clock::now();
    gettimeofday (&t2,NULL);
    
    
    /*cout<<"\n Random sorted array is: \t";
    
    for(int p=0;p<1000;p++)
    {
        cout<<"\n"<<b[p];
    }
    */
    cout<<"\n\nNo of swaps for average case are = "<<r<<endl;
    
    
    /*cout<<"\n Best case sorted array is: \t";*/
    for(int l=0;l<g;l++)
    {
        c[l]=b[l];
    }
    gettimeofday (&t3,NULL);
    start2 = std::chrono::system_clock::now();
    int q=insertion_sort(c,g);
    end2 = std::chrono::system_clock::now();
    gettimeofday (&t4,NULL);
    
    /*for(int y=0;y<1000;y++)
    {
        cout<<"\n"<<c[y];
    }*/
    cout<<"\n\nNo of swaps for best case are = "<<q<<endl;
    
    
    /*cout<<"\n Worst case of sorted array is: ";*/
    
   
    for(m=0;m<g;m++)
    {
        d[m]=b[(g-1)-m];
        
    }
    
    gettimeofday (&t5,NULL);
    start3 = std::chrono::system_clock::now();
    int z=insertion_sort(d,g);
    end3 = std::chrono::system_clock::now();
    gettimeofday (&t6,NULL);
    /*for(int x=0;x<1000;x++)
    {
        cout<<"\n"<<d[x];
    }*/
    cout<<"\n\nNo of Swaps for worst case are = "<<z<<endl;
    
    std::chrono::duration<double>elapsed_seconds1=end1-start1;
    std::chrono::duration<double>elapsed_seconds2=end2-start2;
    std::chrono::duration<double>elapsed_seconds3=end3-start3;
    
    std::cout<<"\n\nTime in seconds for average case is (chrono) = "<<elapsed_seconds1.count();
    std::cout<<"\n\nTime in seconds for best case is (chrono) = "<<elapsed_seconds2.count();
    std::cout<<"\n\nTime in seconds for worst case is (chrono) = "<<elapsed_seconds3.count();
    
    std::cout<<"\n\nTime in microseconds for average case is (chrono)= "<<((elapsed_seconds1.count())*1000000);
    std::cout<<"\n\nTime in microseconds for best case is (chrono)= "<<((elapsed_seconds2.count())*1000000);
    std::cout<<"\n\nTime in microseconds for worst case is (chrono)= "<<((elapsed_seconds3.count())*1000000);
    
    cout<<"\n\nTime in seconds for average case is (timeval) = "<<abs(float(t2.tv_sec-t1.tv_sec));
    cout<<"\n\nTime in seconds for best case is (timeval) ="<<abs(float(t4.tv_sec-t3.tv_sec));
    cout<<"\n\nTime in seconds for worst case is (timeval) ="<<abs(float(t6.tv_sec-t5.tv_sec));
    
    cout<<"\n\nTime in microseconds for average case is (timeval) = "<<abs(float(t2.tv_usec-t1.tv_usec));
    cout<<"\n\nTime in microseconds for best case is (timeval) ="<<abs(float(t4.tv_usec-t3.tv_usec));
    cout<<"\n\nTime in microseconds for worst case is (timeval) ="<<abs(float(t6.tv_usec-t5.tv_usec));
    
    
          
   
    

    
    return 0;
    
}
