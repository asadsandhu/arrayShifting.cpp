#include <iostream>
using namespace std;

void shiftArray(int* arr, int p, int size)
{
	int j = 0;
	int* temp, size2 = 0;
	cout << "\nActual Array: \n\t{ ";
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";
	}
	cout << " }" << endl;
	
	if (p > 0) {
		size2 = size - p;
		temp = new int[size2];

		for (int i = 0; i < size2; i++)
			temp[i] = arr[i];

		for (int i = 0; i < p; i++)
			arr[i] = arr[i + size2];
		for (int i = p; i < size; i++) {
			arr[i] = temp[j];
			j++;
		}
		p = 0;
	}

	if (p < 0) {
		p = -p;
		size2 = size - p;
		temp = new int[p];
		for (int i = 0; i < p; i++)
			temp[i] = arr[i];

		for (int i = 0; i < size2; i++)
			arr[i] = arr[i + p];
		for (int i = size2; i < size; i++) {
			arr[i] = temp[j];
			j++;
		}
		p = 0;
	}

	if (p == 0) {
		cout << "\nAfter Shifting: \n\t{ ";
		for (int i = 0; i < size; i++) {
			cout << arr[i];
			if (i != size - 1)
				cout << ", ";
		}
		cout << " }" << endl;
	}
	delete[]temp;
}

int main()
{
	int size = 0, p = 0;
	int* arr;
	
	cout << "Input size of array : ";
	cin >> size;
	arr = new int [size];
	
	cout << "Input elements:" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	
	cout << "Input shifting position : ";
	cin >> p;
	shiftArray(arr, p, size);
	delete[]arr;
}