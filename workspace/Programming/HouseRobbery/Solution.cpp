class Solution {
public:
    int maxrob(int c, vector<int>& nums, vector<int>& m_maxrob) {
        if (c >= nums.size())
            return 0;
        
        if (c == nums.size()-1)
            return nums[c];
        
        if (m_maxrob[c] == -1)     
            m_maxrob[c] = max(nums[c]+maxrob(c+2, nums, m_maxrob), maxrob(c+1, nums, m_maxrob));
        return m_maxrob[c];
    }
    
    int rob(vector<int>& nums) {
        vector<int> m_maxrob(nums.size(), -1);
        return maxrob(0, nums, m_maxrob);
    }
};