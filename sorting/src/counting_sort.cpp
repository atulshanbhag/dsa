#include <iostream>
#include <cstring>
using namespace std;

void print_array(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << arr[i] << " " << flush;
	cout << endl;
}

void counting_sort(int arr[], int sorted[], int n, int K)
{
	int count[K];
	memset(count, 0, sizeof(count));

	for(int i=0; i<n; i++)
		count[arr[i]]++;

	for(int i=1; i<K; i++)
		count[i] += count[i-1];

	for(int i=0; i<n; i++)
	{
		sorted[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
}

int main()
{
	int arr[] = {4, 2, 1, 63, 12, 65, 22, 11, 23, 10, 5, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sorted[n];

	counting_sort(arr, sorted, n, 100);

	print_array(sorted, n);

	return 0;
}