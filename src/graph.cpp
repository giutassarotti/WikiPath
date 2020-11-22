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
			this->searchGoal(lilPath, bigPath,goal, depth-1);
		}
	}
}

Graph::Graph()
{}

Graph& Graph::getInstance()
{
	static Graph myGraph();
	
	return myGraph;
}

Node& Graph::getNode(const string& label) const
{
	for (const Node& n: this->nodes)
	{
		if (n.label == label)
			 return n;
	}
	
	return this->addNode(label);
}

Node& Graph::addNode(const string& label)
{
	//dal file
}

vector<vector<string> Graph::createPath(const string& start, const string& goal, unsigned char depth) const
{
	Node& start = this->getNode(start);
	vector<string> lilPath;
	vector<vector<string>> bigPath;
	
	return start.searchGoal(lilPath, bigPath, goal);
}
