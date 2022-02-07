

#include"Xmlgraphrepresentation.h"






Graph::	Graph(int v)
	{
		n = v;
		vertex.resize(v);
		edges = std::vector<std::vector<int>>(n, std::vector<int>(n));
	
	}

	void Graph::addedge(std::string v1, std::string v2)
	{   
		int row, col;
		std::vector<std::string>::iterator it;
		std::vector<std::string>::iterator it2;
		it= std::find(vertex.begin(), vertex.end(), v1);
		if (it != vertex.end())
		{
			row = it-vertex.begin();
		}
		
		it2 = std::find(vertex.begin(), vertex.end(), v2);
		if (it2 != vertex.end())
		{
			col = it2 - vertex.begin();
		}
		edges[row][col] = 1;
	}
	void  Graph:: addNode(std::string id , int index)
	{
		vertex[index] = id;
		for (int i = 0; i < n; i++)
		{
			edges[index][i] = 0;
			edges[i][index] = 0;
		}
	}
	void Graph::print()
	{
		for (int i = 0; i < n; i++)
		{
			System::Diagnostics::Debug::Write(gcnew String(vertex[i].c_str()));
			System::Diagnostics::Debug::Write("--->");
		
			for (int j = 0; j < n; j++)
			{
				
				System::Diagnostics::Debug::Write(gcnew String(std::to_string(edges[i][j]).c_str()));
				System::Diagnostics::Debug::Write(" ");
			}
			
			
			System::Diagnostics::Debug::Write("\n");
		}
		
		System::Diagnostics::Debug::Write("\n");
	}
	std::vector<std::string> Graph:: getVertex()
	{
		return this->vertex;
	}
	std::vector<std::vector<int>>Graph::getEgdes()
	{
		return this->edges;
	}

 



Graph Xml_DFS(XmlTreeNode* root)
{ 
	
	std::stack <XmlTreeNode*>st;
	Graph g(root->getNumberOfChildren());
	int n = root->getNumberOfChildren();
	for (int i = 0; i < n; i++)
	{
		g.addNode(root->getChildren()[i]->getChildren()[0]->getValue(), i);
	}
	
		st.push(root);
		
		do
		{
			XmlTreeNode* v = st.top();
			st.pop();
		
		
				if (v->getTagName() == "followers")
				{
					
					for (int i = 0; i < v->getChildren().size() ; i++)
					{
					
						g.addedge(v->getParent()->getChildren()[0]->getValue() , v->getChildren()[i]->getChildren()[0]->getValue());
					}
					continue;
				

				}
				else
				{
					for (int i = 0; i < v->getChildren().size() ; i++)
					{
						st.push(v->getChildren()[i]);
					}
				}
		


		} while (!st.empty());

		g.print();

		return g;
	
}
