#include "AdjMatGraph.h"
#include "Wgraph.h"
#include "WGraphMST.h"
#include "WGraphPrim.h"
#include "WGraphDijkstra.h"

int main()
{
	SrchAMGraph g;

	for (int i = 0; i < 8; i++)
		g.insertVertex('A' + i);
	g.insertEdge(0, 1);
	g.insertEdge(0, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);
	g.insertEdge(2, 4);
	g.insertEdge(3, 5);
	g.insertEdge(4, 6);
	g.insertEdge(4, 7);
	g.insertEdge(6, 7);
	printf("인접 행렬로 표현한 그래프\n");
	g.display();
	FILE* fp;
	fopen_s(&fp,"../text_out.txt","w");
	g.display(fp);
	fclose(fp);

	printf("DFS==> ");
	g.resetVisited();
	g.DFS(0);
	printf("\n");

	WGraph mg;
	mg.load(".../graph.txt");
	mg.display();

	return 0;
	
	//WGraphMST n;
	//n.load("graph.txt");
	// printf("입력 그래프: graph.txt\n");
	// g.display("graph.txt");
	//printf("MST By Kruskal's Algorithm\n");
	//n.Kruskal();

	WGraphPrim y;
	y.load("graph.txt");
	printf("MST By Kruskal's Algorithm\n");
	y.Prim(0);
	return 0;

	WGraphDijkstra t;
	t.load("graph.txt");
	printf("MST By Dijkstra's Algorithm\n");
	t.ShortestPath(0);

}


