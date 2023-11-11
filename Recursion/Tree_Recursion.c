#include<stdio.h>
int count = 1;
void fun(int n){
  if(n>0){
    
    printf("before Function1 call count val : %d \n",count);
    count++;
    fun(n-1);
    printf("After Function1 Return count val : %d \n\n",count);
    count++;
    printf("Before Function2 Call count val : %d \n",count);
    fun(n-1);
    printf("After Function2 Return count val : %d \n\n\n",count);
    
  }
}

int main(){
  fun(3);
}
