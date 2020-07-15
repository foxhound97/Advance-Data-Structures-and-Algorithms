#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

unsigned long long markerM=0;
unsigned long long markerA=0;



unsigned long long u=0;


struct node{
	int key;
	struct node *left;
	struct node *right;
};




struct timeval t1,t2,t3,t4,t5,t6,t11,t12,t100,t101;
void modbubblesort(unsigned long long int a[]);
void bubblesort(unsigned long long int a[]);
void insertionsort(unsigned long long int a[]);
void mergesort(unsigned long long a[], unsigned long long low, unsigned long long high);
void merge(unsigned long long a[], unsigned long long low, unsigned long long high, unsigned long long mid);
void fillrandom(unsigned long long int a[]);
void check (unsigned long long int a[]);



struct node* newnode(unsigned long long int key);
struct node* insert(struct node* b,unsigned long long int key);
void myownsort(unsigned long long int f, unsigned long long int x);
void inorder_store(struct node *temp, unsigned long long int x);




unsigned long long int N;



struct node* newnode(unsigned long long int key)
{
	struct node* t=(struct node*)malloc(sizeof(struct node));
	t->key=key;
	t->left=NULL;
	t->right=NULL;
	
	return(t);
}

struct node* insert(struct node* b,unsigned long long int key)
{
	if (b==NULL) return newnode(key);
	
	if(key < b->key)
	{
		b->left=insert(b->left,key);
	}
	else
	b->right=insert(b->right,key);
	
	return b;
}

void myownsort(unsigned long long int f, unsigned long long int x)
{   
    unsigned long long int w[x];
    w[u]=f;
    
    /*cout<<w[u]<<"\n";*/
    u++;
    
}



void inorder_store(struct node *temp, unsigned long long int x) 
{ 
    
   
    if (temp != NULL) 
    { 
       
       
        inorder_store(temp->left, x); 
        myownsort(temp->key, x);
        inorder_store(temp->right,  x); 
        
       
        
      
    
         
        } 
    
    
} 



void modbubblesort(unsigned long long int a[])
{
     unsigned long long int i,j,t,marker;
     for(i=0;i<N;i++)
     { 
		 marker=0;
		 for(j=0;j<((N-i)-1);j++)
		 {
			 if(a[j]>a[j+1])
			 {
			 t=a[j];
			 a[j]=a[j+1];
			 a[j+1]=t;
			 marker++;
			 markerM++;
		     }
		}
		if(marker==0)
		break;
	}
}
     
     
     
     
     
     
     
     
     
void bubblesort(unsigned long long int a[])
{
	
    for (unsigned long long int i=0 ; i<(N-1); i++)
    {
		for (unsigned long long int j=0 ; j<((N-i)-1);j++)
		{
			if (a [j]>a[j +1])
			{
			unsigned long long int tmp=a[j];
			a [j]=a[j+1];
			a [j+1]=tmp ;
			markerA++;

			}
		}
    }
return ;

}

void insertionsort(unsigned long long int a[])
{
    unsigned long long int f,l,key;
    for(f=1;f<N;f++)
    {
        key = a[f];
        l=f-1;
        
        while(l>0 && a[l]>=key)
        {
            a[l+1]=a[l];
            
            l=l-1;
        }
        if(a[l] > key)
        {
			a[l+1] = a[l];
		}
        a[l]=key;

    }

}

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
        
        i++;
    }
    else
    {
        temp[k] = a[j];
        
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

void fillrandom(unsigned long long int a[])
{
    for(unsigned long long int p=0;p<N;p++)
    {
        a[p]=((rand()%1000)+p);
    }
    return ;
}


void check (unsigned long long int a[])
{
    for (unsigned long long int x=0;x<N-1;x++)
    {
    if(a[x]>a[x+1])
    {
        cout<<"sort failed....see iteam number: "<<x;
        return ;
    }
    }
    cout<<"\ncheck pass!";
    
    
}





int main()
{
	
	unsigned long long data;
	
	
    srand((unsigned)time(0)); 
    
     cout<<"ENter size of array:";
    cin>>N;
    
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->key=(rand()%1000);
    
    for(unsigned long long int i=0;i<(N-1);i++)
	{
	    data=((rand()%10000)+i+5);
		
		
		insert(root,data);
	}
	
	gettimeofday(&t100,NULL);
	inorder_store(root,N);
    gettimeofday(&t101,NULL);
    
    
    unsigned long long int a[N];
  
    //time a modbubble short
    
    fillrandom(a);
    gettimeofday(&t11,NULL);
    
    modbubblesort(a);
    gettimeofday(&t12,NULL);
    
    cout<<"\n\nModified Bubblesort time is: "<<abs(t11.tv_usec - t12.tv_usec);
    cout<<"\n\nSwaps in Semi Bubble sort is: "<<markerA;
    check(a);
    
    
    
    //time a bubble short
    
    fillrandom(a);
    gettimeofday(&t1,NULL);
    
    bubblesort(a);
    gettimeofday(&t2,NULL);
    
    cout<<"\n\nBubblesort time is: "<<abs(t1.tv_usec - t2.tv_usec);
    cout<<"\n\nSwaps in Bubble sort is: "<<markerM;
    check(a);
    
    // time an mergesort
    
    fillrandom(a);
    gettimeofday(&t5,NULL);
    
    mergesort(a,0,N-1);
    gettimeofday(&t6,NULL);
    
    cout<<"\n\nMerges sort time is: "<<abs(t6.tv_usec - t5.tv_usec);
    check(a);
    
    //time an insertion short
    
    fillrandom(a);
    gettimeofday(&t3,NULL);
    
    insertionsort(a);
    gettimeofday(&t4,NULL);
    
    cout<<"\nInsertionsort time is:"<<abs(t3.tv_usec - t4.tv_usec);
    check(a);
    
    cout<<"\nMy own sort time is: "<<abs(t101.tv_usec - t100.tv_usec);
    
    return 0;
    
    
    
    
}

