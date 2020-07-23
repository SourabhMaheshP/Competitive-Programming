import java.util.*;

class Solution {
    public int candy(int[] arr) {
          int n = arr.length;
          int[] least = new int[n];
            Arrays.fill(least,1);

            int sum = 0;

                //left -> right
            for(int i =1; i<n; i++)
                if(arr[i] > arr[i-1])
                    least[i] = least[i-1] + 1;
            //right->left
            for(int i=n-1;i>0;i--)
                if(arr[i-1] > arr[i] && least[i-1] <= least[i])
                    least[i-1] = least[i]+1;
             
            for(int i=0;i<n;i++)
                sum+=least[i];
            return sum;
    }
}