//https://www.hackerrank.com/challenges/primsmstsub
import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader ob=new BufferedReader(new InputStreamReader(System.in));
//		int testCases,;
		int nodes,edges,startV;
		int from, to,weight;
//		String line = ob.readLine();
//		testCases = Integer.parseInt(line);
//		for(int i=0;i<testCases;i++){
			String line=ob.readLine();
			String [] array = line.split(" ");
			nodes = Integer.parseInt(array[0]);
			AdjacentListGraph graph = new AdjacentListGraph(nodes);
			edges = Integer.parseInt(array[1]);
			for (int j = 0; j < edges; j++) {
				line = ob.readLine();
				array = line.split(" ");
				from = Integer.parseInt(array[0]) - 1;
				to = Integer.parseInt(array[1]) - 1;
				weight = Integer.parseInt(array[2]);
				graph.addEdge(from, to, weight);
			}
			startV = Integer.parseInt(ob.readLine()) - 1;
			Prim prim = new Prim(graph);
			prim.findMST(startV);
//		}
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

			@Override
			public String toString() {
				return "Edge from " + from + " to " + to;
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

			//System.out.println("addEdge " + u + "  to " + v + " weight = " + weight);
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

	public static class Prim {
		AdjacentListGraph graph;
		int [] mstDistance;
		int V;
		int source;


		public Prim (AdjacentListGraph graph){
			this.graph = graph;
			this.V = graph.V;
			mstDistance = new int[V];
			for (int i = 0; i < V; i++){
				mstDistance[i] = Integer.MAX_VALUE;
			}
		}

		public void findMST(int source) {
			this.source = source;
			mstDistance[source] = 0;
			Queue<Integer> queue = new LinkedList<>();
			queue.add(source);
			Queue<AdjacentListGraph.Edge> edgeQueue = new LinkedList<>();
			while(queue.size() < this.V) {
				int selectedVertex = -1;
				int minWeight = Integer.MAX_VALUE;
				AdjacentListGraph.Edge selectedEdge = null;
				for (Integer vertex : queue) {
					List<AdjacentListGraph.Edge> listEdge = graph.adjacentList.get(vertex);
					for (AdjacentListGraph.Edge edge : listEdge) {
						if (minWeight > edge.weight && !queue.contains(edge.to)) {
							minWeight = edge.weight;
							selectedVertex = edge.to;
							selectedEdge = edge;
						}
					}
				}

				if (selectedVertex!= -1 && !queue.contains(selectedVertex)) {
					queue.add(selectedVertex);
					mstDistance[selectedVertex] = minWeight;
					edgeQueue.add(selectedEdge);
				}
			}
//			for (int item : queue) {
//				System.out.println(item + "");
//			}
			printMST(edgeQueue);
		}

		public void printMST(Queue<AdjacentListGraph.Edge> edgeQueue){
//			StringBuilder builder = new StringBuilder();
			int sum = 0;
			for (AdjacentListGraph.Edge edge : edgeQueue) {
				sum += edge.weight;
			}
			System.out.println(sum+"");
		}
	}
}