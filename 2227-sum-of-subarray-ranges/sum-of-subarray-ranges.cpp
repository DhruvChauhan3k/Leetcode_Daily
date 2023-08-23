class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       vector< long long int>A;
      for(auto it:nums)A.push_back(it);
       
        stack<pair< long long int, long long int>> in_stk_p, in_stk_n;
    // left is for the distance to previous less element
    // right is for the distance to next less element
    vector< long long int> left(A.size()), right(A.size());
		
    //initialize
    for( long long int i = 0; i < A.size(); i++) left[i] =  i + 1;
    for( long long int i = 0; i < A.size(); i++) right[i] = A.size() - i;
		
    for( long long int i = 0; i < A.size(); i++){
      // for previous less
      while(!in_stk_p.empty() && in_stk_p.top().first > A[i]) in_stk_p.pop();
      left[i] = in_stk_p.empty()? i + 1: i - in_stk_p.top().second;
      in_stk_p.push({A[i],i});
			
      // for next less
      while(!in_stk_n.empty() && in_stk_n.top().first > A[i]){
        auto x = in_stk_n.top();in_stk_n.pop();
        right[x.second] = i - x.second;
      }
      in_stk_n.push({A[i], i});
    }

    long long ans = 0;
    for( long long int i = 0; i < A.size(); i++){
      ans = (ans + A[i]*left[i]*right[i]);
    }
    // return ans;
      

      stack<pair< long long int, long long int>> in_stk_p1, in_stk_n1;
      vector< long long int>A1;
      for(auto it:nums)A1.push_back(it);
    // left is for the distance to previous less element
    // right is for the distance to next less element
    vector< long long int> left1(A1.size()), right1(A1.size());
		
    //initialize
    for( long long int i = 0; i < A1.size(); i++) left1[i] =  i + 1;
    for( long long int i = 0; i < A1.size(); i++) right1[i] = A1.size() - i;
		
    for( long long int i = 0; i < A1.size(); i++){
      // for previous less
      while(!in_stk_p1.empty() && in_stk_p1.top().first < A1[i]) in_stk_p1.pop();
      left1[i] = in_stk_p1.empty()? i + 1: i - in_stk_p1.top().second;
      in_stk_p1.push({A1[i],i});
			
      // for next less
      while(!in_stk_n1.empty() && in_stk_n1.top().first < A1[i]){
        auto x = in_stk_n1.top();in_stk_n1.pop();
        right1[x.second] = i - x.second;
      }
      in_stk_n1.push({A1[i], i});
    }

    long long ans1 = 0;
    for( long long int i = 0; i < A1.size(); i++){
      ans1 = (ans1 + A1[i]*left1[i]*right1[i]);
    }
    return ans1-ans;


    }
};