#include "AdjMatGraph.h"
#include "WGraph.h"
#include "WGraphMST.h"
#include "WGraphPrim.h"
#include "WGraphDijkstra.h"

int main() {
	// 1. 인접 행렬 기본 그래프 테스트
	printf("=== [1] 기본 인접 행렬 DFS 테스트 ===\n");
	SrchAMGraph g;
	for (int i = 0; i < 8; i++) g.insertVertex('A' + i);
	g.insertEdge(0, 1); g.insertEdge(0, 2);   g.insertEdge(1, 3);
	g.insertEdge(2, 3);   g.insertEdge(2, 4);   g.insertEdge(3, 5);
	g.insertEdge(4, 6);   g.insertEdge(4, 7);   g.insertEdge(6, 7);

	printf("인접 행렬 그래프 구조:\n");
	g.display();
	printf("DFS 탐색 결과==> ");
	g.resetVisited();
	g.DFS(0);
	printf("\n\n");

	// 2. 가중치 그래프 데이터 확인
	printf("=== [2] 가중치 그래프 데이터 로드 ===\n");
	WGraph mg;
	mg.loadInMemory();
	mg.display();
	printf("\n");

	// 3. Kruskal's MST
	printf("=== [3] MST By Kruskal's Algorithm ===\n");
	WGraphMST n;
	n.loadInMemory();
	n.Kruskal();
	printf("\n");

	// 4. Prim's MST
	printf("=== [4] MST By Prim's Algorithm ===\n");
	WGraphPrim y;
	y.loadInMemory();
	printf("방문 정점 순서: ");
	y.Prim(0);
	printf("\n");

	// 5. Dijkstra's Shortest Path
	printf("=== [5] Shortest Path By Dijkstra's Algorithm ===\n");
	WGraphDijkstra t;
	t.loadInMemory();
	t.ShortestPath(0);

	return 0;
}