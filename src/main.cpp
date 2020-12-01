#include <served/served.hpp>

int main(int argc, char const* argv[]) 
{
	served::multiplexer mux;

	mux.handle("/wikipath{start}{goal}{depth}")
		.get([](served::response & res, const served::request & req) {
			res << req.params["start"] << req.params["goal"]; << req.params["depth"]
		});

	served::net::server server("127.0.0.1", "8080", mux);
	server.run(10);

	return (EXIT_SUCCESS);
}
