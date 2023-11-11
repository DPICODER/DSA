#include<stdio.h>

double Taylor_Series (int x,int y){
  static double p=1,f=1;
    double r;
  if(y==0){
    return 1;
  }
  r=Taylor_Series(x,y-1);
  p=p*x;
  f=f*y;
  return r+p/f;
}

//This Version of Taylor Series Has Time Complexity of O(n^2);

//In order to Overcome This Time complexity Issue The Taylor Series is implemented using Horners rule 


double Taylor_Series_Horner(int x,int y){
  static double s;
  if(y==0){
    return s;
  }
  s=1+x*s/y;
  return Taylor_Series_Horner(x,y-1);
}

double Taylor_Series_Iter(int x,int y){
  double s = 1;
  int i;
  double num = 1, den = 1;
    for(i = 1 ; i<=y ; i++){
      num*=x;
      den*=i;
      s+=num/den;
    } 
    return s;
}


int main(){
printf("The e^x Values Taylor_Series_Iter :%lf \n : ",Taylor_Series_Iter(4,15));
  printf("The e^x Values Taylor_Series :%lf \n : ",Taylor_Series(4,15));
  printf("The e^x Values Taylor_Series_Horner :%lf \n : ",Taylor_Series_Horner(4,15));
  return 0;
  
}
