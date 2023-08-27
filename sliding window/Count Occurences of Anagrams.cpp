// Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.
// Example 1:

// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Explanation: for, orf and ofr appears
// in the txt, hence answer is 3.

class Solution{
public:
    bool allZeros(vector<int> &count){
        for(int i=0;i<count.size();i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }
	int search(string pat, string txt) {

	    int k = pat.length();
        vector<int> count(26, 0);
	   // count frquency of each character in pat
	    for(int i=0;i<k;i++){
	        count[pat[i]-'a']++;
	    }
	    // sliding window technique.
	    int i = 0;
	    int j = 0;
	    int ans = 0;
	    while(j<txt.length()){
	        count[txt[j] - 'a']--;
	        if(j-i+1 == k){
	            if(allZeros(count)){
	                ans++;
	            }
	            count[txt[i] - 'a']++;
	            i++;
	        }
	        j++;
	    }
	    return ans;
	}
};
