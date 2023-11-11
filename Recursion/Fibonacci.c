#include<stdio.h>

int fibonacci_regular(int n){
  int t0 = 0,t1=1 , s = 0 , i;
  if(n<=1) return n;
  
  for(i=2 ; i<=n ; i++){
    s = t0 + t1;
    t0 = t1; 
    t1 = s;
  }
  return s;
}


int fibonacci_recursive(int n){
  if(n<=1) return n;
  return fibonacci_recursive(n-2)+fibonacci_recursive(n-1);
}

int F[10];

//The Below Recursive Funtion Uses Memoization in Order to Reduce The Redundant Funtion Calls to Get The Same Parameter's.

int fibonacci_recursive_memoization(int n){
  if(n<=1){
    F[n]=n;
    return n;
  }
  else{
    if(F[n-2]==-1)
      F[n-2]=fibonacci_recursive_memoization(n-2);
    if(F[n-1]==-1)
      F[n-1]=fibonacci_recursive_memoization(n-1);
    F[n]=F[n-2]+F[n-1];  
    return F[n-2]+F[n-1];
  }
}

int main(){
  int i;
  
  for(i = 0 ; i < 10 ; i++){
    F[i]=-1;
  }
  
  int n = 6;
  printf(":  %d ",fibonacci_regular(n));
  printf(":  %d ",fibonacci_recursive(n));
   printf(":  %d ",fibonacci_recursive_memoization(n));
}
