#include<stdio.h>

void funB(int x);

void funA(int x){
  if(x>0){
  printf("The Fun A val : %d\n",x);
  funB(x/2);  
  }
}
void funB(int x){
  if(x>0){
    printf("The Fun B val : %d\n",x);
    funA(x-2);
  }
}

//Indirect Recursions Contains Recurive Function Calls Between 2 or More Functions Passing Values
//in Between those Functions

int main (){
  funA(28);
}
