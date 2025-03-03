#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;
struct Node {
    int key;
    int value;
    weak_ptr<Node> prev;
    shared_ptr<Node> next;
    Node(int k, int v) : key(k), value(v) {}
};
class LRUCache {
public:
    LRUCache(int cap) : capacity(cap) {
        head = make_shared<Node>(-1, -1);
        tail = make_shared<Node>(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int k) {
        auto it = cacheMap.find(k);
        if (it == cacheMap.end()) return -1;
        auto nodePtr = it->second.lock();
        if (!nodePtr) {
            cacheMap.erase(k);
            return -1;
        }
        moveToFront(nodePtr);
        return nodePtr->value;
    }
    void put(int k, int v) {
        auto it = cacheMap.find(k);
        if (it != cacheMap.end()) {
            auto nodePtr = it->second.lock();
            if (nodePtr) {
                nodePtr->value = v;
                moveToFront(nodePtr);
                return;
            } else {
                cacheMap.erase(it->first);
            }
        }
        auto newNode = make_shared<Node>(k, v);
        insertAfter(head, newNode);
        cacheMap[k] = weak_ptr<Node>(newNode);
        if (cacheMap.size() > capacity) evictLast();
    }
    void printCache() {
        cout << "Cache actuel: ";
        auto cur = head->next;
        while (cur && cur != tail) {
            cout << cur->key << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int capacity;
    unordered_map<int, weak_ptr<Node>> cacheMap;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    void insertAfter(shared_ptr<Node> node, shared_ptr<Node> newNode) {
        auto temp = node->next;
        node->next = newNode;
        newNode->prev = node;
        newNode->next = temp;
        temp->prev = newNode;
    }
    void removeNode(shared_ptr<Node> node) {
        auto p = node->prev.lock();
        auto n = node->next;
        if (p) p->next = n;
        if (n) n->prev = p;
    }
    void moveToFront(shared_ptr<Node> node) {
        removeNode(node);
        insertAfter(head, node);
    }
    void evictLast() {
        auto lastNode = tail->prev.lock();
        if (!lastNode || lastNode == head) return;
        int oldKey = lastNode->key;
        removeNode(lastNode);
        cacheMap.erase(oldKey);
        lastNode.reset();
    }
};
int main() {
    LRUCache cache(4);
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);
    cout << "get(1) => " << cache.get(1) << endl;
    cache.put(4, 400);
    cache.printCache();
    cache.put(5, 500);
    cache.printCache();
    return 0;
}