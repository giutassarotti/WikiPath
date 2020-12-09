#include <httplib.h>
#include <graph.hpp>
#include <cstdlib>

// cd src

// If you changed meson.build:
// rm -r build
// meson build

// ninja -C build
// ./build/WikiPath

using namespace httplib;
using namespace std;

int main(int argc, char const* argv[]) 
{
	Server server;
	Graph& graph = Graph::getInstance();

	server.Get("/help", [](const Request&, Response& res) 
	{
	  res.set_content("example: \nhttp://localhost:8080/createPaths?start=Roma&goal=Barbabietola&depth=3", "text/plain");
	});
	
	server.Get("/createPaths", [&graph](const Request& req, Response& res) 
	{
		string s, g, d;
		
		if (!((req.has_param("start"))&&(req.has_param("goal"))&&(req.has_param("depth"))))
		{
			res.set_content("You are missing something, try /help", "text/plain");
		}
		else
		{
			string stringa;
			s = req.get_param_value("start");
			g = req.get_param_value("goal");
			d = req.get_param_value("deapth");
			
			vector<vector<string>> path = graph.createPath(s, g, strtoul(d.c_str(), 0, 10));
			
			for (vector<string>& lilPath: path)
				{
					for (string& label: lilPath)
						stringa+= label + "\n";
					stringa+= "\n\n";
				}
			
			res.set_content(stringa, "text/plain");
		}
	});
	
	server.listen("0.0.0.0", 8080);

	return 0;
}
