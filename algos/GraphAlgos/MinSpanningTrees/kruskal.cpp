/* No implementation seen */

#include<iostream>
#include<vector>

class GraphNode;

class AdjListNode {
    public:
        GraphNode* node;
        int weight;

        AdjListNode (GraphNode* g, int w) {
            node = g;
            weight = w;
        }
};

class GraphNode {
    public:
        int value;
        std::vector<AdjListNode*> adjList;
        std::vector<GraphNode*> MSPadj;

        GraphNode (int val) {
            value = val;
        }

        void addAdjNode (GraphNode* node, int weight) {
            AdjListNode *aNode = new AdjListNode(node, weight);
            adjList.push_back(aNode);
        }
};

class Edge {
    public:
        std::vector<GraphNode*> vertices;
        int weight;

        Edge (GraphNode* one, GraphNode* two, int w) {
            vertices.push_back(one);
            vertices.push_back(two);
            weight = w;
        }
};

void sortEdges (std::vector<Edge *> &edges) {
    // selection sort
    for (int i = 0; i < edges.size(); i++) {
        for (int j = i + 1; j < edges.size(); j++) {
            if (edges[i]->weight > edges[j]->weight) {
                Edge *temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

bool isEdgeSafe (Edge* edge) {
    std::vector<GraphNode*> vertice1Adj = edge->vertices[0]->MSPadj;
    std::vector<GraphNode*> vertice2Adj = edge->vertices[1]->MSPadj;

    for (int i = 0; i < vertice1Adj.size(); i++) {
        for (int j = 0; j < vertice2Adj.size(); j++) {
            if (vertice1Adj[i] == vertice2Adj[j]) return false;
        }
    }
    return true;
}

void makeTreeEdge (Edge* edge) {
    edge->vertices[0]->MSPadj.push_back(edge->vertices[1]);
    edge->vertices[1]->MSPadj.push_back(edge->vertices[0]);
}

void kruskal (std::vector<Edge *> &edges, int totalVertices) {
    sortEdges(edges);

    std::vector<GraphNode *> visitedVertices;
    int totalCost = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (isEdgeSafe(edges[i])) {
            totalCost += edges[i]->weight;
            makeTreeEdge(edges[i]);
            visitedVertices.push_back(edges[i]->vertices[0]);
            visitedVertices.push_back(edges[i]->vertices[1]);
        }
    }

    std::cout<<"Cost of the minimum spanning tree: "<<totalCost<<std::endl;
}

int main () {
    /* making the graph */
    GraphNode* a = new GraphNode(1);
    GraphNode* b = new GraphNode(2);
    GraphNode* c = new GraphNode(3);
    GraphNode* d = new GraphNode(4);
    GraphNode* e = new GraphNode(5);

    a->addAdjNode(b, 1);
    a->addAdjNode(c, 7);

    b->addAdjNode(a, 1);
    b->addAdjNode(c, 5);
    b->addAdjNode(d, 4);
    b->addAdjNode(e, 3);

    c->addAdjNode(a, 7);
    c->addAdjNode(b, 5);
    c->addAdjNode(e, 6);

    d->addAdjNode(b, 4);
    d->addAdjNode(e, 2);

    e->addAdjNode(b, 3);
    e->addAdjNode(d, 2);
    e->addAdjNode(c, 6);

    std::vector<GraphNode*> vertices = {a, b, c, d, e};
    std::vector<Edge*> edges;

    // figure out how to convert to this using adjacency list
    edges.push_back(new Edge(a,b,1));
    edges.push_back(new Edge(a,c,7));
    edges.push_back(new Edge(b,c,5));
    edges.push_back(new Edge(b,d,4));
    edges.push_back(new Edge(b,e,3));
    edges.push_back(new Edge(c,e,6));
    edges.push_back(new Edge(d,e,2));

    /* Kruskal's */

    kruskal(edges, vertices.size());
}