#include <list>
#include <iostream>
#include <functional>

using namespace std;

int randomElem() {
	return -100 + rand() % (100 - (-100));
}

void printList(list<int>& temp) {
	cout << endl;
	for (auto listElement : temp) {
		cout << listElement << "\t";
	}
	cout << endl;
}

void announceClearList(list<int>& temp) {
	temp.clear();
	printList(temp);
}

void addFiveElements(list<int>& temp) {
	list<int> newTemp = { randomElem(), randomElem(), randomElem(), randomElem(), randomElem() };
	temp.insert(temp.end(), newTemp.begin(), newTemp.end());
	printList(temp);
}

void printFirstElement(list<int>& temp) {
	cout << endl << temp.front() << endl;
}

void addTwoElements(list<int>& temp) {
	temp.push_front(randomElem());
	temp.push_front(randomElem());
	printList(temp);
}

void deleteFourthElement(list<int>& temp) {
	list<int>::iterator it = temp.begin();
	advance(it, 3);
	if (it != temp.end())
	{
		temp.erase(it);
	}
	printList(temp);
}

void randomThreePositions(list<int>& temp) {
	if (temp.size() > 3) {
		auto s = --(--(temp.end()));
		int x = 3;
		for (auto e = temp.begin(); e != temp.end(); e++) {
			if (e == s) {
				size_t d = x;
				temp.insert(e, d, 15);
				break;
			}
			else if (rand() % 2 == 1 && x > 0) {
				x--;
				temp.insert(e, size_t(1), 15);
			}
		}
	}
	else {
		cout << "List size less then " << 4 << endl;
	}
	printList(temp);
}

void deleteLastElement(list<int>& temp) {
	if (temp.size() > 0) {
		temp.pop_back();
	} else {
		cout << "List size less then " << 1 << endl;
	}
	printList(temp);
}

void deleteFirstElement(list<int>& temp) {
	if (temp.size() > 0) {
		temp.pop_front();
	} else {
		cout << "List size less then " << 1 << endl;
	}
	printList(temp);
}

void towElementsInMidle(list<int>& temp) {
	int listSize = temp.size();
	auto listBegin = temp.begin();
	for (int i = 0; i < listSize * 0.5; i++) listBegin++;
	temp.insert(listBegin, size_t(2), randomElem());
	printList(temp);
}

void deleteSameElements(list<int>& temp) {
	temp.sort();
	temp.unique();
	printList(temp);
}

void clearList(list<int>& temp) {
	temp.clear();
	printList(temp);
}

void checkClearList(list<int>& temp) {
	if (temp.empty()) {
		cout << "List clear" << endl;
	}
	else {
		cout << "list is not clear" << endl;
	}
	printList(temp);
}

int main() {
	srand(time(0));

	list<int> mainList;

	announceClearList(mainList);
	addFiveElements(mainList);
	printFirstElement(mainList);
	addTwoElements(mainList);
	deleteFourthElement(mainList);
	randomThreePositions(mainList);
	deleteLastElement(mainList);
	deleteFirstElement(mainList);
	towElementsInMidle(mainList);
	deleteSameElements(mainList);
	clearList(mainList);
	checkClearList(mainList);


	return 0;
}