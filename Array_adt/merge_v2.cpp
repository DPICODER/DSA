#include<iostream>

using namespace std;

struct array {
	int A[10];
	int length;
	int size;
};

void display(struct array a){
	for (int i = 0; i < a.length; i++)
	{
		cout<<" | "<<a.A[i]<<" | ";
	}
}

struct array* merge(struct array *a1 , struct array *a2){
	int i, j ,k;
	i = j = k =0;

	struct array *a3 = (struct array *) malloc(sizeof(struct array));

	while(i < a1->length && j < a2->length){

		if(a1->A[i] < a2->A[j])
			a3->A[k++] = a1->A[i++];
		else
			a3->A[k++] = a2->A[j++];
	}
	cout<<"i Value is :"<<i<<endl<<"j Value is :"<<j<<endl;
	for(;i<a1->length;i++)
		a3->A[k++]=a1->A[i];
	for(;j<a2->length;j++)
		a3->A[k++]=a2->A[j];

	a3->length = a1->length+a2->length;
	a3->size = 2*a3->length;
	cout<<endl<<" A3 Size :"<<a3->size<<endl;

	return a3;
}


int main(){

struct array a1 = {{1,3,4,6,8},5,10};
struct array a2 = {{2,5,7,9,0},5,10};
struct array *a3;

a3 = merge(&a1 ,&a2);
display(*a3);
}