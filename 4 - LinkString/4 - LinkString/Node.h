#ifndef __NODE_H__
#define __NODE_H__

// ½áµãÀà
struct Node {
	char *data;
	Node *next;
	int Nodelen;

	Node();
	Node(char *e, int len, Node *link = NULL);
};

Node::Node() {
	Nodelen = 0;
	data = new char[4];
	assert(data);
	next = NULL;
}

Node::Node(char *e, int len, Node *link) {
	Nodelen = len > 4 ? 4 : len;
	data = new char[4];
	assert(data);
	for (int i = 0; i < Nodelen; i++) data[i] = e[i];
	next = link;
}
#endif
