#include <iostream>
#include <stack>
#include <list>

using namespace std;

void putElementInStack(stack<int>& temp) {
	int a;
	cout << endl << "Enter a number:" << endl;
	cin >> a;
	temp.push(a);
	cout << "Element: " << a << " was add in stack\n" << endl;
}

void deleteElementFromStack(stack<int>& temp) {
	if (!(temp.empty())) {
		cout << endl << "Element: " << temp.top() << " was deleted\n" << endl;
		temp.pop();
	}
	else {
		cout << endl << "Stack is empty!\n" << endl;
	}
}

void printStack(stack<int>& temp) {
	if (!(temp.empty())) {
		list<int> helpList1;

		cout << endl << "|\t" << " \t" << "|" << endl;

		while (!(temp.empty())) {
			helpList1.push_front(temp.top());
			temp.pop();
		}

		list<int> helpList2 = helpList1;

		for (auto e = helpList1.begin(); e != helpList1.end(); e++) {
			cout << endl << "|\t" << helpList2.back() << "\t" << "|" << endl;
			helpList2.pop_back();
		}

		while (!helpList1.empty()) {
			temp.push(helpList1.front());
			helpList1.pop_front();
		}
	}
	else {
		cout << endl << "Stack is empty!\n" << endl;
	}
}

void clearStack(stack<int>& temp) {
	if (!(temp.empty())) {
		for (int i = 0; i < temp.size(); i++) {
			temp.pop();
		}
	}
	else {
		cout << endl << "Stack is empty!\n" << endl;
	}
}

void exitProgramm() {
	exit(0);
}

void menu(int a, stack<int>& temp) {
	switch (a)
	{
	case 1:
		putElementInStack(temp);
		break;
	case 2:
		deleteElementFromStack(temp);
		break;
	case 3:
		printStack(temp);
		break;
	case 4:
		clearStack(temp);
		break;
	case 5:
		exitProgramm();
		break;
	default:
		cout << endl << "There is no such command! " << endl;
		break;
	}
}

int main() {
	stack <int> mainSteck;
	int command;

	while (true)
	{
		cout << "Select command." << endl;
		cout << "1. Add element to stack." << endl;
		cout << "2. Remove an element from the stack." << endl;
		cout << "3. Show stack elements." << endl;
		cout << "4. Clear stack." << endl;
		cout << "5. Exit." << endl;

		cin >> command;

		menu(command, mainSteck);
	}

	return 0;
}