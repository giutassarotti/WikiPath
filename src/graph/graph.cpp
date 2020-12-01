#include <iostream>

#include "graph.hpp"

using namespace std;

Node::Node(const string& label_):
	label(label_)
{}

void Node::addLinks(const vector<Node*>& links)
{
	this->links.resize(links.size());
	
	this->links.insert(this->links.begin(), links.begin(), links.end());
}

vector<vector<string> Node::searchGoal(vector<string> lilPath, vector<vector<string>>& bigPath, const string& goal, unsigned char depth)
{  
	if (depth==0)
		return bigPath;
	
	for (const Node& n: this->links)
	{
		if (n.label == goal)
			 bigPath.emplace_back(lilPath);
		else 
		{
			lilPath.push_back(n.label);
			
			if (n.links.size() == 0)
				Graph::getInstance().expandNode(n);
			
			n.searchGoal(lilPath, bigPath, goal, depth-1);
		}
	}
}

Graph::Graph():
	db("database.sqlite", SQLite::OPEN_READ)
{}

Graph& Graph::getInstance()
{
	static Graph myGraph();
	
	return myGraph;
}

Node& Graph::getNode(const string& label) const
{
	Node& n = this->nodes[label];
	if (n.label == "")
		n.label = label;
			
	if (n.links.size() == 0)
		this->expandNode(label);
	
	return n;
}

void Graph::expandNode(Node& node)
{
	//from the file sqlite
	SQLite::Statement querySearch(db, "SELECT pl_title FROM pagelinks WHERE pl_from = \"" + node.label + "\"");
	
	while (querySearch.executeStep())
	{
		const char* title = querySearch.getColumn(1);
		
		Node& n = this->nodes[title];
		if (n.label == "")
			n.label = title;
		
		node.links.push_back(&n);
	}
}

vector<vector<string> Graph::createPath(const string& start, const string& goal, unsigned char depth) const
{
	Node& start = this->getNode(start);
	vector<string> lilPath;
	vector<vector<string>> bigPath;
	
	return start.searchGoal(lilPath, bigPath, goal);
}
