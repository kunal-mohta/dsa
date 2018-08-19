#include<iostream>
#include<vector>

class Node {
    public:
        std::string color = "white";
        int value;
        std::vector <Node*> Adj;
        int dist = -1;
        int f = -1;
        Node *parent = nullptr;

        Node (int val) {
            value = val;
        }

        void addAdj (Node *newAdjNode) {
            newAdjNode->parent = this;
            Adj.push_back(newAdjNode);
        }

        void assignAdjs (std::vector <Node *> nodes) {
            for (int i = 0; i < nodes.size(); i++) {
                nodes[i]->parent = this;
            }
            Adj = nodes;
        }
};

void dfsVisit(Node *node, int time) {
    node->color = "gray";
    node->dist = time;

    std::cout<<node->value<<std::endl;

    for (int i = 0; i < (node->Adj.size()); i++) {
        if (node->Adj[i]->color == "white") {
            time++;
            node->Adj[i]->parent = node;
            dfsVisit(node->Adj[i], time);
        }
    }

    node->color = "black";
}

void dfs (Node* start) {
    int time = 0;
    dfsVisit(start, time);
}

int main () {
    // constructing the graph
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);
    Node *six = new Node(6);
    Node *seven = new Node(7);
    Node *eight = new Node(8);

    std::vector <Node*> oneN = { two, five };
    one->assignAdjs(oneN);

    std::vector <Node*> twoN = { one, six };
    two->assignAdjs(twoN);

    std::vector <Node*> threeN = { four, six, seven };
    three->assignAdjs(threeN);

    std::vector <Node*> fourN = { three, seven, eight };
    four->assignAdjs(fourN);

    std::vector <Node*> fiveN = { one };
    five->assignAdjs(fiveN);

    std::vector <Node*> sixN = { two, three, seven };
    six->assignAdjs(sixN);

    std::vector <Node*> sevenN = { three, four, six };
    seven->assignAdjs(sevenN);

    std::vector <Node*> eightN = { four, seven };
    eight->assignAdjs(eightN);

    //dfs
    dfs(two);
}