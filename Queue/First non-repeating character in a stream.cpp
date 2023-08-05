// Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> count;
		    queue<char> q;
		    string ans = "";
		    for(int i=0;i<A.length();i++){
		        char ch = A[i];
		      //  increase count
		        count[ch]++;
		      //  push into queue
		        q.push(ch);
		        while(!q.empty()){
		          //  repeating character
		            if(count[q.front()] > 1){
		                q.pop();
		            }
		          //  non-repeating character
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};
