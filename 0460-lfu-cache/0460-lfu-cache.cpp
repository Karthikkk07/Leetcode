class LFUCache {
public:

    struct Node {
        int key;
        int value;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    struct DLL {
        Node* head;
        Node* tail;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        Node* removeLast() {
            if (head->next == tail) {
                return nullptr;
            }
            Node* node = tail->prev;
            remove(node);
            return node;
        }
        bool empty() {
            return head->next == tail;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void increaseFreq(Node* node) {

        int oldFreq = node->freq;
        freqMap[oldFreq]->remove(node);
        if (oldFreq == minFreq &&
            freqMap[oldFreq]->empty()) {
            minFreq++;
        }
        node->freq++;
        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DLL();
        }
        freqMap[node->freq]->addFront(node);
    }


    int get(int key) {

        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        Node* node = keyMap[key];
        increaseFreq(node);
        return node->value;
    }


    void put(int key, int value) {

        if (capacity == 0) {
            return;
        }
        if (keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];
            node->value = value;
            increaseFreq(node);
            return;
        }
        if (keyMap.size() == capacity) {
            DLL* list = freqMap[minFreq];
            Node* nodeToRemove = list->removeLast();
            keyMap.erase(nodeToRemove->key);
            delete nodeToRemove;
        }
        Node* newNode = new Node(key, value);
        keyMap[key] = newNode;
        if (freqMap.find(1) == freqMap.end()) {
            freqMap[1] = new DLL();
        }
        freqMap[1]->addFront(newNode);
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */