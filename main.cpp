#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Sort {
private:
	vector<int> sorted;

public:

	vector<int> getSorted() {
		return this->sorted;
	}

	void comparison_counting_sort(vector<int> input) {
		int n = input.size();
		vector<int> helpVector(n, 0);
		sorted.resize(n);

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (input[i] > input[j]) {
					helpVector[i]++;
				}
				else {
					helpVector[j]++;
				}		
			}
		}


		for (int i = 0; i < n; i++) {
			sorted[helpVector[i]] = input[i];
		}
	}

	void distribution_counting_sort(vector<int> input) {
		int n = input.size();
		sorted.resize(n);

		int l = *min_element(input.begin(), input.end());
		int u = *max_element(input.begin(), input.end());

		vector<int> helpVector(u - l + 1, 0);

		for (int i = 0; i < n; i++) {
			helpVector[input[i] - l]++;
		}
		

		for (int i = 1; i < helpVector.size(); i++) {
			helpVector[i] += helpVector[i - 1];
		}
		

		for (int i = n - 1; i >= 0; i--) {
			sorted[helpVector[input[i] - l] - 1] = input[i];
			helpVector[input[i] - l] --;
		}
	}

	void printVector(vector<int> input) {
		for (int i = 0; i < input.size(); i++) {
			cout << input[i] << " ";
		}
		cout << endl << endl;
	}
};

vector<int> input_1 = { 15, 53, 44, 74, 46, 1, 50, 30, 62, 2, 4, 63, 67, 87, 19, 61, 48, 45, 54, 24, 76, 17, 30, 6, 36, 95, 64, 69, 77, 98, 94, 1, 88, 4, 38, 23, 88, 47, 20, 42, 79, 4, 56, 45, 43, 3, 23, 61, 83, 3, 51, 41, 80, 4, 1, 77, 12, 86, 10, 20, 42, 20, 10, 77, 61, 74, 97, 13, 0, 62, 89, 99, 39, 21, 93, 54, 72, 99, 15, 98, 27, 17, 10, 76, 27, 78, 90, 96, 100, 73, 85, 17, 9, 74, 86, 93, 28, 58, 62, 83, 86, 82, 18, 5, 64, 85, 18, 26, 98, 98, 29, 96, 27, 70, 15, 89, 17, 98, 50, 45, 19, 3, 3, 46, 19, 3, 83, 75, 38, 8, 40, 26, 39, 6, 74, 61, 38, 16, 14, 83, 5, 97, 75, 4, 5, 63, 54, 81, 49, 2, 35, 30, 71, 94, 39, 94, 92, 46, 6, 22, 14, 100, 16, 12, 51, 3, 30, 91, 70, 11, 24, 24, 3, 59, 4, 61, 59, 36, 9, 91, 56, 75, 50, 7, 32, 71, 41, 17, 64, 40, 42, 23, 12, 44, 70, 0, 33, 58, 70, 80 };
vector<int> input_2 = { 27, 40, 88, 28, 3, 32, 13, 8, 57, 77, 13, 31, 18, 62, 12, 27, 48, 43, 44, 62, 93, 59, 89, 68, 59, 6, 62, 96, 90, 62, 52, 71, 8, 62, 24, 83, 27, 29, 85, 5, 8, 29, 85, 85, 6, 17, 21, 1, 51, 0, 43, 3, 61, 37, 55, 74, 6, 40, 92, 55, 49, 25, 100, 72, 11, 47, 87, 95, 98, 100, 13, 16, 75, 4, 73, 100, 86, 54, 19, 4, 35, 5, 89, 46, 50, 32, 54, 54, 6, 60, 37, 77, 59, 68, 1, 40, 60, 78, 45, 70, 54, 35, 1, 60, 24, 17, 78, 95, 94, 11, 36, 7, 70, 80, 78, 15, 16, 93, 19, 12, 8, 10, 52, 31, 72, 16, 20, 64, 41, 83, 35, 31, 53, 53, 55, 8, 13, 4, 52, 71, 3, 85, 3, 49, 83, 50, 43, 46, 75, 61, 3, 41, 96, 58, 36, 98, 91, 43, 85, 71, 41, 12, 3, 50, 82, 57, 16, 91, 26, 90, 0, 31, 6, 1, 77, 70, 49, 21, 94, 26, 58, 40, 27, 88, 33, 28, 17, 24, 14, 53, 54, 89, 56, 19, 1, 58, 84, 12, 13, 22 };
vector<int> input_3 = { 269, 150, 164, 365, 127, 127, 385, 347, 94, 170, 379, 241, 255, 143, 129, 361, 119, 87, 206, 25, 125, 237, 70, 200, 74, 124, 381, 330, 216, 289, 326, 249, 192, 172, 149, 353, 130, 249, 189, 89, 69, 385, 249, 215, 374, 271, 307, 73, 370, 112, 210, 100, 107, 145, 367, 224, 200, 3, 22, 115, 292, 9, 51, 220, 140, 177, 88, 56, 389, 43, 3, 26, 341, 321, 355, 346, 153, 243, 124, 22, 374, 140, 49, 172, 158, 139, 283, 76, 8, 19, 46, 359, 239, 257, 99, 8, 192, 379, 326, 292, 245, 22, 399, 120, 134, 381, 293, 265, 211, 2, 177, 383, 171, 244, 336, 28, 245, 154, 354, 192, 182, 384, 135, 228, 188, 316, 203, 124, 183, 76, 16, 97, 255, 390, 140, 191, 147, 24, 22, 219, 350, 210, 334, 14, 56, 91, 368, 104, 242, 50, 388, 145, 180, 263, 61, 278, 210, 25, 262, 168, 216, 146, 162, 36, 181, 193, 258, 188, 252, 388, 305, 65, 166, 176, 331, 21, 318, 229, 275, 255, 313, 75, 45, 124, 330, 377, 169, 277, 137, 378, 120, 229, 29, 310, 79, 225, 99, 384, 202, 183 };

int main() {
	Sort sort;

	cout << "Comparasion counting sort:" << endl;
	cout << "-------------------------------" << endl;

	cout << "Input 1:" << endl;
	sort.comparison_counting_sort(input_1);
	sort.printVector(sort.getSorted());

	cout << "Input 2:" << endl;
	sort.comparison_counting_sort(input_2);
	sort.printVector(sort.getSorted());

	cout << "Input 3:" << endl;
	sort.comparison_counting_sort(input_3);
	sort.printVector(sort.getSorted());

	cout << "Distribution counting sort:" << endl;
	cout << "-------------------------------" << endl;
	cout << "Input 1:" << endl;
	sort.distribution_counting_sort(input_1);
	sort.printVector(sort.getSorted());	

	cout << "Input 2:" << endl;
	sort.distribution_counting_sort(input_2);
	sort.printVector(sort.getSorted());

	cout << "Input 3:" << endl;
	sort.distribution_counting_sort(input_3);
	sort.printVector(sort.getSorted());


	return 0;
}