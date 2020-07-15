
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

#include <chrono>

std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2;


using namespace std; 
int arr[1024];

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	   int pivot = arr[high];
	
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++) 
	{ 
		
		if (arr[j] < pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 




void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		int pi = partition(arr, low, high); 

		
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 


void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 


int main() 
{ 
    srand((unsigned)time(0)); 
    
    for(int y=0;y<1024;y++)
    {
        arr[y]=((rand()/100000)+y);
    }
    
	
	int x=((rand()/10000000)/100);
	cout<<"\n"<<x;
	
	if(x>0 && x<1023)
	{
	swap(arr[x],arr[1023]);
	
	
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    start1 = std::chrono::system_clock::now();
	quickSort(arr, 0, n - 1); 
	 end1 = std::chrono::system_clock::now();
	
	
	}
	else
	cout<<"Random number dosent convey any index of array ! Try again!";
	
	
	std::chrono::duration<double>elapsed_seconds1=end1-start1;
	std::cout<<"\n\nTime in microseconds for Prob Quick Sort is = \n"<<((elapsed_seconds1.count())*1000000);
	
	return 0; 
} 


