// Sort array consisting of 0, 1, and 2

#include <iostream>
using namespace std;

void print_array(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << arr[i] << " " << flush;
	cout << endl;
}

void counting_sort(int arr[], int n)
{
	int sorted[n], count[3] = {};

	for(int i=0; i<n; i++)
		count[arr[i]]++;

	for(int i=1; i<3; i++)
		count[i] += count[i-1];

	for(int i=0; i<n; i++)
		sorted[--count[arr[i]]] = arr[i];

	print_array(sorted, n);
}

int main()
{
	int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	counting_sort(arr, n);

	return 0;
}