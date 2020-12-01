project('WikiPath', 
    ['cpp'], 
    version: '0.1.0',
    meson_version: '>= 0.51.0',
    default_options : [
        'warning_level=3',
        'cpp_std=c++2a',
        'debug=true',
    ]
)

cmake = import('cmake')

cpp 		= meson.get_compiler('cpp')

pthread 	= cpp.find_library('pthread', required : true)
dl			= cpp.find_library('dl', required : true)

sqlitecpp  	= declare_dependency(dependencies:  [cmake.subproject('SQLiteCpp').dependency('SQLiteCpp'), 
													cmake.subproject('SQLiteCpp').dependency('sqlite3'), 
													dl, 
													pthread])
subdir('graph')
