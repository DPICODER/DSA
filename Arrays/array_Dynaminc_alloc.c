#include<stdio.h>
#include<stdlib.h>  


int main(){
  int A[10];
  int n = sizeof(A)/sizeof(int);
  printf("Size of array :%d\n",n);
  int *p;
  p = (int *)malloc(10*sizeof(int));
   int m = sizeof(p)/sizeof(int);
    printf("Size of Dynamic {heap-memory} array :%d\n",m);
    p[0]=4;
    p[1]=5;
    p[2]=7;
    p[3]=2;
    p[4]=1;
    for(int i = 0 ; i < 5 ;i++){
      printf("Ele at index %d is : %d\n",i,p[i]);      
    }
    free(p);
      return 0;
}
