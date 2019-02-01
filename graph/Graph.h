//
// Created by root on 31/01/19.
//

#ifndef TEST_BUILD_GRAPH_H
#define TEST_BUILD_GRAPH_H
#define MAXV 1000

#include "../queue/Queue.h"

class Graph {
    class Edgenode {
    public:
        int y;
        int weight;
        Edgenode *next;

        Edgenode(int y, int weight, Edgenode *edgenode) {
            this-> y = y;
            this->weight = weight;
            this->next = edgenode;
        }
    };

public:
    void read(bool directed) {
        int x[] = {1, 3, 4, 3, 5, 2, 5};
        int y[] = {5, 2, 3, 4, 4, 1, 2};
        initialize(directed);
        this->nvertices = 5;
        int m = 7;
        for (int i = 1; i <= m; i++) {
            insert_edge(x[i-1], y[i-1], directed);
        }
    }

    void print() {
        Edgenode *p;
        for (int i = 1; i <= this->nvertices; i++) {
            std::cout << i << ": ";
            p = this->edges[i];
            while (p != nullptr) {
                std::cout << p->y << " ";
                p = p->next;
            }
            std::cout << std::endl;
        }
    }

    void bfs(int start) {
        bool processed[MAXV + 1];
        bool discovered[MAXV + 1];
        int parent[MAXV + 1];

        for(int i = 0; i <= MAXV; i++) {
            processed[i] = discovered[i] = false;
            parent[i] = -1;
        }
        
        Queue<int> *queue = new Queue<int>();
        int v; // current top
        int y; // next top
        Edgenode *p;
        queue->add(start);
        while(!queue->is_empty()) {
            v = queue->get().getData();
            process_vertex_early(v);
            processed[v] = true;
            p = this->edges[v];
            while (p != nullptr) {
                y = p->y;
                if (!processed[y] && directed) process_edge(v, y);
                if (!discovered[y]) {
                    queue->add(y);
                    discovered[y] = true;
                    parent[y] = v;
                }
                p = p->next;
            }
            process_vertex_late(v);
        }
    }

private:
    Edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;

    void initialize(bool directed) {
        int i;
        this->directed = directed;
        this->nvertices = 0;
        this->nedges = 0;

        for (i = 1; i <= MAXV; i++) this->degree[i] = 0;
        for (i = 1; i <= MAXV; i++) this->edges[i] = nullptr;
    }

    void insert_edge(int x, int y, bool directed) {
        Edgenode *p = new Edgenode(y, 0, this->edges[x]);
        this->edges[x] = p; // insert in start of list
        this->degree[x]++;
        if (!directed) insert_edge(y, x, true);
        else this->nedges++;
    }

    void process_vertex_early(int v) {
        std::cout << "Processed vertex: " << v << std::endl;
    }

    void process_edge(int x, int y) {
        std::cout << "Processed edge: (" << x << ", " << y << ")" << std::endl;
    }

    void process_vertex_late(int v) {

    }
};


#endif //TEST_BUILD_GRAPH_H
