#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;



std::chrono::time_point<std::chrono::system_clock> start1, end1, start2, end2;

struct Node
{
  int data;
  Node *left, *right;
};

Node *newNode(int value)
{
  Node *node = (Node*) malloc(sizeof(Node));
  node -> data = value;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}

Node *insertlevelorder(int a[],Node *root,int index,int size)
{

if(size==0)
{
	cout<<"Height is 0";
}

  else
  {
  if(index < size)
  {

     Node *temp = newNode(a[index]);
     root = temp;

     root -> left = insertlevelorder(a,root->left,2*index + 1,size);

     root -> right = insertlevelorder(a,root->right,2*index + 2,size);

  }
  return root;
}

}

int maxdip(Node *root)
{
  if (root == NULL)
  {
	  
    return 0;
  }
  else
  {
    int ldep = maxdip(root -> left);
    int rdep = maxdip(root -> right);

    if (ldep > rdep)
    {
      return (ldep + 1);
    }
    else
    {
      return (rdep + 1);
    }
  }
}




int main() 
{
	
	srand((unsigned)time(0));

  using namespace std::chrono;
  
  int n ;
int a[n];
  cout << "Enter number of elements in Binary Tree: ";
  cin>>n;
  
  

 
  for (int i=0;i<n;i++)
  {
    a[i]=((rand()/100000)+i);
    
   
  }


  Node *root = insertlevelorder(a,root,0,n);


  start2 = std::chrono::system_clock::now();

  int height = maxdip(root);

  end2 = std::chrono::system_clock::now();
  
  std::chrono::duration<double>elapsed_seconds2=end2-start2;

  cout << "\nHeight of Tree :" << height;

  std::cout<<"\n\nTime in microseconds = \n"<<((elapsed_seconds2.count())*1000000);


  



  return 0;
}
