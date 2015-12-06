class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    map[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto it : map) {
	        if (it.first < value-it.first && map.find(value-it.first) != map.end())
	            return true;
	        // handle duplicate
	        if (it.first*2 == value && it.second > 1)
	            return true;
	    }
	    return false;
	}
	
private:
    // value -> times of occurance
    unordered_map<int, int> map;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
