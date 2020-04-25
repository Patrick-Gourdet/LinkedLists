
#ifndef NODECONTROLLER_H


class NodeController
{

public:
#define NODECONTROLLER_H 
	struct NodeClass {
		int value;
		NodeClass* next;
	}node_class{};
	NodeController() {}
	~NodeController();
    NodeClass* node{};
	static NodeClass* new_node_func();

	void insert_front(int value, NodeClass* first_node);
	void insert_back(int value, NodeClass* last_node);
	void insert_between(const int value, int search_value, NodeClass* between_node);
	void remove_node(const int value, NodeClass* remove_node);

	NodeClass* get_last(NodeClass* node);
	NodeClass* find_node(const int value, NodeClass* node);

};
#endif
