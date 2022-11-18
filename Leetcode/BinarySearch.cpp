#include <vector>

using namespace std;

class Solution {
 public:
  int BinarySearch1(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return -1;
  }

  int BinarySearch2(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;

    int left = 0;
    int right = nums.size();
    int mid;
    while (left < right) {
      // Prevent (left + right) overflow
      mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid;
    }

    // Post-processing:
    // End Condition: left == right

    if (left != nums.size() && nums[left] == target) return left;
    return -1;
  }

  int BinarySearch3(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left + 1 < right) {
      // Prevent (left + right) overflow
      mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid;
      else
        right = mid;
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if (nums[left] == target) return left;
    if (nums[right] == target) return right;
    return -1;
  }
};