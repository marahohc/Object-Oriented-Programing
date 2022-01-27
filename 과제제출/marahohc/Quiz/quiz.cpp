#include <iostream>
#include <cstring>
using namespace std;

class Node {
private:
    char word[20];
    Node* next;
public:
    Node() {
        next = NULL;
    }
    void setword(char* WORD) { strcpy(word, WORD); }
    char* getword() { return word; }
    Node* getnext() { return next; }
    void setnext(Node* NEXT) { next = NEXT; }
};

class List {
private:
    Node* word;
    Node* head;
public:
    List() {
        word = NULL;
        head = NULL;
    }
    void Insert(char* WORD);
    void Print();
};

void List::Insert(char* word) {
    Node* node1 = new Node;
    node1->setword(word);
    Node* curnode = new Node;
    Node* prevnode = new Node;
    curnode = head;
    if (head == NULL) {
        head = new Node;
        return;
    }
    while (curnode->getnext() != NULL) {
        if (node1->getword()[0] > curnode->getword()[0]) {
            prevnode->setnext(node1);
            node1->setnext(curnode);
            return;
        }
        else if ((int)node1->getword()[0] < (int)curnode->getword()[0]) {
            prevnode->setnext(curnode);
            curnode = curnode->getnext();
            return;
        }
        else if (node1->getword()[0] == curnode->getword()[0]) {
            int i = 1;
            while (node1->getword()[i] == curnode->getword()[i]) {
                i++;
            }
            if (node1->getword()[i] > curnode->getword()[i]) {
                prevnode->setnext(node1);
                node1->setnext(curnode);
                return;
            }
            else if (node1->getword()[i] < curnode->getword()[i]) {
                prevnode->setnext(curnode);
                curnode = curnode->getnext();
                return;
            }
        }
        prevnode->setnext(curnode);
        curnode = curnode->getnext();
    }
}

void List::Print() {
    Node* node = new Node;
    node = head;
    if(head = NULL)
        head = new Node;
    int i = 0;
    cout << i << ". " << node->getword() << endl;
    node = node->getnext();
}

int main(void) {
    Node* word = new Node;
    List* list = new List;
    string insert;
    char* insertword = new char;

    while (1) {
        cin >> insert;
        if (insert == "INSERT") {
            cin >> insertword;
            list->Insert(insertword);
            list->Print();
        }
        else if (insert == "FIND") {

        }

        else if (insert == "END") {

        }
        
        else {
            cout << "Comment Error. Insert Again" << endl;
        }
    }

    delete word;
    delete list;
    delete[] insertword;
}