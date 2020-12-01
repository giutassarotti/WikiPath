//my little graph
#include <map>
#include <string>
#include <vector>

#include <SQLiteCpp/SQLiteCpp.h>

#define NOTFOUND 7

struct Node
{
	std::string label;
	std::vector<Node*> links;
	
	Node(const std::string& label);
	Node() {}
	
	void addLinks(const std::vector<Node*>& links);
	void searchGoal(std::vector<std::string> lilPath, std::vector<std::vector<std::string>>& bigPath, const std::string& goal, unsigned char depth);
	
};

class Graph
{	
	private:
		std::map<std::string, Node> nodes;
		
		SQLite::Database db;
		
		//my little graph is a singleton, just one in the universe
		Graph();
		
		Node& getNode(const std::string& label);
	public:
		static inline Graph& getInstance()
		{
			static Graph myGraph;
			
			return myGraph;
		};
		void expandNode(Node& node);
		
		//Note: max depth is ~500
		std::vector<std::vector<std::string>> createPath(const std::string& start, const std::string& goal, unsigned char depth);
};
