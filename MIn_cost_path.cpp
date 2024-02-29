#include<iostream>
#include<vector>
using namespace std;


int find_min_cost(vector<vector<int>>&A,int i,int j,int n,int m) {
    if(i==n-1&&j==m-1) {
        return A[i][j];
    }

   if(i>=n || j>=m) {
    return INT_MAX;
   }
    int x = find_min_cost(A,i,j+1,n,m);
    int y = find_min_cost(A,i+1,j,n,m);
    int z = find_min_cost(A,i+1,j+1,n,m);

    int ans = min(x,min(y,z)) + A[i][j];
    return ans;

}

int  main(){
    cout<< "Enter the size of matrix"<<endl;
   int n,m;
   cin>>n>>m;

  cout<< "Enter the matrix"<<endl;
   vector<vector<int>> A(3,vector<int>(4) );
   for(int i=0  ; i< n;i++){
     for(int j=0;j<m;j++){
        cin>>A[i][j] ;
     }
   }

   int ans = find_min_cost( A,0,0,n,m);

 cout<< "The total cost of going from (0,0) to (n-1,m-1) is : " ;
cout<<ans;

}
