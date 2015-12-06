class TwoSum {
private:
    unordered_multiset<int> nums;
    
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    nums.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (int i : nums) {
	        // consider duplicate
	        int count = (value-i == i) ? 1 : 0;
	        if (nums.count(value-i) > count)
	            return true;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
