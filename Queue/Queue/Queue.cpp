// Queue.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;
class queue {
private:
	struct node {
		int value;
		node *next;
	};
	node *head = nullptr;
	node *tail = nullptr;
	unsigned int queueSize = 0;
public:
	void enqueue(int elem) {
		auto obj = new node{ elem, nullptr };
		if (queueSize == 0) {
			head = obj;
		}
		else {
			(*tail).next = obj;
		}
		tail = obj;
		++queueSize;
	}
	int dequeue() {
		if (queueSize != 0) {
			node *newhead = (*head).next;
			int dequeuedElement = (*head).value;
			delete(head);
			head = newhead;
			--queueSize;
			return dequeuedElement;
		}
	}
	bool empty() { return queueSize == 0; }
	~queue();
};
queue::~queue() {
	cout << "Deleting queue .. " << endl;
	while (queueSize != 0) {
		cout << "deleted element is: " << dequeue() << endl;
	}
}
int main()
{
	queue myQueue;
	int status = 1, c, elem;
	while (status) {
		cout << "Enter what you want to do with the queue: " << endl
			<< "1) dequque element from queue" << endl
			<< "2) enqueue element into queue" << endl;
		cin >> c;
		switch (c) {
		case 1:
			if (myQueue.empty())
				cout << "Cannot dequque element from queue" << endl;
			else {
				cout << "Dequeued element is: " << myQueue.dequeue() << endl;
			}
			break;
		case 2:
			cout << "Enter value you want to enqueue into queue: " << endl;
			cin >> elem;
			myQueue.enqueue(elem);
			break;
		default:
			cerr << "No such operation is available" << endl;
		}
		cout << "Would you like to continue? Enter 1 for YES, 0 for NO" << endl;
		cin >> c;
		if (c == 0) { break; }
	}
	return 0;
}