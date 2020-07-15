
#include <bits/stdc++.h> 
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std; 

int countl=0;
int counth=0;

std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2;

int partition_l(int a[], int low, int high) 
{ 
	int pivot = a[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than or 
		// equal to pivot 
		if (a[j] <= pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(a[i], a[j]); 
			countl++;
		} 
	} 
	swap(a[i + 1], a[high]); 
	return (i + 1); 
} 

int partition_h(int b[], int low, int high) 
{ 
	int pivot = b[low]; 
	int i = low - 1, j = high + 1; 

	while (true) 
	{ 
		// Find leftmost element greater than 
		// or equal to pivot 
		do
		{ 
			i++; 
			
		} while (b[i] < pivot); 

		// Find rightmost element smaller than 
		// or equal to pivot 
		do
		{ 
			j--; 
			
		} while (b[j] > pivot); 

		// If two pointers met. 
		if (i >= j) 
			return j; 

		swap(b[i], b[j]); 
		counth++;
	} 
} 


void quickSort_l(int a[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition_l(a, low, high); 
		

		// Separately sort elements before 
		// partition and after partition 
		quickSort_l(a, low, pi - 1); 
		quickSort_l(a, pi + 1, high); 
	} 
} 

void quickSort_h(int b[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition_h(b, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort_h(b, low, pi); 
		quickSort_h(b, pi + 1, high); 
	} 
} 


int main() 

{ 
	int n;
	
	cout<<"Enter vector size:";
	cin>>n;
	
	int a[n];
int b[n];
	
    
    srand((unsigned)time(0));
    
	for(int x=0;x<n;x++)
	{
	    a[x]=((rand()/1000000)+x);
	    b[x]=a[x];
	    
	}
	
	
	 start1 = std::chrono::system_clock::now();
	quickSort_l(a, 0, n-1); 
	end1 = std::chrono::system_clock::now();
	
	start2 = std::chrono::system_clock::now();
	quickSort_h(b, 0, n-1); 
	end2 = std::chrono::system_clock::now();
	
	std::chrono::duration<double>elapsed_seconds1=end1-start1;
std::chrono::duration<double>elapsed_seconds2=end2-start2;

std::cout<<"\n\nTime in microseconds for lumuto is = \n"<<((elapsed_seconds1.count())*1000000);
std::cout<<"\n\nTime in microseconds for hoare is = \n"<<((elapsed_seconds2.count())*1000000);
	 
	cout<<"\n"<<"swaps in lomuto scheme:"<<countl;
	cout<<"\n"<<"swaps in hoare scheme:"<<counth;
	return 0; 
} 

