#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos > 0 && nums[pos - 1] >= nums[pos]) pos--;
        reverse(nums.begin() + pos, nums.end());
        if (pos > 0) {
                for (int i = pos; i < nums.size(); i++ ) {
                    if (nums[i] > nums[pos - 1]) {
                        swap (nums[pos - 1], nums[i]);
                        break;
                    }
                }
        }     
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s1;
    s1.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}