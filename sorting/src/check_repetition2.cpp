#include <iostream>
#include <algorithm>
using namespace std;

bool check_duplicate2(int arr[], int n)
{
	sort(arr, arr+n);
	for(int i=0; i<n-1; i++)
		if(arr[i] == arr[i+1])
			return true;
	return false;
}

int main()
{
	int arr[] = {1, 3, 5, 32, 12};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << check_duplicate2(arr, n) << endl;

	return 0;
}