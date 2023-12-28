#include<iostream>
using namespace std;

struct Array{
	int a[10];
	int len;
	int size;
};
void display(struct Array A){
	for (int i = 0; i < A.len; i++)
	{
		cout<<" | "<<A.a[i]<<" | ";
	}
}

struct Array* merge (struct Array *a1,struct Array *a2){

int i , j ,k;

i = j = k =0;

struct Array *a3 = (struct Array*)malloc(sizeof(struct Array));

while(i < a1->len && j < a2->len){
	if(a1->a[i]<a2->a[j]){
		a3->a[k++]=a1->a[i++];
	}
	else
		a3->a[k++] = a2->a[j++];
}

for(;i<a1->len;i++)
	a3->a[k++] = a1->a[i];
for(;j<a2->len;j++)
	a3->a[k++] = a2->a[j];

a3->len = a1->len+a2->len;
a3->size = 1.5*a3->len;
return a3;
}

struct Array* Union (struct Array *a1,struct Array *a2){

int i , j ,k;

i = j = k =0;

struct Array *a3 = (struct Array*)malloc(sizeof(struct Array));

while(i < a1->len && j < a2->len){
	if(a1->a[i]<a2->a[j]){
		a3->a[k++]=a1->a[i++];
	}
	else if(a2->a[i] < a1->a[j])
		a3->a[k++] = a2->a[j++];
	else{
		a3->a[k++] = a1->a[i++];
		j++;
	}
}

// for(;i<a1->len;i++)
// 	a3->a[k++] = a1->a[i];
// for(;j<a2->len;j++)
// 	a3->a[k++] = a2->a[j];

a3->len = a1->len+a2->len;
a3->size = 1.5*a3->len;
return a3;
}

int main(){
	struct Array a1 = {{1,3,4,6,8},5,10};
	struct Array a2 = {{1,3,6,9,0},5,10};
	struct Array *a3;
	a3 = Union(&a1,&a2);
	// a4 = Union(&a1,&a2);

	display(*a3);
	// display(*a4);
}