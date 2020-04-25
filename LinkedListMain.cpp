#include <iostream>

#include "Node.h"


int main()
{
	auto* node_controller = new NodeController();
	auto* root = NodeController::new_node_func();
	auto* first = NodeController::new_node_func();
	root->next = first;
	node_controller->insert_front(55, first);
	node_controller->insert_back(6, root);
	node_controller->insert_between(8, 0, root);
}
