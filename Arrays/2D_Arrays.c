#include<stdio.h>


int main(){
  int Array[3][4] , i , j;
    
    int n = sizeof(Array)/sizeof(int);
    
    printf("The size of Array is %d",n);
    
        printf("Enter Elemnets in Array Are : \n");
    for(i = 0 ; i < 3 ; i++){
      for(j = 0; j < 4 ; j++){
        scanf("%d",&Array[i][j]);
      }
    }
    
    printf("Elemnets in Array Are : \n");
    for(i = 0 ; i < 3 ; i++){
    printf("\n");
      for(j = 0; j < 4 ; j++){
        printf("%d",Array[i][j]);
      }
    }
}
