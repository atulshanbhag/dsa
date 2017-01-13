#include <iostream>
using namespace std;


void print_array(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << arr[i] << " " << flush;
	cout << endl;
}


void merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int l1[n1];
	int l2[n2];
	
	for(int i=0; i<n1; i++)
		l1[i] = arr[left+i];

	for(int j=0; j<n2; j++)
		l2[j] = arr[mid+j+1];

	int i = 0, j = 0, k = left;
	
	while(i < n1 && j < n2)
	{
		if(l1[i] < l2[j])
			arr[k++] = l1[i++];
		else
			arr[k++] = l2[j++];
	}

	while(i < n1)
		arr[k++] = l1[i++];

	while(j < n2)
		arr[k++] = l2[j++];
}

void mergesort(int arr[], int left, int right)
{
	if(left >= right)
		return;

	int mid = (left + right) / 2;
	
	mergesort(arr, left, mid);
	merge(arr, left, mid, right);
	mergesort(arr, mid+1, right);
}

int main()
{
	int arr[] = {5, 4, 19, 2, 46, 1, 13, 45, 34, 22};
	int n = sizeof(arr) / sizeof(arr[0]);

	mergesort(arr, 0, n-1);

	print_array(arr, n);

	return 0;
}