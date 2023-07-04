// Subsequences of String
// Sample Input 1:
// 1 
// abc
// Sample Output 1:
// a ab abc ac b bc c

#include <bits/stdc++.h> 
void solution(string str, int index, string output, vector<string>& ans){
	// base case
	if(index>=str.length()){
		if(output.length()>0)
			ans.push_back(output);
		return;
	}
	// exclude
	solution(str, index+1, output,ans);

	// include
	output.push_back(str[index]);
	solution(str, index+1, output,ans);
}
vector<string> subsequences(string str){
	
	// Write your code here
	int index = 0;
	string output = "";
	vector<string> ans;
	solution(str, index, output,ans);
	return ans;
}
