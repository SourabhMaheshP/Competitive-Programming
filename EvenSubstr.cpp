
//[Complexity]: O(N^3) solution
//optimize solution [hint] : use DP

#include<iostream>
using namespace std;
int ri(char c)
{
    return c-'0';
}
void findSubstr(string s)
{
    int elen,j;

    //check possibility for every even length
    //if not decrease it by 2
        elen = s.length();
        while(elen >= 0)
        {
            j = (elen % 2 == 0) ? elen-1 : elen-2;
            for(int i=0 ; j < s.length() ; ++i,++j)
            {
                int leftsum = 0 , rightsum = 0;
                
                int mid = (i + j) / 2;
                
                for(int x=i ; x <= mid ; ++x)
                    leftsum += ri(s[x]);
                for(int x=mid+1;x<=j;x++)
                    rightsum += ri(s[x]);
                if(leftsum == rightsum)
                {
                    cout << "max even length found " << ((elen % 2 == 0) ? elen : elen-1 );   
                    return;
                }
            }   
            elen-=2;
        }
         
        cout << "Not found any Even length!" ;
}
int main()
{
    string s;
    cin>>s;
    
    findSubstr(s);
    
    return 0;
}
