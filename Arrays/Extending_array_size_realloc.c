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
  
/*  realloc used for Re-allocation of Memory for any Predefined Pointer
      ex we are Incersing the size of the pointer p which was 5 block's of memory in Heap 

  USing realloc we need a new pointer varaible to Perform this 
  Ex : we initializad *ptr and
  used ptr = realloc(p,8);
  
  here p refers to the old pointer and 8 refers to increment the pointer size by 8
  
  so the new p pointer size is 5+8 = 13
*/
  int *ptr;
  
  ptr = realloc (p,8);
  
  printf("Attay pointer size increased");
    
  for(i = 0 ; i<13 ; i++){
    scanf("%d",&p[i]);
  }
  printf("\n");
  for(i = 0 ; i<13 ; i++){
    printf("%d\t",p[i]);
  }
  
  printf("\n");
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
//  q = (int *)malloc(10*sizeof(int));
//  
//   
//  for(i = 0 ; i<5 ; i++){
//   q[i]=p[i];
//  }
//  
//  free(p);
// 
//  p = q;
//  q = NULL;   
//  for(i = 0 ; i<10 ; i++){
//    printf("%d\t",p[i]);
//  }
//  free(q);
  return 0;
}
