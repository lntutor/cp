//Problem: https://www.hackerrank.com/challenges/dijkstrashortreach/submissions/code/14904366
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader ob=new BufferedReader(new InputStreamReader(System.in));
		int testCases,nodes,edges,startV;
		int from, to,weight;
		String line = ob.readLine();
		testCases = Integer.parseInt(line);
		for(int i=0;i<testCases;i++){
			line=ob.readLine();
			String [] array = line.split(" ");
			nodes = Integer.parseInt(array[0]);
			AdjacentListGraph graph = new AdjacentListGraph(nodes);
			edges = Integer.parseInt(array[1]);
			for (int j = 0; j < edges; j++) {
				line = ob.readLine();
				array = line.split(" ");
				from = Integer.parseInt(array[0]) -1;
				to = Integer.parseInt(array[1]) -1;
				weight = Integer.parseInt(array[2]);
				graph.addEdge(from, to, weight);
			}
			startV = Integer.parseInt(ob.readLine())-1;
			DijkstraAdjacentList dijkstra = new DijkstraAdjacentList(graph);
			dijkstra.findShortestPath(startV);
		}
	}

	public static class AdjacentListGraph {

		public class Edge {
			int from;
			int to;
			int weight;
			public Edge(int from, int to, int weight){
				this.from = from;
				this.to = to;
				this.weight = weight;
			}
		}

		Map<Integer, List<Edge>> adjacentList;
		int V;

		public AdjacentListGraph (int V) {
			this.V = V;
			adjacentList = new HashMap<>();
			for (int i = 0; i < this.V; i ++) {
				adjacentList.put(i, new LinkedList<Edge>());
			}
		}

		private boolean removeIfExistLargerEdge(int u, int v, int weight) {
			List<Edge> adjacentEdge;
			adjacentEdge = adjacentList.get(u);
			for(Edge edge : adjacentEdge){
				if (edge.from == u && edge.to == v) {
					if (weight < edge.weight)
						edge.weight = weight;
					return true;
				}
			}
			return false;
		}

		public void addEdge(int u, int v, int weight) {
			if (!removeIfExistLargerEdge(u,v, weight))
				adjacentList.get(u).add(new Edge(u , v, weight));
			if (!removeIfExistLargerEdge(v,u, weight))
				adjacentList.get(v).add(new Edge(v, u, weight));
		}

		public void printGraph(){
			for (int vertex = 0; vertex < V; vertex ++ ) {
				List<Edge> adjacentEdge = adjacentList.get(vertex);
				for (Edge edge: adjacentEdge) {
					System.out.println("Edge from " + edge.from + "  to " + edge.to + " weight = " + edge.weight);
				}
			}
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

	/**
	 * Created by loinguyen on 26/10/2015.
	 */
	public static class DijkstraAdjacentList {
		AdjacentListGraph graph;
		int [] shortestDistance;
		//int [] prev;
		int V;
		int source;
		boolean [] visited;


		public DijkstraAdjacentList (AdjacentListGraph graph){
			this.graph = graph;
			this.V = graph.V;
			shortestDistance = new int[V];
			//prev = new int[V];
			visited = new boolean[V];
			for (int i = 0; i < V; i++){
				shortestDistance[i] = Integer.MAX_VALUE;
				visited[i] = false;
			}
		}

		public void findShortestPath(int source) {
			this.source = source;
			shortestDistance[source] = 0;
			PriorityQueue<Vertex> queue = new PriorityQueue<Vertex>();
			queue.add(new Vertex(source, 0));
			while (!queue.isEmpty()) {
				Vertex from = queue.poll();
				List<AdjacentListGraph.Edge> listEdge = graph.adjacentList.get(from.name);
				for (AdjacentListGraph.Edge edge : listEdge) {

					if (shortestDistance[edge.to] > shortestDistance[from.name] + edge.weight) {
						shortestDistance[edge.to] = shortestDistance[from.name] + edge.weight;
						boolean isAdded = false;
						for (Vertex item : queue) {
							if (item.name == edge.to) {
								isAdded = true;
								break;
							}
						}
						if (!isAdded) {
							queue.add(new Vertex(edge.to, shortestDistance[edge.to]));
						}
					}
				}
				visited[from.name] = true;
			}
			printShortestPath();

		}

		public void printShortestPath(){
			StringBuilder builder = new StringBuilder();
			for (int vertex = 0; vertex < V; vertex++ ) {
				if (vertex != this.source) {
					if (shortestDistance[vertex] == Integer.MAX_VALUE) shortestDistance[vertex] = -1;
					if (vertex == V-1)
						builder.append(shortestDistance[vertex]);
					else
						builder.append(shortestDistance[vertex]).append(" ");
				}
			}
			System.out.println(builder.toString());
		}
	}
}