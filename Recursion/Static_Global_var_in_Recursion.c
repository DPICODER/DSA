#include<stdio.h>

int function(int n){
  if(n>0){
    printf("\nFunction1 called with n val : %d\n",n);
    return function(n-1)+n;
//    printf("Function Returned with n val : %d\n",n);
//    It Doesn't Reach here 
  }
  return 0;
}
int function2(int n){
//Here We are including a static Variable Which will be Static Through out The
//Whole Recurion Just By incrementing by 1 for Every Function Call
  static int x = 0;
  if(n>0){
    x++;
     printf("\nFunction2 called with Static X val : %d\n",x);
    return function2(n-1)+x;
  }
  return 0;
}
int main(){
  int a = 5;
  int r = function(a);
  int r1 = function2(a);
  printf("%d\n",r);
  printf("\n%d\n\n",a);
  printf("%d\n",r1);
}
