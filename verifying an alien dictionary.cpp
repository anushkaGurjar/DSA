// Problem Statement: https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution{
public:
    bool isAlienSorted(vector<string>& words, string order){
        
        vector<int> seq(26);
        
        for(int i = 0; i < order.size(); i++)
            seq[order[i] - 'a'] = i;
        
        for(int i = 0; i < words.size() - 1; i++){
            string one = words[i];
            string two = words[i + 1];
            int limit = min(one.size(), two.size()) - 1;
            
            for(int j = 0; j <= limit; j++){
                if(seq[one[j] - 'a'] < seq[two[j] - 'a'])
                    break;
                if(seq[one[j] - 'a'] > seq[two[j] - 'a'])
                    return false;
                else if(j == limit && one.size() > two.size())
                    return false;
            }
        }
        
        return true;
    }
};
