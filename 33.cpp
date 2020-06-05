#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if ((nums[0] > target) ^ (nums[0] >= nums[mid]) ^ (target > nums[mid])) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low == high && nums[low] == target ? low : -1;        
    }
};

int main() {
    vector<int> nums = {7, 8, 9,1, 2, 3, 4};
    Solution s1;
    int a = s1.search(nums, 3);
    cout << a <<endl;
    return 0;
}