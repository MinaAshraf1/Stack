//Stack linked list by Mina Ashraf

#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* link;

	Node() {
		data = 0;
		link = NULL;
	}
};

class Stack {
private:
	Node* top;

public:
	Stack() {
		top = NULL;
	}

	void push(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		if (isEmpty()) {
			top = newNode;
			newNode->link = NULL;
		}
		else {
			newNode->link = top;
			top = newNode;
		}
	}

	int pop() {
		Node* temp = top;
		int data = top->data;
		top = top->link;
		delete temp;
		return data;
	}

	int peek() {
		return top->data;
	}

	void display() {
		Node* temp = top;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->link;
		}
		cout << "\n";
	}

	void isFull() {
		Node* newNode = new Node();
		if (newNode == NULL)
			cout << "Sorry, stack is full\n";
	}

	bool isEmpty() {
		if (top == NULL)
			return true;
		else
			return false;
	}

	bool isFound(int data) {
		Node* temp = top;
		while (temp != NULL) {
			if (temp->data == data)
				return true;
			temp = temp->link;
		}
		return false;
	}

	int count() {
		int counter = 0;
		Node* temp = top;
		while (temp != NULL) {
			counter++;
			temp = temp->link;
		}
		return counter;
	}

	void clear() {
		while (top != NULL)
			pop();
	}
};

int main() {
	Stack s;
	int data;
	int item;

	//push
	cout << "Enter Number of item\n";
	cin >> item;
	while (item) {
		cout << "Enter data to push\n";
		cin >> data;
		s.push(data);
		item--;
	}
	cout << ".......................................................\n";

	//display
	cout << "Stack is:\n";
	s.display();
	cout << ".......................................................\n";

	//pop
	cout << s.pop() << " is removed \n";

	//display
	cout << "Stack after deleted:\n";
	s.display();
	cout << ".......................................................\n";

	//peek
	cout << "peek is " << s.peek() << "\n";
	cout << ".......................................................\n";

	//search
	cout << "Enter data to search\n";
	cin >> data;
	if (s.isFound(data))
		cout << data << " is founded\n";
	else
		cout << data << " not found\n";
	cout << ".......................................................\n";

	//count
	cout << "Number of items is " << s.count() << "\n";
	cout << ".......................................................\n";

	//clear
	s.clear();
	cout << "stack after clear is:\n";
	cout << ".......................................................\n";

	return 0;
}