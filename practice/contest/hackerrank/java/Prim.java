import java.util.*;

public class Prim {

	private AdjacentMatrixGraph graph;
    public boolean [][] mst;
    
    Queue<Integer> visitedList = new LinkedList<Integer>();
    private int INFINITY = 99999;

	public Prim(){
		graph = new AdjacentMatrixGraph(4);
        graph.addEdge(0, 1, 1);
        graph.addEdge(0, 2, 5);
        graph.addEdge(0, 3, 7);
        graph.addEdge(1, 2, 10);
        graph.addEdge(2, 3, 1);

        mst = new boolean[graph.getVertexCount()][graph.getVertexCount()];
        resetGraph();
	}

	private void resetGraph(){
        for (int i =0; i< graph.getVertexCount(); i++) {
            for (int j = 0; j < graph.getVertexCount(); j++) {
                mst[i][j] = false;
            }
        }
    }

    private void printMST(int source) {

        boolean [][] adjacentMatrix = graph.getAdjacentMatrix();
        int [][] distanceMatrix = graph.getDistanceMatrix();
        for (int i = 0; i <  graph.getVertexCount(); i++) {
            for (int j = 0; j < graph.getVertexCount(); j++) {
                if (mst[i][j]) {
                    System.out.println(" Edge from " + i + "  to " + j + " with weight = " + distanceMatrix[i][j]);
                }
            }
        }
    }

    public void findMST(int source){// using Prim Algorithm
            visitedList.add(source);
            boolean [][] adjacentMatrix = graph.getAdjacentMatrix();
            int [][] distanceMatrix = graph.getDistanceMatrix();

            while(visitedList.size() < graph.getVertexCount()){ // visit until visit all vertex of graph
                //loop through visted vertex (connected graph) 
                //and unvisited vertex, choose out the vertex that has the min-edge to current connect graph
                int minWeight = INFINITY;
                int nextChoosenVertex = -1;
                int vertextInGraph = -1;
                for (Integer vertex : visitedList) {
                    for (int i = 0; i < graph.getVertexCount(); i++) { // loop through adjacent vertext of vertex
                        if (!visitedList.contains(i) && adjacentMatrix[vertex][i]) {
                            System.out.println("vertex = " + vertex + " i = " + i + " weight  " + distanceMatrix[vertex][i] + " minWeight " + minWeight);
                            if(minWeight > distanceMatrix[vertex][i] ) {
                                // System.out.println("minWeight =" + minWeight);
                                minWeight = distanceMatrix[vertex][i];
                                nextChoosenVertex = i;
                                vertextInGraph = vertex;
                            }
                        }
                    }
                }

                System.out.println("nextChoosenVertex " + nextChoosenVertex + " with minWeight = " + minWeight);
                mst[vertextInGraph][nextChoosenVertex] = true;
                visitedList.add(nextChoosenVertex);
            }
        graph.printGraph();
        printMST(source);
    }

}