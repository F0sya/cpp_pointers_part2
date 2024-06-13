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
T* init_new_array(int* size_N, int* size_M, int* arr_M, int* arr_N) {
	T* arr = new T[*size_N + *size_M];
	for (int i = 0; i < *size_M; i++) {
		arr[i] = arr_M[i];
	}
	for (int i = 0; i < *size_N; i++) {
		arr[i + (*size_M)] = arr_N[i];
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
template<typename T>
void print_new_array(T* arr, int* size_M,int* size_N){
	for (int i = 0; i < *size_M+*size_N; i++)
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
	
	int* result_arr = init_new_array<int>(size_N, size_M, arr_M, arr_N);
	cout << endl << "Result array:" << endl;
	print_new_array(result_arr, size_M, size_N );

	delete[] arr_M, arr_N;
	delete size_M, size_N;

}