#pragma once

#include <algorithm>

/**
 * Node
 */
template <typename T>
class Node {
 private:
  T data;
  int id;

 public:
  Node(int id, T data) : id(id), data(data) {}
  int get_id() const { return id; }
  T get_data() const { return data; }
};

/**
 * Directed Graph
 */
template <typename T>
class DirectedGraph {
 private:
  std::map<int, std::vector<int>> adj_list;
  std::map<int, Node<T>> nodes;

 public:
  DirectedGraph() {}
  DirectedGraph(std::vector<Node<T>> nodes) {
    for (auto node : nodes) {
      this->nodes[node.get_id()] = node;
    }
  }

  void add_node(Node<T> node) {
    nodes[node.get_id()] = node;
  }

  void add_edge(int from, int to) {
    adj_list[from].push_back(to);
  }

  void add_edges(int from, std::vector<int> to) {
    adj_list[from] = to;
  }

  std::vector<int> get_adj_list(int node_id) {
    return adj_list[node_id];
  }

  std::vector<Node<T>> get_nodes() {
    std::vector<Node<T>> nodes;
    for (auto node : this->nodes) {
      nodes.push_back(node.second);
    }
    return nodes;
  }

  Node<T> get_node(int node_id) {
    return nodes[node_id];
  }

  int get_node_id(Node<T> node) {
    return node.get_id();
  }
};