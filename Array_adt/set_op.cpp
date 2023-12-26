#include<iostream>

using namespace std;

struct array{
	int A[10];
	int len;
	int size;
};

void display(struct array a){
	int i;
	for(i=0;i<a.len;i++){
		cout<<" | "<<a.A[i]<<" | ";	
	}
}


struct array* merge(struct array *a1 , struct array *a2){
int i,j,k;

i = j = k = 0;

struct array *a3 = (struct array *) malloc(sizeof(struct array));

while(i<a1->len && j < a2->len){
	if(a1->A[i] < a2->A[j]){
		a3->A[k++] = a1->A[i++];
	} 
	else
		a3->A[k++] = a2->A[j++];
}

for(;i<a1->len;i++){
	a3->A[k++] = a1->A[i];
}
for(;j<a2->len;j++){
	a3->A[k++] = a2->A[j];
}

a3->len = a1->len+a2->len;

a3->size = 10;

return a3;


}

struct array* Union(struct array *a1 , struct array *a2){
int i,j,k;

i = j = k = 0;

struct array *a3 = (struct array *) malloc(sizeof(struct array));

while(i<a1->len && j < a2->len){
	
	if(a1->A[i] < a2->A[j]){
		a3->A[k++] = a1->A[i++];
	} 

	else if(a2->A[j]<a1->A[i]){
			a3->A[k++] = a2->A[j++];
		}

	else{
		a3->A[k++] = a1->A[i++];
		j++;
	}
}

for(;i<a1->len;i++){
	a3->A[k++] = a1->A[i];
}
for(;j<a2->len;j++){
	a3->A[k++] = a2->A[j];
}

a3->len = k;

a3->size = 10;

return a3;


}


struct array* Intersection(struct array *a1 , struct array *a2){
int i,j,k;

i = j = k = 0;

struct array *a3 = (struct array *) malloc(sizeof(struct array));

while(i<a1->len && j < a2->len){
	
	if(a1->A[i] < a2->A[j]){
		i++;
	} 

	else if(a2->A[j]<a1->A[i]){
			j++;
		}
		
	else if(a1->A[i]==a2->A[j]){
		a3->A[k++] = a1->A[i++];
		j++;
	}
}

a3->len = k;

a3->size = 10;

return a3;


}
struct array* Difference(struct array *a1 , struct array *a2){
int i,j,k;

i = j = k = 0;

struct array *a3 = (struct array *) malloc(sizeof(struct array));

while(i<a1->len && j < a2->len){
	
	if(a1->A[i] < a2->A[j]){
		a3->A[k++] = a1->A[i++];
	} 

	else if(a2->A[j]<a1->A[i]){
			j++;
		}
		
	else{
		i++;
		j++;
	}
}

for(;i<a1->len;i++){
	a3->A[k++] = a1->A[i];
}


a3->len = k;

a3->size = 10;

return a3;


}
//Needs a review again
int main(){
	struct array a1 = {{1,3,4,6,8},5,10};
	struct array a2 = {{2,3,7,6,0},5,10};
	struct array *a3;

	a3 = Difference(&a1,&a2);

	display(*a3);

}
