#ifndef __pathconnections_H
#define __pathconnections_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "boost/filesystem.hpp"
#include "boost/iostreams/stream.hpp"

using namespace std;

template <typename T>
class PathConnection {
public:
	//define type to create 
	typedef std::map< T, std::vector<T> > PathType;
	// constructor
	PathConnection(std::string& file);
	// set file name 
	void set_filename(std::string& file);
	// get file name 
	std::string& get_filename();
	// add value
	void map_add_value(std::pair< T, std::vector<T> >);
private:
	PathType connection;
	std::string filename;
};


template<typename T>
PathConnection<T>::PathConnection(std::string& file) : filename(file) {
	cout << "reading filename  " << file.c_str() << endl;
	// here read the file and add the elements 	
}




template <typename MapType>
class map_add_values {
private:
	MapType mMap;
public:
	typedef typename MapType::key_type KeyType;
	typedef typename MapType::mapped_type MappedType;

	map_add_values(const KeyType& key, const MappedType& val)
	{
		mMap[key] = val;
	}

	map_add_values& operator()(const KeyType& key, const MappedType& val) {
		mMap[key] = val;
		return *this;
	}

	void to(MapType& map) {
		map.insert(mMap.begin(), mMap.end());
	}
};

#endif