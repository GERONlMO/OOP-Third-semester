#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int randomElem(int min, int max) {
	return min + rand() % (max - min);
}

void nullVector(vector<int>& temp) {
	vector<int> vec(20, 0);
	temp = vec;
}

void filling(vector<int>& temp) {
	cout << endl;
	for (auto vectorElement = begin(temp); vectorElement != end(temp); vectorElement++) {
		(*vectorElement) = randomElem(-100, 100);
		cout << *vectorElement << "\t";
	}
	cout << endl;
}

void printVector(vector<int>& temp) {
	cout << endl;
	for (auto vectorElement = begin(temp); vectorElement != end(temp); vectorElement++) {
		cout << *vectorElement << "\t";
	}
	cout << endl;
}

void maxElement(vector<int>& temp) {
	cout << endl;
	int maxElement = *max_element(temp.begin(), temp.end());;
	cout << "max elem: " << maxElement << endl;
}

void minElement(vector<int>& temp) {
	cout << endl;
	int minElement = *min_element(temp.begin(), temp.end());;
	cout<< "min elem: " << minElement << endl;
}

void sortVector(vector<int>& temp) {
	sort(temp.begin(), temp.end());
	printVector(temp);
}

void fourEndElements(vector<int>& temp) {
	temp.push_back(randomElem(-100, 100));
	temp.push_back(randomElem(-100, 100));
	temp.push_back(randomElem(-100, 100));
	temp.push_back(randomElem(-100, 100));
	printVector(temp);
}

void changeElementsLessTen(vector<int>& temp) {
	for (auto vectorElement = begin(temp); vectorElement != end(temp); vectorElement++) {
		if (*vectorElement < 10) { *vectorElement = 0; }
	}
	printVector(temp);
}

void printElementsMoreTwenty(vector<int>& temp) {
	cout << endl;
	for (auto vectorElement = begin(temp); vectorElement != end(temp); vectorElement++) {
		if (*vectorElement > 20) {
			cout << *vectorElement << "\t";
		}
	}
	cout << endl;
}

void multiplyEvenNumbers(vector<int>& temp) {
	for (auto vectorElement = begin(temp); vectorElement != end(temp); vectorElement++) {
		if (*vectorElement % 2 == 0) { 
			*vectorElement *= 3; 
		}
	}
	printVector(temp);
}

void mixElements(vector<int>& temp) {
	random_shuffle(temp.begin(), temp.end());
	printVector(temp);
}

void deleteElementsLessFifty(vector<int>& temp) {
	int n = 0;
	while (true) {
		for (auto vectorElement = begin(temp); vectorElement != end(temp); vectorElement++) {
			if (*vectorElement > 50) {
				temp.erase(vectorElement);
				break;
			}
			n++;
		}
		if (n == temp.size()) { break; }
		n = 0;
	}
	printVector(temp);
}

void functionEleven(vector<int>& temp) {
	cout << endl;
	cout << "size : " << temp.size() << endl;
	if (temp.size() % 2 != 0) { temp.pop_back(); }
	else { reverse(temp.begin(), temp.end()); }
	printVector(temp);
}

void clearVector(vector<int>& temp) {
	cout << endl;
	if (temp.empty()) { cout << "Vector is clear" << endl; }
	else { temp.clear(); }
}

int main() {
	srand(time(0));

	vector<int> mainVector;

	nullVector(mainVector);
	filling(mainVector);
	maxElement(mainVector);
	minElement(mainVector);
	sortVector(mainVector);
	fourEndElements(mainVector);
	changeElementsLessTen(mainVector);
	printElementsMoreTwenty(mainVector);
	multiplyEvenNumbers(mainVector);
	mixElements(mainVector);
	deleteElementsLessFifty(mainVector);
	functionEleven(mainVector);
	clearVector(mainVector);
	clearVector(mainVector);

	return 0;
}