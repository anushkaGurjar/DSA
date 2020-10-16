// Problem Statement: https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums){
        
        string result;
        vector<string> data(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
            data[i] = to_string(nums[i]);
        
        sort(data.begin(), data.end(), [](string& one, string& two) {return one + two > two + one;});
        
        for(auto token: data)
            result.append(token);
        
        return result[0] == '0' ? "0" : result;
    }
};
