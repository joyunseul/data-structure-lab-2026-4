#pragma once
#include "Wgraph.h"

class WGraphPrim : public WGraph {
public:
	int getMintez(bool* selected, int* dist) {
		int minv = 0;
		int mindist = INF;
		for (int v = 0; v < size; v++)
			if (!selected[v] && dist[v] < mindist) {
				mindist = dist[v];
				minv = v;
			}
		return minv;
	}

	void Prim(int s) {
		bool seleted[MAX_VTXS];
		int dist[MAX_VTXS];

		for (int i = 0; i < size; i++) {
			dist[i] = INF;
			seleted[i] = false;
		}
		dist[s] = 0;

		for (int i = 0; i < size; i++) {
			int u = getMinVertex(seleted, dist);
			seleted[u] = true;
			if (dist[u] == INF) return;
			printf("%c", getVertex(u));

			for (int v = 0; v < size; v++)
				if (getEdge(u, v) != INF)
					if (!seleted[v] && getEdge(u, v) < dist[v])
						dist[v] = getEdge(u, v);
		}
		printf("\n");
	}
};