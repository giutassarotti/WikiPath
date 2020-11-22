//my little graph
#include <list>
#include <string>
#include <vector>

#define NOTFOUND 7

struct Node
{
	std::string label;
	std::vector<Node*> links;
	
	Node(const std::string& label);
	
	void addLinks(const std::vector<Node*>& links);
	std::vector<std::vector<std::string> searchGoal(const std::string& goal, unsigned char depth);
	
}

class Graph
{	
	private:
		std::list<Node> nodes;
		
		//my little graph is a singleton, just one in the universe
		Graph();
		
		Node& getNode(const std::string& label) const;
	public:
		Graph& getInstance() const;
		Node& addNode(const std::string& label);
		
		//Note: max depth is ~500
		std::vector<std::vector<std::string> createPath(const std::string& start, const std::string& goal, unsigned char depth) const;
}
