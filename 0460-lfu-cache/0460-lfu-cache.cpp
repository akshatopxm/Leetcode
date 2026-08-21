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
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyMap;

    unordered_map<int, list<Node*>> freqMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void removeNode(Node* node) {
        int f = node->freq;

        freqMap[f].remove(node);
    }

    void addNode(Node* node) {
        freqMap[node->freq].push_front(node);
    }

    void increaseFreq(Node* node) {

        int oldFreq = node->freq;

        removeNode(node);

        if (oldFreq == minFreq && freqMap[oldFreq].empty()) {
            minFreq++;
        }

        node->freq++;

        addNode(node);
    }

    int get(int key) {

        if (keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];

        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];

            node->value = value;

            increaseFreq(node);

            return;
        }

        // Cache is full
        if (keyMap.size() == capacity) {

            Node* lruNode = freqMap[minFreq].back();

            keyMap.erase(lruNode->key);

            freqMap[minFreq].pop_back();

            delete lruNode;
        }

        // Insert new node
        Node* newNode = new Node(key, value);

        keyMap[key] = newNode;

        minFreq = 1;

        freqMap[1].push_front(newNode);
    }
};