#include<iostream>
using namespace std;

void swap ( char &a, char &b)
{
    char temp; 
    temp = a ; 
    a = b;
    b = temp;
} 
int main()
{
    char arr[] =  {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    int n = sizeof(arr) / sizeof (arr[0]);
    int start,end,mid;
    start = mid = 0;
    end = n - 1;
    for (;mid <= end;)
    {
        switch(arr[mid])
        {
            case 'B': 
                swap(arr[mid], arr[end--]);
                break; 
            case 'R': 
                swap(arr[start++], arr[mid++]);
                break; 
            case 'G': 
                mid++; 
                break; 
        }
    } 
    for (int i = 0; i<n ; ++i) cout << arr[i]<<"\t"; 
    return 0;
}