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

	void isFull() {
		Node* newNode = new Node();
		if (newNode == NULL)
			cout << "Sorr, stack is full\n";
	}

	bool isEmpty() {
		if (top == NULL)
			return true;
		else
			return false;
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
			cout << temp->data << " ";
			temp = temp->link;
		}
		cout << "\n";
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
};

int main() {
	Stack s;
	int data;
	int item;

	//push & display
	cout << "Enter Number of item\n";
	cin >> item;
	while (item) {
		cout << "Enter data to push\n";
		cin >> data;
		s.push(data);
		s.display();
		item--;
	}
	
	//pop & display
	cout << s.pop() << " is removed \n";
	s.display();

	//peek
	cout << "peek is " << s.peek() << "\n";

	//search
	cout << "Enter data to search\n";
	cin >> data;
	if (s.isFound(data))
		cout << data << " is founded\n";
	else
		cout << data << " not found\n";

	//count
	cout << "Number of items is " << s.count() << "\n";

	return 0;
}