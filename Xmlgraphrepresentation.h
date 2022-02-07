#ifndef _XMLGRAPHREPRESENTATION_
#define _XMLGRAPHREPRESENTATION_

#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<list>
#include"XmlDocument.h"
#include"XmlTreeNode.h"
#include"XmlSyntaxAndConsistancy.h"
using namespace System;

class Graph {
public:
	std::vector<std::vector<int>> edges;
	std::vector<std::string>vertex;
	int n;
	Graph(int v);
	void addedge(std::string v1, std::string v2);
	void addNode(std::string id, int index);
	void print();
	std::vector<std::string>getVertex();
	std::vector<std::vector<int>>getEgdes();
	
};

Graph Xml_DFS(XmlTreeNode* root);

#endif