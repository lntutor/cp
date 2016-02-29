// https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights
import java.io.*;
import java.util.*;

public class Solution {

	public static class Query {
		int from;
		int to;
		public Query(int from, int to){
			this.from = from;
			this.to = to;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader ob=new BufferedReader(new InputStreamReader(System.in));
		int nodes,edges,numOfQuery;

		int from, to,weight;
		String line = ob.readLine();
		List<Query> queryQueue = new LinkedList<>();

		String [] array = line.split(" ");
		nodes = Integer.parseInt(array[0]);
		AdjacentMatrixGraph graph = new AdjacentMatrixGraph(nodes);
		edges = Integer.parseInt(array[1]);
		for (int j = 0; j < edges; j++) {
			line = ob.readLine();
			array = line.split(" ");
			from = Integer.parseInt(array[0]) -1;
			to = Integer.parseInt(array[1]) -1;
			weight = Integer.parseInt(array[2]);
			graph.addEdge(from, to, weight);
		}
		numOfQuery = Integer.parseInt(ob.readLine());
		while(numOfQuery-->0){
			line = ob.readLine();
			String [] tmp = line.split(" ");
			from = Integer.parseInt(tmp[0]) - 1;
			to = Integer.parseInt(tmp[1]) - 1;
			queryQueue.add(new Query(from, to));
		}
		WarShallFloyd warShallFloyd = new WarShallFloyd(graph);
		warShallFloyd.findShortestPath();
		for (Query query: queryQueue) {
			warShallFloyd.printShortestPath(query.from, query.to);
		}
		//}
	}


	public static class AdjacentMatrixGraph {

		private int V;// number of vertex

		public boolean [][] adjacent;
		public int [][] distance;

		public int getVertexCount(){
			return V;
		}

		public boolean [][] getAdjacentMatrix(){
			return adjacent;
		}

		public int [][] getDistanceMatrix(){
			return distance;
		}

		public AdjacentMatrixGraph(int V){
			adjacent = new boolean [V][V];
			distance = new int [V][V];
			this.V = V;
			resetGraph();
		}

		private void resetGraph(){
			for (int i =0; i< V; i++) {
				for (int j = 0; j < V; j++) {
					adjacent[i][j] = false;
					distance[i][j] = -1;
				}
			}
		}

		public void addEdge(int u, int v, int distance){
			adjacent[u][v] = true;
			this.distance[u][v] = distance;
//			adjacent[v][u] = true;
//			this.distance[v][u] = distance;
		}

	}

	public static class Vertex implements Comparable<Vertex> {
		public int minDistance = Integer.MAX_VALUE;
		public Vertex previous;
		int name;
		public Vertex(int name, int minDistance) {
			this.name = name;
			this.minDistance = minDistance;
		}
		@Override
		public int compareTo(Vertex other) {
			return Integer.compare(minDistance, other.minDistance);
		}
	}

	public static class WarShallFloyd {
		AdjacentMatrixGraph graph;
		int [][] shortestDistance;
		//int [] prev;
		int V;
		int source;
//		boolean [] visited;


		public WarShallFloyd (AdjacentMatrixGraph graph){
			this.graph = graph;
			this.V = graph.V;
			shortestDistance = new int[V][V];
			//prev = new int[V];
//			visited = new boolean[V];
			for (int i = 0; i < V; i++){
				for (int j = 0; j < V; j++) {
					shortestDistance[i][j] = 99999;
					if (graph.adjacent[i][j]) shortestDistance[i][j] = graph.distance[i][j];
				}
				shortestDistance[i][i] = 0;
			}
		}

		public void findShortestPath() {
			for (int k = 0; k < V; k++) {
				for (int i = 0; i < V; i++) {
					for (int j = 0; j < V; j ++) {

						if (shortestDistance[i][j] > shortestDistance[i][k] + shortestDistance[k][j]) {
							shortestDistance[i][j] = shortestDistance[i][k] + shortestDistance[k][j];
						}
					}
				}
			}

		}

		public void printShortestPath(int from, int to){
			System.out.println(shortestDistance[from][to] != 99999 ? shortestDistance[from][to] : -1);
		}
	}
}