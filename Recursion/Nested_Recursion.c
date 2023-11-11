#include<stdio.h>

int fun(int n){

  if(n>100){
  return n-10;
  }
  return fun(fun(n+11));
}

int main(){
  int x;
  x = fun(99);
  printf("%d\n ",x);
  return 0;
}
