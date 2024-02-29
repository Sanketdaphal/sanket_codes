#include<iostream>
#include<vector>
#include<algorithm>

 using namespace std;

 int min_count_helper(int n, vector<int>&dp){
  if(n==0) {
    return 0;
  }
  if(n==1){
    return 1;
  }

  if(dp[n] !=-1){
    return dp[n];
  }

  int ans = n;
  for(int i=1; i*i<n;i++){
    ans = min(ans, 1+ min_count_helper(n-i*i,dp));
  }
  dp[n] = ans;
  return ans;


 }

 int min_count(int n){
     vector<int> dp(n+1,-1);

     return min_count_helper(n,dp);

 }

 int main() {

   int n;
   cin>>n;

   int ans = min_count(n);
   cout<<ans;


 }
