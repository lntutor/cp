import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Created by loinguyen on 26/10/2015.
 */
public class DijkstraAdjacentList {
    AdjacentListGraph graph;
    int [] shortestDistance;
    int [] prev;
    int V;
    int source;


    public DijkstraAdjacentList (){
        graph = new AdjacentListGraph(4);
        graph.addEdge(0, 1, 1);
        graph.addEdge(0, 2, 5);
        graph.addEdge(0, 3, 7);
        graph.addEdge(1, 2, 10);
        graph.addEdge(2, 3, 1);
        this.V = graph.V;
        shortestDistance = new int[V];
        prev = new int[V];
        for (int i = 0; i < V; i++){
            shortestDistance[i] = Integer.MAX_VALUE;
            prev[i] = -1;
        }
    }

    public void findShortestPath(int source) {
        this.source = 0;
        shortestDistance[source] = 0;
        prev[source] = -1;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);
        while (!queue.isEmpty()) {
            int from = queue.remove();
            List<AdjacentListGraph.Edge> listEdge = graph.adjacentList.get(from);
            for (AdjacentListGraph.Edge edge : listEdge) {
                if (shortestDistance[edge.to] > shortestDistance[from] + edge.weight) {
                    shortestDistance[edge.to] = shortestDistance[from] + edge.weight;
                    prev[edge.to] = from;
                }
                queue.add(edge.to);
            }
        }
        printShortestPath();

    }

    public void printShortestPath(){
        for (int vertex = 0; vertex < V; vertex ++ ) {
            System.out.print(shortestDistance[vertex]);
            int tmp = vertex;
            String path = "";
            while(prev[tmp] != -1) {
                path =  tmp + " ==> " + path;
                tmp = prev[tmp];
            }
            System.out.println("   Path is: " + source + " ==> " + path);
        }
    }

    public static void main(String args[]) {
        Dijkstra dijkstra = new Dijkstra();
        dijkstra.findShortestPath(0);
    }

}
