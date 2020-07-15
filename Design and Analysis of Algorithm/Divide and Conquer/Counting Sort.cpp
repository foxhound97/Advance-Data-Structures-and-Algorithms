#include <iostream>
#include <ctime>
#include <cstdlib>

#include <chrono>

std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2;



using namespace std;
int k=0;

/*Method to sort the array*/
void Counting_Sort(int A[],int B[],int n)    
{
	int C[k];
	for(int i=0;i<k+1;i++)
	{
		/*It will initialize the C with zero*/
		C[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		/*It will count the occurence of every element x in A 
		and increment it at position x in C*/
		C[A[j]]++;			    
	}
	for(int i=1;i<=k;i++)
	{
		/*It will store the last 
		occurence of the element i */
		C[i]+=C[i-1];            
	}
	for(int j=n;j>=1;j--)
	{
		/*It will place the elements at their 
		respective index*/
		B[C[A[j]]]=A[j];          
		/*It will help if an element occurs 
		more than one time*/
		C[A[j]]=C[A[j]]-1;		  
	}
}
int main()
{
	
	srand((unsigned)time(0));
	
	int n;
	cout<<"Enter the size of the array :";
	cin>>n;
	
	/*A stores the elements input by user */
	/*B stores the sorted sequence of elements*/  	
	int A[n],B[n]; 
	
	for(int i=1;i<=n;i++)        
	{
		A[i]=(rand()/100000);
		if(A[i]>k)
		{
			/*It will modify k if an element 
			occurs whose value is greater than k*/
			k=A[i];              
		}
	}
	
	start1 = std::chrono::system_clock::now();
	Counting_Sort(A,B,n); 
	end1 = std::chrono::system_clock::now(); 
	
	
	std::chrono::duration<double>elapsed_seconds1=end1-start1;
	std::cout<<"\n\nTime in microseconds for Counting Sort is = \n"<<((elapsed_seconds1.count())*1000000);      
	
	
	
	/*It will print the sorted sequence on the 
	console*/ 
	/*for(int i=1;i<=n;i++)       
	{
		cout<<B[i]<<" ";
	}
	
	cout<<endl;*/
	return 0;
}
