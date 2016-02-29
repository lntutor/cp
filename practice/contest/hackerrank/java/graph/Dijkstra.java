import java.util.*;

public class Dijkstra {

	private AdjacentMatrixGraph graph;
    public int [][] shortestDistance;
    public int [] prev;
    private int INFINITY = 99999;

	public Dijkstra(){
		graph = new AdjacentMatrixGraph(4);
        graph.addEdge(0, 1, 1);
        graph.addEdge(0, 2, 5);
        graph.addEdge(0, 3, 7);
        graph.addEdge(1, 2, 10);
        graph.addEdge(2, 3, 1);

        shortestDistance = new int[graph.getVertexCount()][graph.getVertexCount()];
        prev = new int[graph.getVertexCount()];
        resetGraph();
	}

	private void resetGraph(){
        for (int i =0; i< graph.getVertexCount(); i++) {
            prev[i] = -1;
            for (int j = 0; j < graph.getVertexCount(); j++) {
                shortestDistance[i][j] = INFINITY;
            }
        }
    }

     private void printShortestPath(int source) {

        boolean [][] adjacentMatrix = graph.getAdjacentMatrix();
        for (int j = 0; j < graph.getVertexCount(); j++) {
            if (adjacentMatrix[source][j]) {
                System.out.print("Shortest path from " + source + "  to " + j + "  is "  + shortestDistance[source][j]);
                String path = j + "";
                int tmp = j;
                while(prev[tmp] != source) {
                    path =  prev[tmp] + " ==> " + path;
                    tmp = prev[tmp];
                }
                System.out.println("   Path is: " + source + " ==> " + path);
            }
        }
    }

    public void findShortestPath(int source){// using Dijkstra Algorithm
            shortestDistance[source][source] = 0;
            prev[source] = source;
            Queue<Integer> st = new LinkedList<Integer>();
            st.add(source);
            boolean [][] adjacentMatrix = graph.getAdjacentMatrix();
            int [][] distanceMatrix = graph.getDistanceMatrix();

            while(!st.isEmpty()) {

                int vertexToVisit = (int) st.poll();
                for (int i = 0; i < graph.getVertexCount(); i++) { // loop through adjacent vertext of vertexToVisit

                    if (adjacentMatrix[vertexToVisit][i]) {
                        int tmp = shortestDistance[source][vertexToVisit] + distanceMatrix[vertexToVisit][i];
                        if(tmp < shortestDistance[source][i]) {
                            shortestDistance[source][i] = tmp;
                            prev[i] = vertexToVisit;
                        }
                        st.add(i);
                    }

                }
           }
        graph.printGraph();
        printShortestPath(source);
    }

}