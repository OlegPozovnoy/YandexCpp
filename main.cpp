#include <string>
#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include <set>

using namespace std;

/*
enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;  // возраст
	Gender gender;  // пол
	bool is_employed;  // имеет ли работу
};
*/

template <typename T>
void Print(vector<T>& elements) {
	for (auto x = elements.begin(); x != elements.end(); x++) {
		cout << *x << " ";
	}
	cout << endl;
}

/*
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
	if (range_begin == range_end) {
		return 0;
	}
	vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	auto middle = begin(range_copy) + range_copy.size() / 2;
	nth_element(
		begin(range_copy), middle, end(range_copy),
		[](const Person& lhs, const Person& rhs) {
		return lhs.age < rhs.age;
	}
	);
	return middle->age;
}
*/

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

	//vector<typename RandomIt::value_type> copy(range_begin, range_end);

	if (range_end - range_begin < 2)
		return;

	//RandomIt middle = copy.begin() + (copy.end() - copy.begin()) / 2;
	RandomIt left = range_begin + (range_end - range_begin) / 3;
	RandomIt right = range_begin + (range_end - range_begin)*2 / 3;

	MergeSort(range_begin, left);
	MergeSort(left,right);
	MergeSort(right, range_end);

	vector<typename RandomIt::value_type> merged;

	merge(range_begin, left, left,right, back_inserter(merged));

	vector<typename RandomIt::value_type> merged2;

	merge(merged.begin(),merged.end() ,right, range_end, back_inserter(merged2));

	RandomIt inserted = merged2.begin();
	for (auto i = range_begin; i != range_end; i++) {
		*i = *inserted;
		inserted++;
	}
}


	int main() {
		vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1,-9 };
		MergeSort(begin(v), end(v));
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
		return 0;
	}
