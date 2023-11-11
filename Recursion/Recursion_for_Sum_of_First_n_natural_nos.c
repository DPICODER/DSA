#include<stdio.h>

int sum(int n){
  if(n==0){
    return 0;
  }
  return(sum(n-1)+n);
}

int Iter_sum(int n){
  int i,s=0;
  for(i = 0 ; i <=n ; i++){
    s = s+i;
  }
  return s;
}

int main(){
  int n = 5;
  int r = sum(n);
  printf("%d\n",r);
    
  int i = Iter_sum(n);
  printf("%d\n",i);
}
