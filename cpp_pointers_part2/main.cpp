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
T* init_new_array(int* size, int* size_N, int* size_M, int* arr_M, int* arr_N) {
	int* new_size = new int{ 0 };
	T* arr = new T[*size_M + *size_N];
	for (int i = 0; i < *size_M; i++)
	{
		bool check_in = false;
		for (int j = 0; j < *size_N; j++)
		{
			if (arr_M[i] == arr_N[j]) {
				check_in = true;
			}
		}
		if (check_in == false) {
			bool checker = false;
			for (int k = 0; k < *new_size; k++) {
				if (arr_M[i] == arr[k]) {
					checker = true;
					break;
				}
			}
			if (checker == false) {
				arr[*new_size] = arr_M[i];
				(*new_size)++;
			}
		}
	}

	for (int i = 0; i < *size_N; i++)
	{
		bool check_in = false;
		for (int j = 0; j < *size_M; j++)
		{
			if (arr_N[i] == arr_M[j]) {
				check_in = true;
			}
		}
		if (check_in == false) {
			bool checker = false;
			for (int k = 0; k < *new_size; k++) {
				if (arr_N[i] == arr[k]) {
					checker = true;
					break;
				}
			}
			if (checker == false) {
				arr[*new_size] = arr_N[i];
				(*new_size)++;
			}
		}
	}

	*size = *new_size;
	T* new_arr = new T[*size];
	for (int i = 0; i < *size; i++)
	{
		new_arr[i] = arr[i];
	}
	return new_arr;
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
	int* size_N = new int;

	cout << "Enter a first size_M:"; cin >> *size_M;
	cout << "Enter a first size_N:"; cin >> *size_N;

	int* arr_M = init_array<int>(size_M);
	int* arr_N = init_array<int>(size_N);

	cout << endl << "First array:" << endl;
	print_array(arr_M, size_M);
	cout << "Second array:" << endl;
	print_array(arr_N, size_N);

	int* new_size = new int;
	int* result_arr = init_new_array<int>(new_size, size_N, size_M, arr_M, arr_N);
	cout << endl << "Result array:" << endl;
	print_array(result_arr, new_size);

	delete[] arr_M, arr_N;
	delete size_M, size_N;

}