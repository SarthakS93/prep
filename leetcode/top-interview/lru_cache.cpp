#include<iostream>
#include<unordered_map>
using namespace std;


class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->prev = NULL;
            this->next = NULL;
        }
};


class LruCache {
    private:
        unordered_map<int, Node*> lookupTable;
        Node* head;
        Node* tail;
        int size;

        void addToList(Node* node) {
            node->next = head;
            node->prev = NULL;
            if (head != NULL) {
                head->prev = node;
            }
            head = node;
            if (tail == NULL) {
                tail = head;
            }
        }

        void removeFromList(Node* node) {
            if (node == tail) {
                removeFromEnd();
                return;
            }
            Node* previousNode = node->prev;
            Node* nextNode = node->next;
            previousNode->next = nextNode;
            nextNode->prev = previousNode;
            node->next = NULL;
            node->prev = NULL;
        }

        int removeFromEnd() {
            int key = tail->key;
            Node* nodeBeforeTail = tail->prev;
            nodeBeforeTail->next = NULL;
            tail = nodeBeforeTail;
            return key;
        }


    public:

        LruCache(int size) {
            this->head = NULL;
            this->tail = NULL;
            this->size = size;
        }

        int get(int key) {
            cout<<"Get for key "<<key<<endl;
            unordered_map<int, Node*>::iterator it = lookupTable.find(key);
            if (it == lookupTable.end()) {
                return -1;
            }
            else {
                Node* node = it->second;
                removeFromList(node);
                addToList(node);
                printCacheContents();
                return node->key;
            }
        }

        void set(int key, int value) {
            cout<<"Set key "<<key<<endl;
            unordered_map<int, Node*>::iterator it = lookupTable.find(key);
            Node* node = NULL;
            if (it == lookupTable.end()) {
                node = new Node(key, value);
                lookupTable.insert({key, node});
                if (lookupTable.size() > size) {
                    int keyOfRemovedElement = removeFromEnd();
                    lookupTable.erase(keyOfRemovedElement);
                }
            }
            else {
                node = it->second;
                removeFromList(node);
            }
            addToList(node);
            printCacheContents();
        }

        void printCacheContents() {
            cout<<"Cache contents are as follows: "<<endl;
            Node* p = head;
            while (p != NULL) {
                cout<<p->key<<" ";
                p = p->next;
            }
            cout<<endl;
        }

        void printCacheContentsExtra() {
            cout<<"Cache contents are as follows: "<<endl;
            Node* p = head;
            while (p != NULL) {
                cout<<p->key<<" ";
                p = p->next;
            }
            cout<<endl;
        }       
};




int main() {

    LruCache lruCache(4);
    cout<<"Started"<<endl;
    lruCache.printCacheContents();
    int op = 0, key;
    while (op != -1) {
        cout<<"Enter operation, 1 for get and 2 for set and also enter key"<<endl;
        cin>>op>>key;
        if (op == 1) {
            int res = lruCache.get(key);
            cout<<"Result is "<<res<<endl;
        }
        else {
            lruCache.set(key, key);
        }
    }


    return 0;
}
