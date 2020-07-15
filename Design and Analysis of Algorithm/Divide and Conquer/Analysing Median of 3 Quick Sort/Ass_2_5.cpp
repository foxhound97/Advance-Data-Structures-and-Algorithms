
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <chrono>

std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2;

using namespace std; 
int a[3];
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
	    
	    arr[y]=((rand()/10000)+y);
	}
	
    a[0]=arr[0];
    a[1]=arr[512];
    a[2]=arr[1023];
    
    quickSort(a,0,(sizeof(a)/4));
    for(int x=0;x<(sizeof(arr)/4);x++)
    {
        if(a[1]==arr[x])
        {
            swap(arr[x],arr[1023]);
            break;
        }
    }
    
    
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    start1 = std::chrono::system_clock::now();
	quickSort(arr, 0, 1023); 
	end1 = std::chrono::system_clock::now();
	
	std::chrono::duration<double>elapsed_seconds1=end1-start1;
	
	
	
	std::cout<<"\n\nTime in microseconds for MID 3 Quick Sort is = \n"<<((elapsed_seconds1.count())*1000000);
	return 0; 
} 


