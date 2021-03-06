// BinarySearch_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/*binary search is efficient algorithm to find if item exist in array or not 
and can localize it's location on one condition that the array is sorted
complexity is logn*/

int binarySearch(vector<int> &arr, int num)
{
	int location = -1;
	int start = 0;
	int end = arr.size() - 1;
	int mid;


	while (start <= end)
	{
		mid = start + (end - start) / 2;

		cout << "start" << start<<endl;
		cout << "mid" << mid << endl;
		cout << "end" << end << endl<<endl;

		if(num == arr[mid])
		{
			location = mid;
			break;
		}
		else if (num < arr[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
		
	}
	return location;

}

int main()
{
	vector <int> x{-5,-2,-1,0,1,2,4};

	int location = binarySearch(x, 0);

	cout << location<<endl;
	system("pause");
    return 0;
}

