#include <iostream>
#include <chrono>

#include <bits/stdc++.h> 
std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2;
using namespace std;

int brute(int arr[], int n) 
{ 
    int x = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                x++;
    return x; 
} 

int mergesort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size) 
{ 
    int* temp = (int*)malloc(sizeof(int) * array_size); 
    return mergesort(arr, temp, 0, array_size - 1); 
} 

int mergesort(int arr[], int temp[], int left, int right) 
{ 
    int mid, x = 0; 
    if (right > left) { 
        
        mid = (right + left) / 2; 
  
        
        x= mergesort(arr, temp, left, mid); 
        x += mergesort(arr, temp, mid + 1, right); 
  
        
        x += merge(arr, temp, left, mid + 1, right); 
    } 
    return x;
} 

int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    int i, j,k; 
    int x = 0; 
  
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            
            x = x + (mid - i); 
        } 
    } 
  
     
   
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return x; 
} 

int main()
{ 
	int n;
	
	
	cout<<"\nEnter size of array :";
	cin>>n;
	
    int arr[n];
	
	for(int i=0;i<n;i++)
	{
		arr[i]=i+rand()%(i+1);
	}
	start1 = std::chrono::system_clock::now();
    cout<<"number of inversion by brute froce is:"<<brute(arr, n); 
	end1 = std::chrono::system_clock::now();
	
	start2 = std::chrono::system_clock::now();
	cout<<"\nnumber of inversions by merge sort method is: "<< mergeSort(arr, n);
	end2 = std::chrono::system_clock::now();
	
	
	std::chrono::duration<double>elapsed_seconds1=end1-start1;
std::chrono::duration<double>elapsed_seconds2=end2-start2;
	
	std::cout<<"\n\nTime in microseconds for brute force is = \n"<<((elapsed_seconds1.count())*1000000);
std::cout<<"\n\nTime in microseconds for cmerge sort is = \n"<<((elapsed_seconds2.count())*1000000);
    return 0; 
} 
