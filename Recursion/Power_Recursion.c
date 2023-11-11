#include<stdio.h>

int powr(int m , int n){
  if(n==0){
    return (1);
  }
  return powr(m,n-1)*m;
}

int main(){
  int m,n;
  printf("\n\nEnter a Number for Finding its Exponent : ");
  scanf("%d",&m);
  printf("\n\nEnter a Number for Range of Power To be Applied : ");
  scanf("%d",&n);
  int res = powr(m,n);
  
  printf("\n\n The Final Exponent Val : %d",res);
}
