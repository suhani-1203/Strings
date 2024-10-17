class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        //lexographically sort the array of strings
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0],last=strs[n-1];
        //compare the letters of first and last words of sorted array
        for(int i=0;i<(min(first.size(),last.size()));i++){
            if(first[i]!=last[i])
                return ans;
            ans=ans+first[i];
        }
        return ans;
    }
};