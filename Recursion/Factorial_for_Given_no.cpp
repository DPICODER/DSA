#include<stdio.h>
// yo
int fact_rec(int n){
   static int cnt = 5;
    int fact;
  if(n==0){
    return(1);
  }
  else{
    return fact_rec(n-1)*n;
  }
}

int fact_looped(int n){
  
  printf("\n\n\nFactorial with Loop : ");
  
  int fact = 1 , i = 1 ;
    for(i = 1 ; i <=n ; i++){
      fact = fact * i;
        printf("\n Internal Loop Iter : %d",fact);
    }
    printf("\n\n Final Factorial Number : %d\n\n",fact);
    return 0;
}

int main(){
  int n = 5;
//  int cnt = 0;
fact_rec(n);
//  fact_looped(n);
int res = fact_rec(n);
  printf("%d",res);
}
