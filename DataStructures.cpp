#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node(int nodeValue) : data(nodeValue), next(nullptr) {}
		Node() : data(0), next(nullptr) {}
};

class LinkedList
{
	private:
		Node* head;
		int size{ 0 };
	public:
		LinkedList(int data)
		{
			head = new Node{ data };
			size++;
		}
		LinkedList()
		{
			head = nullptr;
		}
		~LinkedList() {
			Node* current = head;
			while (current != nullptr) {
				Node* next = current->next;
				delete current;
				current = next;
			}
		}

		bool insertValueAtEnd(int value)
		{
			if (head == nullptr)
			{
				head = new Node{ value };
				size++;
				return true;
			}
			else
			{
				Node* tempHead = head;
				while (tempHead->next != nullptr)
				{
					tempHead = tempHead->next;
				}
				tempHead->next = new Node{ value };
				size++;
				cout << "Node added" << endl;
				return true;
			}
			return false;
		}
		void display()
		{
			if (head == nullptr)
			{
				cout << "----- LinkedList is empty -----" << endl;
			}
			else
			{
				Node* temp = head;

				cout << "----- LinkedList contains -----" << endl;
				for (int i = 0; i < size; i++)
				{
					cout << "Node value: " << temp->data << " at index " << i << endl;
					temp = temp->next;
				}
			}
		}
};

int main()
{
	Node* n1 = new Node{ 3 };
	Node* n2 = new Node{ 7 };
	Node* n3 = new Node{ 11 };
	LinkedList testLL = LinkedList(1);
	testLL.insertValueAtEnd(2);
	testLL.display();
	return 0;
}