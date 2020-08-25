#include<iostream>
#include<unordered_map>

using namespace std;

void dupToUnique(int *arr,int n)
{
    unordered_map <int,int> freq;
    int min_sum = 0;
    for(int i=0; i<n; ++i)
        freq[arr[i]]++;
    for(int i=0; i<n; ++i)
    {
        if( freq[arr[i]] != 1 )
        {
            freq[arr[i]]--;
            while( freq.find(++arr[i]) != freq.end() );
            freq[arr[i]]++;   
        }
        min_sum += arr[i];
    }
    cout << min_sum << endl;
}
int main()
{
    int arr[] = {3,2,1,2,1,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    dupToUnique(arr,n);
    for(int i:arr)  cout<<i<<" ";
    return 0;
}
