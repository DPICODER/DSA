#include<iostream>

using namespace std;



struct array{
	int a[10];
	int size;
	int len;
};


void display(struct array arr){
	cout<<endl<<"Elements in Array :"<<endl;

	for(int i = 0 ; i <arr.len ; i++){
		cout<<" | "<<arr.a[i]<<" | ";
	}
	cout<<endl;
	cout<<endl;

}

void insert(struct array *arr, int ele){
	if(arr->len < arr->size){
		arr->a[arr->len++] = ele;
	}
}


void append(struct array *arr , int index , int ele){
	if(index < arr->len && index > 0){
		if(arr->len < arr-> size){
			for(int i = arr->len ; i >=index ; i--){
				arr->a[i+1] = arr->a[i];
			}
			arr->a[index] = ele;
			arr->len++;
		}
	}
}


void delete_ele(struct array *arr , int index){
	int temp_str = arr->a[index];
	if(index < arr->len && index > 0){

		for(int i = index ; i<= arr->len ; i++){
			arr->a[i] = arr->a[i+1];
		}
		arr->len--;
		cout<<"Element -> "<< temp_str <<" at Index Location : "<<index <<" Is successfully Deleted"<<endl;
	}
}


int linear_search (struct array arr,int ele){
	int cnt = 0;
	for(int i = 0 ; i < arr.len; i++){
		if(arr.a[i] == ele){
			cout<<endl<< "Linear_Search -::- Element -> "<<ele <<" Found at Index Location : "<<i<<endl<<endl;
			return 0;
		}
	}
	return 1;
}

void binary_search(struct array arr,int ele , int low , int high){
	int mid;
	cout<<endl<< "Binary_Search "<<endl;
	cout<<endl<< "-------------------------------------------------------------------------------------------------"<<endl;
	while(low<=high){
		mid = (low + high)/2;
		cout<<"high : "<<high<<endl<<"mid : "<< mid<<endl<<"low : "<< low<<endl<<endl;
		if(arr.a[mid] == ele ){
			cout<<endl<< "Binary_Search -::- Element -> "<< ele <<" Found at Index Location : "<<mid<<endl<<endl;
			break;
		}
		else
			if(ele > arr.a[mid]){
				low = mid + 1;
			}
		else{
			high = mid - 1;
		}
	}
}


int main(){
	struct array arr = {{1,2,4,5,7,8,9},20,7};

	display(arr);

	insert(&arr,10);

	display(arr);

	append(&arr,2,3);

	display(arr);

	delete_ele(&arr,8);

	display(arr);

	linear_search(arr,3);

	binary_search(arr,7,0,arr.len);
	
	// binary_search(arr,2,0,arr.len);

	// binary_search(arr,4,0,arr.len);

	// binary_search(arr,3,0,arr.len);

	// binary_search(arr,9,0,arr.len);




}