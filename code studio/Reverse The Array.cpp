// Reverse The Array
// Sample Input 1:
// 2
// 6 3
// 1 2 3 4 5 6
// 5 2
// 10 9 8 7 6
// Sample Output 1:
// 1 2 3 4 6 5
// 10 9 8 6 7
#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	int s = m+1;
	int e = arr.size()-1;
	int temp;
	while(s<=e){
		temp = arr[s];
		arr[s] = arr[e];
		arr[e] = temp;
		s++;
		e--;
	}
}
