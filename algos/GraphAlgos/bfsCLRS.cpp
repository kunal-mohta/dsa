#include<iostream>
#include<vector>

class Node {
    public:
        std::string color = "white";
        int value;
        std::vector <Node*> Adj;
        int dist = -1;
        Node *parent = nullptr;

        Node (int val) {
            value = val;
        }

        void addAdj (Node *newAdjNode) {
            Adj.push_back(newAdjNode);
        }

        void assignAdjs (std::vector <Node *> nodes) {
            Adj = nodes;
        }
};

class Queue {
    public:
        std::vector <Node*> queue;
        int head = 0, tail = -1;

        void enqueue (Node *newNode) {
            queue.push_back(newNode);
            if (isEmpty()) {
                tail = head + 1;
            }
            else {
                tail = tail + 1;
            }
        }

        Node* dequeue () {
            if (isEmpty()) {
                return nullptr;
            }
            else {
                head = head + 1;
                return queue[head - 1];
            }
        }

        void peek() {
            if (isEmpty()) {
                std::cout<<"cannot peek"<<std::endl;
            }
            else {
                std::cout<<queue[head]->value<<std::endl;
            }
        }

        bool isEmpty() {
            if (head == tail + 1) {
                return true;
            }
            else {
                return false;
            }
        }

        void printQueue () {
            if (isEmpty()) {
                std::cout<<"Queue is empty"<<std::endl;
            }
            else {
                for (int i = head; i <= tail; i++) {
                    std::cout<<queue[i]->value<<std::endl;
                }
                std::cout<<"queue printed"<<std::endl;
            }
        }
};

void bfs (Node *start) {
    start->color = "gray";
    int time = 0;

    Queue q;
    q.enqueue(start);

    while (!q.isEmpty()) {
        Node* u = q.dequeue();
        std::cout<<u->value<<std::endl;
        for (int i = 0; i < u->Adj.size(); i++) {
            if (u->Adj[i]->color == "white") {
                time++;

                Node *v = u->Adj[i];
                q.enqueue(v);
                // q.printQueue();
                v->dist = time;
                v->color = "gray";
                v->parent = u;
            }
        }
        u->color = "black";
    }
};

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

    //bfs
    bfs(two);

    // for (int i = 0; i < visitOrder.size(); i++) {
    //     std::cout<<visitOrder[i]->value<<std::endl;
    // }

    // Queue q;
    // q.enqueue(one);
    // q.enqueue(two);
    // q.dequeue();
    // q.enqueue(three);
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.enqueue(one);

    // q.printQueue();
}