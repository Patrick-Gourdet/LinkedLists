#include "Node.h"

#include <iostream>

NodeController::NodeClass* NodeController::get_last(NodeClass* node)
{
	if (node->next == nullptr)
		return node;

	NodeController::get_last(node->next);
}

NodeController::NodeClass* NodeController::find_node(const int value, NodeClass* node)
{
	if (node->next->value == value)
	{
		return node->next;
	}
	if (node == nullptr)
		return nullptr;

	NodeController::find_node(value, node->next);
};


NodeController::NodeClass* NodeController::new_node_func()
{
	auto* new_node = new NodeClass();
	new_node->value = 0;

	return new_node;
}

void NodeController::insert_front(const int value, NodeClass* first_node)
{
	auto* node = NodeController::new_node_func();
	node->next = first_node;
	first_node = node;
	node = node->next;
	first_node->value = value;
}

void NodeController::insert_back(const int value, NodeClass* last_node)
{
	auto* node = NodeController::new_node_func();
	node->value = value;
	get_last(last_node)->next = node;
}

void NodeController::insert_between(const int value, int search_value, NodeClass* between_node)
{
	auto* node = NodeController::new_node_func();
	node->value = value;
	node->next = find_node(search_value, between_node);
	if (node->next == nullptr)
	{
		std::cout << "No Such node found";
		delete node->next;
		delete node;
		return;
	}
	between_node->next = node;
}

void NodeController::remove_node(const int value, NodeClass* remove_node)
{
	auto* node_to_remove = NodeController::find_node(value, remove_node);
	if (node_to_remove == nullptr || node_to_remove->next == nullptr)
	{
		return;
	}
	remove_node = node_to_remove->next;
	delete node_to_remove;
}
