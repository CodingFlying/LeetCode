#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums.front() > 0 || nums.back() < 0)  return {};   //font() 和 back()
        vector<vector <int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int fix = nums[i];
            if (fix > 0) break;
            if (i > 0 && fix == nums[i-1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == -fix) {
                    if (l == i + 1 || r == nums.size() - 1) {      //优化的
                        res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if (nums[l] == nums[l-1]) {
                        l++;
                    }
                    else if (nums[r] == nums[r+1]) {
                        r--;
                    }
                    else {
                        res.push_back(vector<int> {nums[i],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                }
                else if(nums[l]+nums[r]<-fix)
                    l++;
                else r--;
            }   
        }
        return res;
    }

    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector <vector<int> > ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) return ans;
        int i = 0;       
        while (i < nums.size()) {
            if (nums[i] > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                long long y = static_cast<long long> (nums[i]);     // 转换为long long避免加法过程中溢出
                long long x = static_cast<long long> (nums[l]);
                long long z = static_cast<long long> (nums[r]);
                if (x + y > 0 - z ) {
                    r--;
                }
                else if (x + y < 0 -z) {
                    l++;
                }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r-1]) {
                        r--;
                    }
                    r--;
                    l++;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
                i++;
            }
            i++;
    }
    return ans;
    }
};


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s1;
    vector<vector<int>> result = s1.threeSum(nums);
    for (int i = 0; result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
}