#include "GraphNode.h"

std::vector<std::shared_ptr<GraphNode>> createGraph() {
  auto node1 = std::make_shared<GraphNode>(1);
  auto node2 = std::make_shared<GraphNode>(2);
  auto node3 = std::make_shared<GraphNode>(3);

  node1->addEdge(node2);
  node1->addEdge(node3);

  node2->addEdge(node3);

  node3->addEdge(node1);

  return {node1, node2, node3};
}

int main() {
  auto graph = createGraph();

  for (const auto& node : graph) {
    node->printEdges();
  }

  return 0;
}