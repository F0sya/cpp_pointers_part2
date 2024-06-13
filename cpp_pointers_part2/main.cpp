#include <iostream>
#include <ctime>
using namespace std;


template<typename T>
T* init_array(int* size)
{
	T* arr = new T[*size];
	for (int i = 0; i < *size; i++) {
		arr[i] = rand() % 10;
	}
	return arr;
}

template<typename T>
T* action(int* arr, int* size,int*choose) {
	int new_size = 0;
	switch (*choose) {
	case 1:
		for (int i = 0; i < *size; i++) {
			if (arr[i] % 2 == 0) {
				arr[new_size] = arr[i];
				new_size++;
			}
		}break;
	case 2:
		for (int i = 0; i < *size; i++) {
			if (arr[i] % 2 != 0) {
				arr[new_size] = arr[i];
				new_size++;
			}
		}break;
	}
	return arr;
}

template<typename T>
void print_array(T* arr, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}

int main() {
	srand(time(0));

	int* size_M = new int;
	int* choose = new int;
	cout << "Enter a first size_M:"; cin >> *size_M;
	int* arr_M = init_array<int>(size_M);

	cout << endl << "First array:" << endl;
	print_array(arr_M, size_M);

	cout << "What'd you wanna delete?\n-(1)ODD\n-(2)EVEN"; cin >> *choose;
	int* result_arr = action<int>(arr_M, size_M, choose);
	int* new_size = new int;
	*new_size = (sizeof(result_arr) / sizeof(result_arr[0])) + 1;
	print_array(result_arr, new_size);
	delete[] arr_M;
	delete size_M;

}