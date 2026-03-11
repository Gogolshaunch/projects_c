#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Node {
private:
	Node* next = nullptr;
	Node* pr = nullptr;
	int num;
public:
	Node(int num_) {
		num = num_;
	}
	void SetNext(Node* next_) {
		next = next_;
	}

	void Setpr(Node* pr_) {
		pr = pr_;
	}

	Node* Getnext() {
		return next;
	}
	Node* Getpr() {
		return pr;
	}
	int GetNum() {
		return num;
	}
};

class DoubleLinkedList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;

public:
	void SetHead(Node* head_) {
		head = head_;
	}

	void SetTail(Node* tail_) {
		tail = tail_;
	}

	Node* GetHead() {
		return head;
	}
	Node* GetTail() {
		return tail;
	}
	DoubleLinkedList(Node* head_, Node* tail_) {
		head = head_;
		tail = tail_;
	}
	DoubleLinkedList() {	}

	void add_new_tail(int num_) {
		Node* obj = new Node(num_);
		if (head == nullptr) {
			head = obj;
			tail = obj;
		}
		else {
			tail->SetNext(obj);
			obj->Setpr(tail);
			tail = obj;
		}
	}

	void del_tail() {
		if (head == nullptr)
		{
			cout << "Структура пустая" << "\n";
		}
		else {
			tail = tail->Getpr();
			tail->SetNext(nullptr);
		}
	}

	void del_after(int num_) {
		if (head == nullptr)
		{
			cout << "Структура пустая" << "\n";
		}
		else {
			Node* cur = head;

			while (cur->GetNum() != num_) {
				cur = cur->Getnext();
			}
			if (cur->Getnext() == nullptr) {
				cout << "Это был последний элемент!" << "\n";
			}
			else {
				Node* cur2 = cur->Getnext();
				Node* cur0 = cur->Getpr();
				cur0->SetNext(cur2);
				cur2->Setpr(cur0);
			}
		}
	}

	void add_new_head(int num_) {
		Node* obj = new Node(num_);
		if (head == nullptr) {
			head = obj;
			tail = obj;
		}
		else {
			obj->SetNext(head);
			head->Setpr(obj);
			head = obj;
		}
	}

	void size_list() {
		if (head == nullptr)
		{
			cout << "Структура пустая. 0 элементов" << "\n";
		}
		else
		{
			int count = 0;
			Node* current = head;
			while (current)
			{
				count++;
				current = current->Getnext();
			}
			cout << count << "  элементов" << "\n";
		}
	}

	bool find_el(int el) {
		if (head == nullptr)
		{
			cout << "Структура пустая" << "\n";
		}
		else {
			Node* cur = head;
			if (cur->GetNum() == el)
			{
				cout << "\n" << "Объект найден:" << cur->GetNum() << "\n";
				return true;
			}
			do {
				cur = cur->Getnext();
				if (cur->GetNum() == el)
				{
					cout << "\n" << "Объект найден:" << cur->GetNum() << "\n";
					return true;
				}
			} while (cur->Getnext() != nullptr);

			cout << "Элемент не найден!" << "\n";
			return false;
		}
	}

	void print(){
		if (head == nullptr)
		{
			cout << "Структура пустая" << "\n";
		}
		else
		{
			Node* current = head;
			while (current)
			{
				cout << current->GetNum() << "\t";
				current = current->Getnext();
			}
			cout << "\n";
		}
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DoubleLinkedList obj;
	obj.add_new_tail(5);
	obj.add_new_tail(6);
	obj.add_new_tail(7);
	obj.add_new_tail(8);
	obj.add_new_tail(9);

	obj.add_new_head(15);
	obj.print();
	obj.size_list();
	obj.del_after(6);
	obj.del_tail();
	obj.print();
	return 0;
}
