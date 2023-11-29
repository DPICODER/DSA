#include<iostream>

using namespace std;


// created a structure named array 
struct array{
	int a[10];  //Declared a array{ a [ of size 10 ] } -> we can ignore the size declared here 
	int size;  // the Integer size variable is used to decide the overall size of array
	int len;   // the Integer len Variable is used to represent total no of elememts in the array
};

// Display method used to Print all Contents of the Array 

void display(struct array arr){
	
	// while calling struct we are using call by value 

	// all we need is to access the elements in the array and not to modify the data in it 

	cout<<endl<<"Elements in Array :"<<endl;

	for(int i = 0 ; i <arr.len ; i++){
		cout<<" | "<<arr.a[i]<<" | ";
	}
	cout<<endl;
	cout<<endl;

}

// Insert method used to insert a element to the array at last available index 

void insert(struct array *arr, int ele){

	// while calling struct we are using call by address

	// Here we are Modifying the elements in the array and adding new data in it


	if(arr->len < arr->size){
		arr->a[arr->len++] = ele;
	}
}

// Append method is used to add a element to array at desired location

void append(struct array *arr , int index , int ele){

	// Call by address

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

// Delete_ele method is used to Delete a element in array at any desired location


void delete_ele(struct array *arr , int index){

	// call by address

	int temp_str = arr->a[index];
	if(index < arr->len && index > 0){

		for(int i = index ; i<= arr->len ; i++){
			arr->a[i] = arr->a[i+1];
		}
		arr->len--;
		cout<<"Element -> "<< temp_str <<" at Index Location : "<<index <<" Is successfully Deleted"<<endl;
	}
}


// Linear_search :- { Searching Alogrithm }
	// searching  a element through out the array in a sequential manner comparing the req element to the array element
	// we use for loop to iterate through the whole array

int linear_search (struct array arr,int ele){
	
	//call by value

	int cnt = 0;
	for(int i = 0 ; i < arr.len; i++){
		if(arr.a[i] == ele){
			cout<<endl<< "Linear_Search -::- Element -> "<<ele <<" Found at Index Location : "<<i<<endl<<endl;
			return 0;
		}
	}
	return 1;
		// Computational Complexity || Time-Complexity  
		 // 				O(n)	||	BigOh(n)
}


// Binary_search :- { Searching Algorithm}
	// also used for seaching a element  --> Requires a sorted array
	// User different Searching approach-----------{ Devide-and-Conquer }
	// Devides the array by half to reach the mid point and search element --> Reduced Search Time


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
	// Computational Complexity || Time-Complexity  
	// 				   O(log n) || BigOh(log n)
}

// Simple Get method to retrive a element at given index

int get(struct array arr, int index){
	if(index >= 0 && index < arr.len){
		return arr.a[index];
	}
	return -1;
}

// Simple set method to replace a element at given index

void set(struct array *arr, int index , int ele){
	if(index >= 0 && index < arr->len){
		if(arr->len < arr->size){
			arr->a[index] = ele;
		}
	}
}

//Simple method to find the maximum value element in the array

int max(struct array arr){
	int M = arr.a[0];
	for(int i = 0 ; i<arr.len ; i++){
		if(arr.a[i] > M){
			M = arr.a[i];
		}
	}
		return M;
}


//Simple method to find the minimum value element in the array

int min(struct array arr){
	int M = arr.a[0];
	for(int i = 0 ; i<arr.len ; i++){
		if(arr.a[i] < M){
			M = arr.a[i];
		}
	}
	return M;
}

// sum method for calculating sum of all elements in array

int sum(struct array arr){
	int sum = 0;
	for(int i = 0 ; i < arr.len ; i++){
		sum += arr.a[i];
	}
	return sum;
}

float Average(struct array arr){
	return(float)sum(arr)/arr.len;
}

// Simple code for reversing a array we use 2-different arrays and 2-for-loops

void reverse_arr(struct array *arr){
	
	int arr1[arr->len];
	
	//loading the struct elements into a temporary array

	int i , j;
	for(i = 0 ; i <arr->len ; i++){
		arr1[i] = arr->a[i];
	}

	int size = sizeof(arr1)/sizeof(int);
	int arr2[size];

	cout<<"SIZE OF ARRAY : "<<size<<endl<<endl;
	// Using 2 for loops to reverse the temp array created
	
	for(i = 0 ; i < size ;i++){
		for(j =0 ; j < size-i; j++){ 
			arr2[j] = arr1[i];			
								// j = 1 and j < size-i < = > j = 1  -> j < 8-1 (7)
								// here on arr2[1] ---> we place arr1[7]
								// j = 2 and j < size-i < = > j = 2  -> j < 8-2 (6)
								// here on arr2[2] ---> we place arr1[6]

								//and so onn-------
		}
	}




	//printing reversed array
	cout<<"reversed Array : ";
	for(int i = 0 ; i <size ; i++){
		cout<<" | "<<arr2[i]<<" | ";
	}
	cout<<endl<<endl;
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

	int getdata = get(arr,7);
	cout<<"Retrived data : "<<getdata<<endl<<endl;

	set(&arr,8,10);
	display(arr);

	int max_ele = max(arr);
	cout<<"Maximum VALUE : "<<max_ele<<endl<<endl;

	int min_ele = min(arr);
	cout<<"Minimum VALUE : "<<min_ele<<endl<<endl;

	int total = sum(arr);
	cout<<"Total VALUE : "<<total<<endl<<endl;

	int avg = Average(arr);
	cout<<"Average VALUE : "<<avg<<endl<<endl;

	reverse_arr(&arr);

}