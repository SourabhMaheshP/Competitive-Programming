#include<stdio.h>
int main()
{
    int arr[] = {4,2,-3,1,6};
    int sum ;

    for (int i = 0; i < 5; i++)
    {
        sum = 0;
        for (int j = i; j < 5; j++ )
        {
            sum += arr[j];    
            
            if(sum == 0) // !sum
            {
                printf("Found! %d %d ",i,j);
                break;
            }

        }   
    }
    
    return 0;
}