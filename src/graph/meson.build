graph_lib = static_library(
	'graph',
	[
		'graph.cpp'
	],
	dependencies : [
		sqlitecpp
    ]
)

graph = declare_dependency(
    link_with : [graph_lib],
    include_directories : ['.'],
    dependencies: [
		sqlitecpp
    ]
)
