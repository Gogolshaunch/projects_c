#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>

using namespace std;

class List {
protected:
    string name;
    int number;
    List* next = nullptr;

public:
    void Set(List* current) {
        next = current;
    }

    List* Get() {
        return next;
    }

    string Getname() {
        return name;
    }

    int Getnum() {
        return number;
    }

    void add(List*& head, string name, int number) {
        List* ex = new List(name, number);

        if (head == nullptr) {
            head = ex;
        }
        else {
            List* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = ex;
        }
    }

    void swap(List*& head)
    {
        if (head == nullptr) {
            cout << "Структура пустая";
        }
        else {
            List* cur = head;
            List* cur2 = head;

            while (cur->next != nullptr)
            {
                cur = cur->next;
            }

            while (cur2->next != cur)
            {
                cur2 = cur2->next;
            }
            cur2->next = nullptr;
            cur->next = head;
            head = cur;
        }
    }

    void print(List*& head)
    {
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }
        else
        {
            List* current = head;
            while (current)
            {
                cout << current->name << "-" << current->number << "\n";
                current = current->next;
            }
        }
    }

    void addfront(List*& head, string name, int number, int n)
    {
        List* ex = new List(name, number);
        List* current = head;

        for (int i = 1; i < n - 1; i++)
        {
            current = current->next;
        }
        if (n == 1)
        {
            ex->next = current;
            head = ex;
        }

        else {
            ex->next = current->next;
            current->next = ex;
        }
    }

    void addafter(List*& head,  string name,  int number, int n)
    {
        List* ex = new List(name, number);
        List* cur = head;

        for (int i = 1; i < n; i++)
        {
            cur = cur->next;
        }
        if (cur != nullptr)
        {
            ex->next = cur->next;
            cur->next = ex;
        }
        else {
            cout << "Это последний элемент, воспользуйтесь функцией add";
        }
    }

    void delhead(List*& head)
    {
        List* cur = head->next;
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }
        else {
            delete head;
            head = cur;
        }
    }

    void delend(List*& head)
    {
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }
        else {
            List* cur = head;
            List* cur2 = head;

            while (cur->next != nullptr)
            {
                cur = cur->next;
            }

            while (cur2->next != cur)
            {
                cur2 = cur2->next;
            }
            cur2->next = nullptr;
            delete cur;
        }
    }

    void delafter(List*& head, int n)
    {
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }
        else {
            List* cur = head;

            for (int i = 1; i < n; i++)
            {
                cur = cur->next;
            }
            List* cur2 = cur->next;

            if (cur->next == nullptr)
            {
                cout << "Это последний элемент";
            }
            else {
                cur->next = cur2->next;
                delete cur2;
            }
        }
    }

    void delfront(List*& head, int n)
    {
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }
        else if (n < 2)
        {
            cout << "Перед этим элементом ничего нет";
        }
        else {
            List* cur = head;

            for (int i = 1; i < n - 1; i++)
            {
                cur = cur->next;
            }
            List* cur2 = head;

            while (cur2->next != cur)
            {
                cur2 = cur2->next;
            }
            cur2->next = cur->next;
            delete cur;
        }
    }

    void del(List*& head, int n)
    {
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }

        else if (n == 1)
        {
            delhead(head);
        }
        else {
            List* cur = head;
            for (int i = 1; i < n; i++)
            {
                cur = cur->next;
            }
            List* cur2 = head;
            while (cur2->next != cur)
            {
                cur2 = cur2->next;
            }
            cur2->next = cur->next;
            delete cur;
        }
    }

    void paste(List*& head,  string name,  int number, int n)
    {
        List* ex = new List(name, number);
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }
        else if (n == 1)
        {
            addfront(head, name, number, n);
        }
        else {
            List* cur = head;
            List* cur2 = head;

            for (int i = 1; i < n; i++)
            {
                cur = cur->next;
            }

            while (cur2->next != cur)
            {
                cur2 = cur2->next;
            }

            if (cur->next == nullptr)
            {
                addafter(head, name, number, n);
            }
            else
            {
                ex->next = cur2->next;
                cur2->next = ex;
            }
        }
    }

    void find(List*& head, string tofind)
    {
        if (head == nullptr)
        {
            cout << "Структура пустая";
        }
        else {
            List* cur = head;
            int count = 1;
            if (cur->name == tofind)
            {
                cout << "\n" << "Объект найден:" << "элемент под номером " << count << ":" << "\n" << cur->name << "-" << cur->number << "\n";
                return;
            }
            count++;
            do {
                cur = cur->next;
                if (cur->name == tofind)
                {
                    cout << "\n" << "Объект найден:" << "элемент под номером " << count << ":" << "\n" << cur->name << "-" << cur->number << "\n";
                    return;
                }
                count++;
            } while (cur->next != nullptr);
            cout << "Элемент не найден!";
        }
    }

    List(string name_, int number_) {
        name = name_;
        number = number_;
    }
};

class Stack : public List {
public:
    Stack(string name_, int number_): List(name_, number_) {    }

    Stack() : List("", 0)
    {
        name = "";
        number = 0;
        next = nullptr;
    }

    void add(List*& head, string name, int number)
    {
        List* new_head = new List(name, number);
        if (head == nullptr) {
            head = new_head;
        }
        else {
            List* current = head;
            head = new_head;
            head->Set(current);
        }
    }
    List* get(List*& head) {
        if (head == nullptr) {
            cout << "Структура пустая" << "\n";
        }
        else {
            return head;
        }
    }
    void look(List * &head) {
        if (head == nullptr) {
            cout << "Структура пустая" << "\n";
        }
        else {
            name = head->Getname();
            number = head->Getnum();
            cout << name << "-" << number << "\n";
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*List* head = nullptr;
    List obj("А", 10);
    obj.add(head, "Ч", 9);
    obj.add(head, "А", 10);
    obj.add(head, "О", 6);
    obj.add(head, "Й", 15);
    obj.add(head, "У", 3);
    obj.add(head, "З", 9);
    obj.add(head, "Ш", 17);
    obj.add(head, "Н", 15);
    obj.add(head, "Т", 1);*/


    List* head = nullptr;
    Stack obj1;
    Stack obj;
    obj1.add(head, "Ч", 9);
    obj1.add(head, "А", 10);
    obj1.add(head, "О", 6);

    obj1.print(head);
    List* str = obj1.get(head);
    cout << str->Getname();
    obj1.look(head);
    return 0;
}
