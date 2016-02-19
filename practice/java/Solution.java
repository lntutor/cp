import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

	public static void main(String[] args) throws IOException {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
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
            //if (i == 4) System.out.println(line);
			for (int j = 0; j < edges; j++) {
				line = ob.readLine();
				array = line.split(" ");
				from = Integer.parseInt(array[0]) -1;
				to = Integer.parseInt(array[1]) -1;
				weight = Integer.parseInt(array[2]);
				graph.addEdge(from, to, weight);
                //if (i == 4) System.out.println(line);
			}
            //graph.printGraph();
			startV = Integer.parseInt(ob.readLine()) -1;
            //if (i == 4) System.out.println(""+startV);
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
            
		    //System.out.println("addEdge " + u + "  to " + v + " weight = " + weight);
			if (!removeIfExistLargerEdge(u,v, weight))
				adjacentList.get(u).add(new Edge(u , v, weight));
			if (!removeIfExistLargerEdge(v,u, weight))
				adjacentList.get(v).add(new Edge(v, u, weight));

//			List<Edge> adjacentEdge = adjacentList.get(u);
//			if (u < v) {
//                if (!removeIfExistLargerEdge(u,v, weight))
//                    adjacentList.get(u).add(new Edge(u , v, weight));
//            } else {
//                if (!removeIfExistLargerEdge(v,u, weight))
//                    adjacentLis®t.get(v).add(new Edge(v, u, weight));
//            }
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
			//	prev[i] = -1;
				visited[i] = false;
			}
		}

		public void findShortestPath(int source) {
			this.source = source;
			shortestDistance[source] = 0;
			//prev[source] = -1;
			visited[source] = true;
			Queue<Integer> queue = new LinkedList<>();
			queue.add(source);
			while (!queue.isEmpty()) {
				int from = queue.remove();
				List<AdjacentListGraph.Edge> listEdge = graph.adjacentList.get(from);
				for (AdjacentListGraph.Edge edge : listEdge) {
                    //System.out.println("Edge from " + edge.from + "  to " + edge.to + " weight = " + edge.weight);

					if (shortestDistance[edge.to] > shortestDistance[from] + edge.weight) {
						shortestDistance[edge.to] = shortestDistance[from] + edge.weight;
						//prev[edge.to] = from;
					}
					if (!visited[edge.to]) {
						visited[edge.to] = true;
						queue.add(edge.to);
					}
				}
			}
//			graph.printGraph();
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