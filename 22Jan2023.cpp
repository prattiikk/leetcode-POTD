class Solution {
public:
    int n;
    bool ispal(string &s, int i , int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++,j--;
        }
        return true;
    }
    void backtrack(string s,int idx,vector<string>curr,vector<vector<string>>&result){
        if(idx==n){
            result.push_back(curr);
            return;
        }    
        for(int i = idx ; i< n ;i++){
            if(ispal(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,curr,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        n=s.length();
        backtrack(s,0,curr,result);
        return result;
    }
};
