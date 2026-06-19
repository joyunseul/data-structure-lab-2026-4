#pragma once
#define MAX_ELEMENT 200

class HeapNode {
    int key;    // Key 값: 간선의 가중치
    int v1;     // 정점 1
    int v2;     // 정점 2
public:
    HeapNode(int k, int u, int v) : key(k), v1(u), v2(v) { }
    void setKey(int k) { key = k; }
    int getKey() { return key; }
    int getV1() { return v1; }
    int getV2() { return v2; }
};


class MinHeap {
    HeapNode node[MAX_ELEMENT];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }

    HeapNode& getParent(int i) { return node[i / 2]; }

    void insert(int key, int u, int v) {
        if (isFull()) return;
        int i = ++size;
        while (i != 1 && key < getParent(i).getKey()) {
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key, u, v);
    }

    HeapNode remove() {
        if (isEmpty()) return HeapNode(-1, -1, -1);

        HeapNode root = node[1];
        HeapNode last = node[size--];

        int parent = 1;
        int child = 2;

        while (child <= size) {
            if (child < size && node[child].getKey() < node[child + 1].getKey()) {
                child++;
            }
            if (last.getKey() <= node[child].getKey()) {
                break;
            }

            node[parent] = node[child];
            parent = child;
            child *= 2;
        }

        node[parent] = last;
        return root;
    }
};
