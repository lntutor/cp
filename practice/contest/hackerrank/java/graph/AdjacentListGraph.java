import java.util.*;

public class AdjacentListGraph {

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
		for (int i = 0; i < V; i ++) {
			adjacentList.put(i, new LinkedList<Edge>());
		}
	}

	public void addEdge(int from, int to, int weight) {
		List<Edge> adjacentEdge = adjacentList.get(from);

		if (adjacentEdge != null) {
			adjacentEdge.add(new Edge(from, to, weight));
		}

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