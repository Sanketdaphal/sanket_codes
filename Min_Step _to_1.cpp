\*in this code i have to find minimum number of steps i need to reach 1 by doing the given three operations.*\

#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
using namespace std;

int find_min_step(int n,int step){
    if(n==1){
        return step;
    }
    if(n==2 || n==3){
        return step+1;
    }

   if(n%3==0){
    n = n/3;
    step++;
    find_min_step(n,step);
   }

   if(n%2==0){
    n=n/2;
    step++;
    find_min_step(n,step);
   }

   else{
    n=n-1;
    step++;
    find_min_step(n,step);
   }

}





int find_min_step_2(int n){
           if(n<=1){
            return 0;
           }

           int x = find_min_step_2(n-1);
           int y = INT_MAX;
           if( n %2==0){
               y = find_min_step_2(n/2);
           }
           int z = INT_MAX;

           if(n%3==0){
                z = find_min_step_2(n/3);
           }


           int ans = min(x,min(y,z)) + 1;
           return ans;

}





int find_min_helper(int n,vector<int>&ans){

    if(n<=1){
        return 0;
    }

    if(ans[n] != -1){
        return ans[n];
    }

  int x = find_min_helper(n-1,ans);
  int y = INT_MAX; int z = INT_MAX;

  if(n%2 == 0 ){
    y = find_min_helper(n/2,ans);
  }

  if(n%3 == 0){
    z = find_min_helper(n/3,ans);
  }

  int answer = min( x , min(y,z)) + 1;
  ans[n] = answer;
  return answer;

}


int find_min_step3(int n){
   vector<int> ans(n+1,-1);

   return  find_min_helper(n,ans);


}

int find_min_step4(int n )
{
    int* ans = new int(n+1);
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;

    for(int i=4;i<=n ; i++){
        ans[i] = 1+ans[i-1];

        if( i %2==0) {
            ans[i ] = min(ans[i], 1+ans[i/2]);
        }
        if(i %3==0) {
            ans[i] = min(ans[i] , 1+ans[i/3]);
        }


    }

    return ans[n];



}

int main(){

    int n;
    cin>>n;

    int step = 0;

   int ans = find_min_step(n,step);
   int ans2 = find_min_step_2(n);N
   int ans3 = find_min_step3(n);
   int ans4 = find_min_step4(n);
   cout<<"Ans1 = " <<ans <<endl;
   cout<< "Ans2  = " <<ans2<<endl;
   cout<<"Ans3 = " << ans3<<endl;
   cout<<"Ans4 = " <<ans4<<endl;


}
