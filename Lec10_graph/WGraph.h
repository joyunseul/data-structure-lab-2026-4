#pragma once
#include "AdjMatGraph.h"

class WGraph : public AdjMatGraph {
public:
    void insertEdge(int u, int v, int weight) {
        if (weight > INF) weight = INF;
        setEdge(u, v, weight);
    }
    bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }

    // 메모리에서 오리지널 가중치 그래프 데이터를 직접 주입
    void loadInMemory() {
        reset();

        char names[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
        for (int i = 0; i < 7; i++) {
            insertVertex(names[i]);
        }

        int grid[7][7] = {
           {0, 7, 9999, 9999, 3, 10, 9999},
           {7, 0, 4, 10, 2, 6, 9999},
           {9999, 4, 0, 2, 9999, 9999, 9999},
           {9999, 10, 2, 0, 11, 9, 4},
           {3, 2, 9999, 11, 0, 9999, 5},
           {10, 6, 9999, 9, 9999, 0, 9999},
           {9999, 9999, 9999, 4, 5, 9999, 0}
        };

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                insertEdge(i, j, grid[i][j]);
            }
        }
    }
};
