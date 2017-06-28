#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::to_string;
using std::set;
using std::sort;
using std::next_permutation;

// test for M get N permutation
class Solution0 {
public:
	vector<vector<int>>  getPermutation(vector<int> m, int n) {
		vector<vector<int>> result;
		vector<int> tempVec;
		if (n == 1) {
			for (auto i : m) {
				tempVec.clear();
				tempVec.push_back(i);
				result.push_back(tempVec);
			}
			return result;
		}
		vector<vector<int>> tempResult;
		for (int i = 0; i < m.size(); ++i) {
			tempVec = m;
			tempVec.erase(tempVec.begin() + i);
			tempResult = getPermutation(tempVec, n - 1);
			for (auto vec : tempResult) {
				vec.push_back(m[i]);
				result.push_back(vec);
			}
		}
		return result;
	}
};

// test for M get N combination
class Solution1 {
public:
	vector<vector<int>> getCombination(vector<int> m, int n) {
		vector<vector<int>> result;
		vector<int> tempVec;
		if (n == 1) {
			for (auto i : m) {
				tempVec.clear();
				tempVec.push_back(i);
				result.push_back(tempVec);
			}
			return result;
		}
		vector<vector<int>> tempResult;
		for (int i = 0; i < m.size(); ++i) {
			tempVec = m;
			tempVec.erase(tempVec.begin() + i);
			tempResult = getCombination(tempVec, n - 1);
			for (auto vec : tempResult) {
				vec.push_back(m[i]);
				if (!existEqualCombination(result, vec)) {
					result.push_back(tempVec);
				}
			}
		}
		return result;
	}

protected:
	bool existEqualCombination(vector<vector<int>> result, vector<int> temp) {
		sort(temp.begin(), temp.end());
		for (auto vec : result) {
			sort(vec.begin(), vec.end());
			if (vec == temp) return true;
		}
		return false;
	}
};

// test for std::next_permutation 
class Solution2 {
public:
	vector<vector<int>> getPermutation(vector<int> m, int n) {
		vector<vector<int>> result;
		if (n == m.size()) {
			while (next_permutation(m.begin(), m.end())) {
				result.push_back(m);
			}
			result.push_back(m);
		} else {
			for (int i = 0; i < m.size(); ++i) {
				vector<int> temp = m;
				temp.erase(temp.begin() + i);
				result = getPermutation(temp, n);
			}
		}
		return result;
	}
};

int main()
{
	vector<int> m = { 1, 2, 3, 4 };
	vector<vector<int>> result;
	// permutation
	Solution0 solution0;
	result = solution0.getPermutation(m, 3);
	// combination
	Solution1 solution1;
	result = solution1.getCombination(m, 3);
	// std::next_permutation
	Solution2 solution2;
	result = solution2.getPermutation(m, 3);
	cout << result.size() << endl;
	for (auto vec : result) {
		for (auto i : vec) {
			cout << i << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}