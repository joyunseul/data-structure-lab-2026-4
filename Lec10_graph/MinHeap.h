#pragma once

class HeapNode {
    int key;
    int v1, v2;
public:
    HeapNode() : key(0), v1(-1), v2(-1) {}
    HeapNode(int k, int u, int v) : key(k), v1(u), v2(v) {}
    int getKey() { return key; }
    int getV1() { return v1; }
    int getV2() { return v2; }
};

class MinHeap {
    HeapNode node[MAX_ELEMENT];
    int heapSize;
public:
    MinHeap() { heapSize = 0; }
    bool isEmpty() { return heapSize == 0; }
    bool isFull() { return heapSize == MAX_ELEMENT - 1; }

    void insert(int key, int u, int v) {
        if (isFull()) return;
        int i = ++heapSize;
        while (i != 1 && key < node[i / 2].getKey()) {
            node[i] = node[i / 2];
            i /= 2;
        }
        node[i] = HeapNode(key, u, v);
    }

    HeapNode remove() {
        if (isEmpty()) return HeapNode(-1, -1, -1);
        HeapNode root = node[1];
        HeapNode last = node[heapSize--];
        int parent = 1, child = 2;

        while (child <= heapSize) {
            if (child < heapSize && node[child].getKey() > node[child + 1].getKey()) child++;
            if (last.getKey() <= node[child].getKey()) break;
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return root;
    }
};