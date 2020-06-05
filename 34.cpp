#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int findFirstPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

    int findLastPosition(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;

            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        int firstPosition = findFirstPosition(nums, target);

        if (firstPosition == -1) {
            return {-1, -1};
        }
        int lastPosition = findLastPosition(nums, target);
        return {firstPosition, lastPosition};
    }
};

int main() {
    vector<int> nums = {1, 2, 4, 4, 6, 8, 9, 11};
    Solution s1;
    vector<int> a = s1.searchRange(nums, 4);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    return 0;
}

