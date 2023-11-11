#include<stdio.h>

void fun(int n){
    if(n>0){
//Descending here Printing happens while Returning


//    printf("\nFunction CALLED with Param : %d  \n",n-1);
//    fun(n-1);    
//    printf("%d\n",n);
//    printf("\nFunction Returned With param : %d \n",n);


//Ascending here Printing happens while calling
    printf("%d\n",n);
    printf("\nFunction CALLED with Param : %d  \n",n-1);
    fun(n-1);    
    printf("\nFunction Returned With param : %d \n",n);

}

}
    

int main(){
    int x = 3;
    fun(x);
}
