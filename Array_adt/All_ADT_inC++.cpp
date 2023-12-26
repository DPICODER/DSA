#include<iostream>

using namespace std;

class Array {
private:
    int* a;
    int size;
    int length;

public:
    Array() {
        size = 10;
        length = 0;
        a = new int[size];
    }

    Array(int sz) {
        size = sz;
        length = 0;
        a = new int[size];
    }

    ~Array() {
        delete[] a;
    }

    void display();
    void insert(int index, int ele);
    void append(int index, int ele);
    void delete_ele(int index);
    int linear_search(int ele);
    void binary_search(int ele, int low, int high);
    int get(int index);
    void set(int index, int ele);
    int max();
    int min();
    int sum();
    void reverse_arr();
    void reverse_arr_Swap();
    void shifting();
    void issorted();
    void setLength(int len) {
        length = len;
    }
};

void Array::display() {
    cout << endl << "Elements in Array :" << endl;

    for (int i = 0; i < length; i++) {
        cout << " | " << a[i] << " | ";
    }
    cout << endl;
    cout << endl;
}

void Array::insert(int index, int ele) {
    if (length < size && index >= 0 && index <= length) {
        for (int i = length - 1; i >= index; i--) {
            a[i + 1] = a[i];
        }
        a[index] = ele;
        length++;
    }
}

void Array::append(int index, int ele) {
    if (index < length && index >= 0 && length < size) {
        for (int i = length - 1; i >= index; i--) {
            a[i + 1] = a[i];
        }
        a[index] = ele;
        length++;
    }
}

void Array::delete_ele(int index) {
    if (index >= 0 && index < length) {
        int temp_str = a[index];
        for (int i = index; i < length - 1; i++) {
            a[i] = a[i + 1];
        }
        length--;
        cout << "Element -> " << temp_str << " at Index Location : " << index << " Is successfully Deleted" << endl;
    }
}

int Array::linear_search(int ele) {
    int cnt = 0;
    for (int i = 0; i < length; i++) {
        if (a[i] == ele) {
            cout << endl << "Linear_Search -::- Element -> " << ele << " Found at Index Location : " << i << endl << endl;
            return i;
        }
    }
    return -1;
}

void Array::binary_search(int ele, int low, int high) {
    int mid;
    cout << endl << "Binary_Search " << endl;
    cout << endl << "-------------------------------------------------------------------------------------------------" << endl;
    while (low <= high) {
        mid = (low + high) / 2;
        cout << "high : " << high << endl << "mid : " << mid << endl << "low : " << low << endl << endl;
        if (a[mid] == ele) {
            cout << endl << "Binary_Search -::- Element -> " << ele << " Found at Index Location : " << mid << endl << endl;
            break;
        }
        else if (ele > a[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}

int Array::get(int index) {
    if (index >= 0 && index < length) {
        return a[index];
    }
    return -1;
}

void Array::set(int index, int ele) {
    if (index >= 0 && index < length && length < size) {
        a[index] = ele;
    }
}

int Array::max() {
    int M = a[0];
    for (int i = 0; i < length; i++) {
        if (a[i] > M) {
            M = a[i];
        }
    }
    return M;
}

int Array::min() {
    int M = a[0];
    for (int i = 0; i < length; i++) {
        if (a[i] < M) {
            M = a[i];
        }
    }
    return M;
}

int Array::sum() {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }
    return sum;
}

void Array::reverse_arr() {
    int arr1[length];
    int i, j;
    for (i = 0; i < length; i++) {
        arr1[i] = a[i];
    }

    int size = sizeof(arr1) / sizeof(int);
    int arr2[size];

    cout << "SIZE OF ARRAY : " << size << endl << endl;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            arr2[j] = arr1[i];
        }
    }

    cout << "reversed Array : ";
    for (int i = 0; i < size; i++) {
        cout << " | " << arr2[i] << " | ";
    }
    cout << endl << endl;
}

void Array::reverse_arr_Swap() {
    int arr1[length];
    int i, j;
    for (i = 0; i < length; i++) {
        arr1[i] = a[i];
    }

    int size = sizeof(arr1) / sizeof(int);

    cout << "SIZE OF ARRAY : " << size << endl << endl;

    int temp = 0;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
    }

    cout << "reversed Array : ";
    for (int i = 0; i < size; i++) {
        cout << " | " << arr1[i] << " | ";
    }
    cout << endl << endl;
}

void Array::shifting() {
    int size = length;
    int holder, i, arr1[size], arr2[size];

    for (i = 0; i < size; i++) {
        arr1[i] = a[i];
        arr2[i] = a[i];
    }

    for (i = 0; i < size; i++) {
        arr1[i - 1] = arr1[i];
    }

    cout << "Left shifted Array : ";
    for (int i = 0; i < size; i++) {
        cout << " | " << arr1[i] << " | ";
    }
    cout << endl << endl;

    for (i = size; i >= 0; i--) {
        arr2[i + 1] = arr2[i];
    }

    cout << "Right shifted Array : ";
    for (int i = 0; i < size; i++) {
        cout << " | " << arr2[i] << " | ";
    }
    cout << endl << endl;
}

void Array::issorted() {
    for (int i = 0; i < length - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << "Array is not Sorted" << endl;
            return;
        }
    }
    cout << "Array is Sorted" << endl;
}

int main() {
    Array* arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of The Array :";
    cin >> sz;

    arr1 = new Array(sz);
    arr1->setLength(0);

    do {
        cout << "\n\nMenu\n\n";
        cout << " 1 . Insert\n";
        cout << " 2 . Delete\n";
        cout << " 3 . Search\n";
        cout << " 4 . Sum\n";
        cout << " 5 . Display\n";
        cout << " 6 . Exit\n";

        cout << "Enter Your Choice :";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter a Element and its Index position: ";
            cin >> x >> index;
            arr1->insert(index, x);
            break;
        case 2:
            cout << "Enter Index: ";
            cin >> index;
            arr1->delete_ele(index);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> x;
            index = arr1->linear_search(x);
            cout << "Element index: " << index << endl;
            break;
        case 4:
            cout << "Sum: " << arr1->sum() << endl;
            break;
        case 5:
            arr1->display();
            break;
        }

    } while (ch < 6);

    return 0;
}
