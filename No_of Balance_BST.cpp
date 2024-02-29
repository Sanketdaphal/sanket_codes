#include<iostream>
#include<cmath>
#include<vector> 
using  namespace std;

int count_bst(int n){
    if(n<=1){
        return 1;
    }
int mod = (int) (pow(10,9))+7;
  int x = count_bst(n-1);
  int y = count_bst(n-2);

  int ans = (1LL * x * x + 2LL * x * y) % ((int)1e9 + 7);
  return ans;
  //return ans1*ans1+2*ans1*ans2;

}

int count_bst_helper(int n,vector<int>&ans){
                      if(n<=1){
                                       return 1;
                                }
       if(ans[n] != -1){
        return ans[n];
       }
       int x = count_bst_helper(n-1,ans);
       int y = count_bst_helper(n-2,ans);

       ans[n] = (1LL * x * x + 2LL * x * y) % ((int)1e9 + 7);

        return ans[n];


}



int count_bst_1(int n){
   vector<int> ans(n+1,-1);
    return count_bst_helper(n,ans);

}


int count_bst_dp(int n){
   vector<int> ans(n+1,-1);

     ans[0] = 1;
     ans[1] = 1;
     for(int i = 2; i <= n; i++){
        int x = ans[i-1];
        int y = ans[i-2];
        ans[i] =  (1LL * x * x + 2LL * x * y) % ((int)1e9 + 7);
     }

  return ans[n];


}
int main(){
  int n;
  cin>>n;

  int ans = count_bst(n);
  cout<<ans<<endl;
  int ans2 = count_bst_1(n);
  cout<<ans2<<endl;
  int ans3 = count_bst_dp(n);
  cout<<ans3<<endl;

}
