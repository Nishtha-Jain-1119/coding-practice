// Sum Of Two Arrays
// Sample Input 1:
// 2
// 4 1 
// 1 2 3 4
// 6
// 3 2
// 1 2 3
// 9 9    
// Sample Output 1:
// 1 2 4 0
// 2 2 2

#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
	int i = n-1;
	int j = m-1;
	int carry = 0;
	while(i>=0 && j>=0){
		int sum = a[i]+b[j]+ carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--;
		j--;
	}
	while(i>=0){
		int sum = a[i]+carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--;
	}
	while(j>=0){
		int sum = b[j]+carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		j--;
	}
	while(carry != 0){
		int sum = carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}