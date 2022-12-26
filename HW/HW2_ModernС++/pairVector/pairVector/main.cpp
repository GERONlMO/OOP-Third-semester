#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<pair<float, string>> vec = {
	{281.0, "protected"},
	{6157.0, "private"},
	{25.0, "protected"},
	{432.44, "public"},
	{11.20, "public"}
};

void filling() {
	for (auto valuesPair = begin(vec); valuesPair != end(vec); valuesPair++) {
		(*valuesPair).first = rand() % 1001;
		int statusRand = rand() % 3;
		if (statusRand == 0) { (*valuesPair).second = "public"; }
		else if (statusRand == 1) { (*valuesPair).second = "protected"; }
		else { (*valuesPair).second = "private"; }
	}
}

void rebuildVector() {
	auto rebuild = [](auto& valuesPair) {
		if (valuesPair.second == "public") {
			valuesPair.first = 0;
		}
		else if (valuesPair.second == "protected") {
			valuesPair.second = "private";
		}
	};
	for (auto& thisVector : vec) { rebuild(thisVector); }
}

void print() {
	for (auto valuesPair : vec) {
		cout << valuesPair.first << "\t";
		if (valuesPair.second == "public") {
			cout << "public" << endl;
		}
		else if (valuesPair.second == "protected") {
			cout << "protected" << endl;
		}
		else
		{
			cout << "private" << endl;
		}
	}
	cout << endl;
}


int main() {
	srand(time(0));

	print();
	rebuildVector();
	print();

	filling();
	print();
	rebuildVector();
	print();

	return 0;
}