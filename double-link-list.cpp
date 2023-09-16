#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;
};

Node* insertAtBeginning(Node* head, int newData)
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	if (head != nullptr)
	{
		newNode->next = head;
		head->prev = newNode;
	}

	return newNode;
}

Node* insertAtEnd(Node* head, int newData)
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr)
	{
		return newNode;
	}

	Node* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = newNode;
	newNode->prev = current;

	return head;
}


Node* deleteNode(Node* head, int target)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	if (head->data == target)
	{
		Node* temp = head;

		if (head->next != nullptr)
		{
			head = head->next;
			head->prev = nullptr;
			delete temp;
			return head;
		}
		else
		{
			delete head;
			return nullptr;
		}
	}

	Node* current = head;
	while (current != nullptr && current->data != target)
	{
		current = current->next;
	}

	if (current != nullptr)
	{
		Node* prevNode = current->prev;
		Node* nextNode = current->next;

		if (prevNode != nullptr)
		{
			prevNode->next = nextNode;
		}
		
		if (nextNode != nullptr)
		{
			nextNode->prev = prevNode;
		}
		else
		{
			prevNode->next = nullptr;
		}
		delete current;
	}
	return head;
}

void display(Node* head)
{
	Node* current = head;

	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
}

int main()
{
	Node* head = nullptr;
	head = insertAtBeginning(head, 1);
	head = insertAtBeginning(head, 2);
	head = insertAtBeginning(head, 3);

	head = insertAtEnd(head, 6);
	head = insertAtEnd(head, 5);
	head = insertAtEnd(head, 4);
	
	head = deleteNode(head, 1);
	head = deleteNode(head, 4);

	display(head);

	return 0;
}