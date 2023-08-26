// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
// Example 1:
// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    int i = 0;
    int j = 0;
    vector<long long>ans;
    queue<int> q;
    while(j<N){
        if(A[j] < 0){
            q.push(A[j]);
        }
        int window_size = j-i+1;
        if(window_size<K){
            j++;
        }
        else if(window_size == K){
            if(!q.empty()){
                ans.push_back(q.front());
            }
            else{
                ans.push_back(0);
            }
            j++;
            if(!q.empty() && (q.front() == A[i])){
                q.pop();
            }
            i++;
        }
        
    }
    return ans;
 }
