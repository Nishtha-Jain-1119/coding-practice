// Count Ways To Reach The N-th Stairs
// Sample Input 1 :
// 2
// 2
// 3
// Sample Output 1 :
// 2
// 3

// iterative code -->two test case pass
#include <bits/stdc++.h>
unsigned int fac(unsigned int n)
{
	if (n == 0)
		return 1;
	return n * fac(n - 1);
} 
int countDistinctWays(int nStairs) {
    int maxSteps = 0;
   if(nStairs&1){
       maxSteps = nStairs/2 + 1;
   }
   else{
       maxSteps = nStairs/2;
   }
   int ans = 0;
   int countOf_2 = 0;
   while(nStairs>=maxSteps){
       unsigned int n = fac(nStairs);
       unsigned int r = fac(countOf_2);
       unsigned int n_r = fac(nStairs-countOf_2);
       ans += n/(r*n_r);
    //    cout<<"ans "<<ans<<" ";
       countOf_2++;
       nStairs--;
   }
   return ans;
}

// recursion code -->3 test case pass
#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    if(nStairs<0)
        return 0;
    if(nStairs==0)
        return 1;
    int ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
    return ans;
}
