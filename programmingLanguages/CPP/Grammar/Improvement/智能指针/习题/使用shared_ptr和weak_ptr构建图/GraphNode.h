#pragma once

#include <memory>
#include <vector>

class GraphNode {
 public:
  explicit GraphNode(int id);

  void addEdge(const std::shared_ptr<GraphNode>& node);
  void printEdges() const;

 private:
  int _id;
  std::vector<std::weak_ptr<GraphNode>> _linkedNode;
};