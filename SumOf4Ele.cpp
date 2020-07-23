/*Program to find a,b,c,d elements from an array such that 
	a+b=c+d 
	Algo:
	1.sort array O(NlogN)
	2.use 2 nested loops
	3.outer loop (i=1 to n-2) inner (j=i+1 to n)
	4.traverse each elemnt from outer loop, and for each element,
	5.find the sum s.t key = a[i] + a[j] - a[j+1]
	6.search "key" using Binary Search O(log N)
	7. if key found print ans.
	8. else traverse inner loop for next ele.
	total TC : o(nlogn) + o(nlogn)^2
			 : o(n2)
	NOTE :	1.I have not used sort
			2.In this prog. i have used linear search. which is o(n)
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define loop(i,n) for(i=0;i<n;i++)
void findPairSum(int *,int);
int main()
{
	int *a, n;
	char ch;
	int i = 0;
	cout << "Enter how many ele"<<endl;
	cin >> n;
	a = (int *)malloc(sizeof(int)*n);
	loop(i, n)
	cin >> a[i];
	cout << "Entered Array Is :" << endl;
	loop(i, n)
	cout << a[i]<<" ";
	cout << endl;
	findPairSum(a, n);
	cin >> ch;
	
	return 0;
}

/*For Optimization purpose use BINARY SEARCH in O(logN) */

int linearSearch(int *a, int last_index, int key)  //O(N)
{
	for (int i = 0; i < last_index; i++)
	{
		if (a[i] == key)
			return 1;  //found
	}
	return 0; //not found
}
void findPairSum(int *a, int n)
{
	int i, j, max = INT_MIN, key = 0;
	int sum_found = 0;
	for (i = 1; i < n - 2; i++)
	{
		max = a[i - 1];
		for (j = i + 1; j < n; j++)
		{
			int sum = a[i] + a[j];
			key = sum - a[j + 1];
			if (key > max && key > 0)
			{
				i++;
				break;
			}
			else if (key <= 0)
				continue;
			else
			{
				sum_found = linearSearch(a, i, key);
				if (sum_found)
					break;
				continue;
			}
		}
		if (sum_found)
			break;
	}
	if (!sum_found)
		cout << "Sum Not Found" << endl;
	else
		cout << a[i] << "+" << a[j] << "=" << key << "+" << a[j + 1] << endl;
}
