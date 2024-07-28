#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

using namespace std;

class Solution {
public:
	void recFun(int left, vector<vector<int>> &ans, vector<int> &nums) {
		// Log the call stack
		cout << endl << "BEGINS" <<endl;
		cout << "depth " << left << ", nums={";
		for (int num : nums) cout << num << " ";
		cout << "}" << endl;

		if (left == nums.size()) {
			cout << "******************************************************" <<endl;
			cout << "depth " << left << " pushing nums in ans, nums={";
			for (int num : nums) cout << num << " ";
			cout << "}" << endl;

			ans.push_back(nums);
			return;
		}
		for (int i = left; i < nums.size(); i++) {
			swap(nums[left], nums[i]);
			cout << "FOR LOOP left= " <<left  <<" and i=" << i <<endl;
			cout <<  "swapping " << left << " with " << i <<endl;
			recFun(left + 1, ans, nums);
			swap(nums[left], nums[i]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		recFun(0, ans, nums);
		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> nums = {1, 2, 3}; // example input
	vector<vector<int>> permutations = sol.permute(nums);
	cout << "----------------------------------------------------------" <<endl;
	cout << endl << "All permutations:" << endl;
	for (const auto& perm : permutations) {
		cout << "{ ";
		for (int num : perm) {
			cout << num << " ";
		}
		cout << "}" << endl;
	}

	return 0;
}
