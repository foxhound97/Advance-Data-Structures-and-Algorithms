#include<iostream>
#include<cstring>
using namespace std;

struct billboards{
  int pos; //position of billboard measured in miles from one end of road
  int rev; //revenue from the billboard placed at position pos
};

typedef struct billboards Billboards;

int max(int a, int b){
  return((a>b)?a:b);
}

int maxrevenue(Billboards arr[], int n, int len, int t){
  int maxrev[len+1];
  memset(maxrev,0,sizeof(maxrev));
  int posofBB=0; //index to the position of next billboard
  for(int m=1;m<=len;m++)
  {
    if(posofBB < n){ // position of current billboard is within length of highway
      if(arr[posofBB].pos != m){
        maxrev[m] = maxrev[m-1];
      }
      else{
        if(m < t){ //current billboard position is within the t
          maxrev[m] = max(maxrev[m-1], arr[posofBB].rev);
        }
        else{ //remove previously placed billboard within t
          maxrev[m] = max(maxrev[m-t-1] + arr[posofBB].rev, maxrev[m-1]);
        }
        posofBB++; //process next billboard
      }
    }
    else{ //no more billboards to place
      maxrev[m] = maxrev[m-1];
    }
  }
  return maxrev[len];
}

int main()
{
  int len,n,t;
  cout << "Enter the length of highway in miles : ";
  cin>>len;
  cout << "Enter the number of billboards to be placed on the heighway : ";
  cin>>n;
  cout << "Enter the t within which no two billboards can be placed : ";
  cin>>t;
  Billboards arr[n]; //array to store all the positions and corresponding revenue for each billboard
  for(int i=0;i<n;i++){
    cout << "Enter the position and associated revenue for billboard : ";
    cin>>arr[i].pos>>arr[i].rev;
  }
  cout << "Maximum Revenue : " << maxrevenue(arr,n,len,t) << "\n";
  return 0;
}
