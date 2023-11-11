#include<stdio.h>
#include<stdlib.h>
int fact(int n){
  if(n==0)return 1;
  return fact(n-1)*n;
}

int NCR(int x , int y){
  int numerator , denominator;
  numerator = fact(x);
  denominator = fact(y)*fact(x-y);
  
  return numerator / denominator;
}

int NCR_Recursive(int x,int y){
  if(x==y||y==0)return 1;
  return NCR_Recursive(x-1,y-1)+NCR_Recursive(x-1,y);
}

int funtion(int &x,int c){
  c = c-1; 
if (c == 0) return 1; 
x = x + 1; 
return (f(x,c)*x);
}
int main(){
  int p = 5;
  printf("%d\n",NCR(4,2));
  printf("%d\n",NCR_Recursive(4,2));
  printf("%d\n",funtion(p , &p ));
  return 0;
}
