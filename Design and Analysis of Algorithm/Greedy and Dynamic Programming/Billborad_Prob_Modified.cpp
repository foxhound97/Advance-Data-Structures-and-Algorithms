#include <bits/stdc++.h> 
using namespace std; 
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include<math.h>
//header files for time utilities
//header files chrono to check time of program
using namespace std::chrono;
// billboad with distance and revenue is given 
struct billboard_property 
{ 
	int distance, revenue; 
}; 

// An utility function which is used for sort
//here we sort it on the basis of maximum revenue first

bool activityCompare(billboard_property s1, billboard_property s2) 
{ 
	return (s1.revenue > s2.revenue); 
} 
void fun_to_check_billboard(billboard_property arr[], int n) 
{ 
	// Sort billiboards on the basis of maximum revenue
	sort(arr, arr+n, activityCompare); 
cout<<"Enter  t";
int t;//t is 5,i.e the distance between two billiboard is not less or equal to 5
cin>>t;
	//cout << "Following billiboards are selected n"; 

	// The first billiboards with maximum revenue is selected always gets selected 
	int i = 0; 
	//cout << "(" << arr[i].distance << ", " << arr[i].revenue << "), "; 
     int sum=0;
     sum=sum+arr[i].revenue;
	// Consider rest of the billiboards which as distance more than 5 from the previous selected billboards 
	for (int j = 1; j < n; j++) 
	{ 
	// If this activity has more distance thaan //
	//select it
    int g=abs(arr[i].distance-arr[j].distance);
    //cout<<g;
    
	if(g>t) 
	{ 
		//cout << "(" << arr[j].distance<< ", "
			//<< arr[j].revenue << "), "; 

           //total revenue get
            sum=sum+arr[j].revenue;
	      i = j; 
	} 
	} 
    cout<<"Total Revenue "<<sum;
} 

int check_class()
{  // cout<<"Enter the distance between Jammu and Delhi ";
    int n;
    //cin>>n;
   // cout<<"Enter the coverage Distance ";
    int d=0;
    //cin>>d;
    int count1=0;
    int i=2;
   // cout<<"Enter the distance between the perol pump";
    int d1=d;
    while(n>0)
    {int p;
      //  cin>>p;
        
        if(p<=d1)
        {//cout<<"skip at the petrol pump number:"<<i<<endl;
            d1=d1-p;
        }
        else
        {
           // cout<<"Stop at the petrol pump number:"<<i<<endl;
            count1++;
            d1=d;
        }
        n=n-p;
        i=i+1;
    }
   // cout<<"Total stopage is"<<count1;
}
 //count total minimum number of classroom present
// cout <<"Number of classroom Required"<<count_classroom_number;
// #include <bits/stdc++.h>
// using namespace std;
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <sys/time.h>
// #include <chrono>
// #include <iostream>
// #include <iterator> // for iterators
// #include <vector> 
int check_class1()
{  // cout<<"Enter the distance between Jammu and Delhi ";
    int n;
    //cin>>n;
   // cout<<"Enter the coverage Distance ";
    int d=0;
    //cin>>d;
    int count1=0;
    int i=2;
   // cout<<"Enter the distance between the perol pump";
    int d1=d;
    while(n>0)
    {int p;
      //  cin>>p;
        
        if(p<=d1)
        {//cout<<"skip at the petrol pump number:"<<i<<endl;
            d1=d1-p;
        }
        else
        {
           // cout<<"Stop at the petrol pump number:"<<i<<endl;
            count1++;
            d1=d;
        }
        n=n-p;
        i=i+1;
    }
   // cout<<"Total stopage is"<<count1;
}




int main() 
{ int n;
 cout<<"Enter Total Number of billboards to be scheduled ";
	cin>>n;
	 billboard_property arr[n] ;
	 cout<<"\n1.First Enter the distance\n2.Seconds Enter the revenue\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].distance;
		cin>>arr[i].revenue;
	}
	//high_resolution_clock::time_point start1 = high_resolution_clock::now();
	fun_to_check_billboard(arr, n); 
    return 0;
}
