#include "GraphNode.h"

#include <iostream>

GraphNode::GraphNode(int id) : _id(id) {}

void GraphNode::addEdge(const std::shared_ptr<GraphNode>& node) {
  int nodeId = node->_id;
  for (const auto& weakNode : _linkedNode) {
    if (auto temp = weakNode.lock()) {
      if (temp->_id == nodeId) {
        return;
      }
    }
  }

  _linkedNode.emplace_back(std::weak_ptr<GraphNode>(node));
}

void GraphNode::printEdges() const {
  std::cout << "Node " << _id << " edges: ";
  for (const auto& node : _linkedNode) {
    if (auto temp = node.lock()) {
      std::cout << temp->_id << " ";
    }
  }
  std::cout << std::endl;
}