#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] + nums[2] + nums[3] > target) return ans;

        for(int i = 0; i < nums.size()-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target) {
                        l++;
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target) {
                        r--;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    }
                }
            }    
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution s1;
    int target = 0;
    vector<vector<int>> result = s1.fourSum(nums, target);
    for (int i = 0; result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
}