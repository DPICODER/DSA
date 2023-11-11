#include<stdio.h>
#include<stdlib.h>
int main(){
  int *p,*q;
  int i;
  p = (int *)malloc(5*sizeof(int));
  
   
  for(i = 0 ; i<5 ; i++){
    scanf("%d",&p[i]);
  }
  
  for(i = 0 ; i<5 ; i++){
    printf("%d\t",p[i]);
  }
  
  printf("\n");
  q = (int *)malloc(10*sizeof(int));
  
   
  for(i = 0 ; i<5 ; i++){
   q[i]=p[i];
  }
  
  free(p);
 
  p = q;
  q = NULL;   
  for(i = 0 ; i<10 ; i++){
    printf("%d\t",p[i]);
  }
  free(q);
  return 0;
}
