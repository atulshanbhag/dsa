#include <iostream>
using namespace std;

bool check_repetition(int arr[], int n)
{
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i] == arr[j])
				return true;

	return false;
}

int main()
{
	int arr[] = {1, 4, 3, 2, 20, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << check_repetition(arr, n) << endl;

	return 0;
}