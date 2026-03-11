#include <iostream>
#include <algorithm>

using namespace std;

class Node {
private:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
public:
    Node(int data_) {
        data = data_;
    }
    void SetLeft(Node* left_) {
        left = left_;
    }

    void SetRight(Node* right_) {
        right = right_;
    }

    Node* GetLeft() {
        return left;
    }
    Node* GetRight() {
        return right;
    }
    int GetData() {
        return data;
    }
    void SetData(int data_) {
        data = data_;
    }
};

class BTree {
public:
    Node* root;
    BTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert_func(root, value);
    }

    Node* insert_func(Node* root_, int value) {
        if (root_ == nullptr) {
            return new Node(value);
        }
        if (value < root_->GetData()) {
            root_->SetLeft(insert_func(root_->GetLeft(), value));
        }
        if (value > root_->GetData()) {
            root_->SetRight(insert_func(root_->GetRight(), value));
        }

        return root_;
    }

    void print() {
        print_f(root, 0);
    }

    void delete_node(int data_) {
        deleteNode(root, data_);
    }

    void print_f(Node* root_, int space) {
        if (root_ == nullptr) {
            return;
        }
        space += 5;
        print_f(root_->GetRight(), space);
        for (int i = 0; i < space; i++) {
            cout << " ";
        }
        cout << root_->GetData() << "\n";
        print_f(root_->GetLeft(), space);
    }

    void print_p(Node* root_) {
        if (root_ == nullptr) {
            return;
        }
        cout << root_->GetData() << "\t";
        print_p(root_->GetLeft());
        print_p(root_->GetRight());
    }

    void print_s(Node* root_) {
        if (root_ == nullptr) {
            return;
        }
        print_s(root_->GetLeft());
        cout << root_->GetData() << "\t";
        print_s(root_->GetRight());
    }

    void print_r(Node* root_) {
        int flag = 0;
        if (root_ == nullptr) {
            return;
        }
        print_r(root_->GetLeft());
        flag++;
        print_r(root_->GetRight());
        flag++;
        if (flag == 2) {
            cout << root_->GetData() << "\t";
        }
    }
    Node* minValueNode(Node* node) {
        Node* cur = node;
        while (cur && cur->GetLeft() != nullptr) {
            cur = cur->GetLeft();
        }
        return cur;
    }

    Node* deleteNode(Node* root_, int data) {
        if (root_ == nullptr) {
            return root_;
        }
        if (data > root_->GetData()) {
            root_->SetRight(deleteNode(root_->GetRight(), data));
        }
        else if (data < root_->GetData()) {
            root_->SetLeft(deleteNode(root_->GetLeft(), data));
        }
        else {
            if (root_->GetLeft() == nullptr) {
                return root_->GetRight();
            }
            else if (root_->GetRight() == nullptr) {
                return root_->GetLeft();
            }
            Node* c = minValueNode(root_->GetRight());
            root_->SetData(c->GetData());
            root_->SetRight(deleteNode(root_->GetRight(), c->GetData()));
        }
        return root_;
    }

    int hight() {
        return hightTree(root);
    }

    int hightTree(Node* root_) {
        if (root_ == nullptr) {
            return -1;
        }
        int count = hightTree(root_->GetLeft());
        int count1 = hightTree(root_->GetRight());
        return 1+max(count, count1);
    }
};

int main()
{
    BTree obj;
    obj.insert(10);
    obj.insert(8);
    obj.insert(14);
    obj.insert(16);
    obj.insert(15);
    obj.insert(12);
    obj.insert(9);
    obj.insert(6);
    obj.insert(7);
    obj.insert(4);
    obj.print();
    cout << obj.hight();
    return 0;
}
