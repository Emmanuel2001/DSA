#include "pch.h"
#include "ListP.h"

ListP::ListP()
{
	Head = NULL;
	size = 0;
}


ListP::~ListP()
{
}

bool ListP::add(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (Head == NULL) {
		Head = newNode;
	}
	else {
		Node* current = Head;
		Node* previous = Head;
		while (current != NULL) {
			previous = current;
			current = current->next;
		}
		previous->next = newNode;
	}
	size++;

	return true;
}

bool ListP::add(int index, ItemType item) {
	if (index >= 0 && index <= size) {
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 0) {
			newNode->next = Head;
			Head = newNode;
		}
		else {
			Node* current = Head;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;

		}
		size++;
		return true;
	}
	else
		return false;
}

void ListP::remove(int index) {
	if (index >= 0 && index <= size) {
		if (index == 0) {
			Head = Head->next;
		}
		else {
			Node* current = Head;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			current->next = current->next->next;

		}
		size--;
	}
}

ItemType ListP::get(int index)
{
	ItemType item;
	bool success = (index >= 0) && (index < size);
	if (success) {
		Node* current = Head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		item = current->item;
	}

	return item;
}

bool ListP::isEmpty() { return size == 0; }

int ListP::getLength() { return size; }

void ListP::print()
{
}


