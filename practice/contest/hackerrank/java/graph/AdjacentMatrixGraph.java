import java.util.*;
/*
* Adjacent matrix graph
*/


public class AdjacentMatrixGraph {
    
    private int V;// number of vertex

    private boolean [][] adjacent;
    private int [][] distance;

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
        adjacent[v][u] = true;
        this.distance[v][u] = distance;
    }

    public void printGraph(){
        System.out.println("Graph info :");
        for (int i = 0; i <V; i++) {
            for (int j =0; j < adjacent[i].length ; j++) {
                if (adjacent[i][j] == true) {
                    System.out.println("Edge from " + i + "  to " + j + " with distance = " + distance[i][j]);
                }   
            }    
        }
    }
}