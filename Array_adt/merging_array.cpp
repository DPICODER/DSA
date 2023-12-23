#include<iostream>

using namespace std;

struct array{
	int arr[10];
	int size;
	int length;
};

void display(struct array a){
	int i= 0;
	for(i = 0 ; i < a.length ; i++){
		cout<<" | "<<a.arr[i]<<" | ";
	}
}

struct array* merge(struct array *arr1 , struct array *arr2){
	int i ,j , k;

	i=j=k=0;

	struct array *arr3 =(struct array *)malloc(sizeof(struct array));


	while(i < arr1->length && j < arr2->length){
		if(arr1->arr[i] < arr2->arr[j])
			arr3->arr[k++]=arr1->arr[i++];
		else
			arr3->arr[k++]=arr2->arr[j++];
	}
	for(;i<arr1->length;i++)
		arr3->arr[k++]=arr1->arr[i];
	for(;j<arr1->length;j++)
		arr3->arr[k++]=arr2->arr[j];
	
	arr3->length=arr1->length+arr2->length;

	arr3->size =10;

	return arr3;
}

int main(){

struct array arr1= {{1,4,7,2,5},10,5};
struct array arr2= {{8,9,6,3,0},10,5};
struct array *arr3;

arr3 = merge(&arr1,&arr2);

display(*arr3);


}