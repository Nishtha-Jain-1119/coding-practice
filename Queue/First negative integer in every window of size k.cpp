// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                        
    vector<long long> ans;
    deque<long long int> dq;
    
    // process first window of K size
    for(int i=0;i<K;i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }
    
    // store ans of first window
    if(dq.empty()){
        ans.push_back(0);
    }
    else{
        ans.push_back(A[dq.front()]);
    }
    
    // process remaining windows
    for(int i=K;i<N;i++){
        // removal
        if(!dq.empty() && (i-dq.front() >= K)){
            dq.pop_front();
        }
        
        // addition
        if(A[i] < 0){
            dq.push_back(i);
        }
        
        // store ans
        if(dq.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(A[dq.front()]);
        }
    }
    
    return ans;
 }
