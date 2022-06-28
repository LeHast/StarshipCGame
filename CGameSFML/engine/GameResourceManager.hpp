#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "SFML/Graphics.hpp"

namespace hast {
template<typename KEY, typename T>
class GameResourceManager{
public:
	ResourceManager(const std::string& pathsFile) {
		LoadPaths(pathsFile);
	}
	virtual ~ResourceManager() { PurgeResources(); }


	void LoadPaths(const std::string&);
	void PurgeResources();
	bool RequireResource(const std::string&);
	bool ReleaseResource(const std::string&);
	bool Unload(const std::string&);
	std::string GetPath(const std::string&);
	T* GetResource(const std::string&);

	std::pair<T*, unsigned int>* Find(const std::string& l_id) {
		auto itr = m_resources.find(l_id);
		return (itr != m_resources.end() ? &itr->second : nullptr);
	}

private:
	std::unordered_map<std::string,std::pair<T*, unsigned int>> m_resources;
	std::unordered_map<std::string, std::string> m_paths;
};

template<typename KEY, typename T>
inline void GameResourceManager<KEY, T>::LoadPaths(const std::string& pathFile){
	std::ifstream paths;
	paths.open(Utils::GetWorkingDirectory() + pathFile);
	if (paths.is_open()) {
		std::string line;
		while (std::getline(paths, line)) {
			std::stringstream keystream(line);
			std::string pathName;
			std::string path;
			keystream >> pathName;
			keystream >> path;
			m_paths.emplace(pathName, path);
		}
		paths.close();
		return;
	}
	std::cerr <<"! Failed loading the path file: "<< pathFile << std::endl;
}

template<typename KEY, typename T>
inline void GameResourceManager<KEY, T>::PurgeResources(){
	while (m_resources.begin() != m_resources.end()) {
		delete m_resources.begin()->second.first;
		m_resources.erase(m_resources.begin());
	}
}

template<typename KEY, typename T>
inline bool GameResourceManager<KEY, T>::RequireResource(const std::string& id){
	auto res = Find(id);
	if (res) {
		++res->second;
		return true;
	}
	auto path = m_paths.find(id);
	if (path == m_paths.end()) { 
		return false; 
	}
	T* resource = Load(path->second);
	if (!resource) {
		return false;
	}
	m_resources.emplace(id, std::make_pair(resource, 1));
	return true;
}

template<typename KEY, typename T>
inline bool GameResourceManager<KEY, T>::ReleaseResource(const std::string& id){
	auto res = Find(id);
	if (!res) {
		return false;
	}
	--res->second;
	if (!res->second) {
		Unload(id);
	}
	return true;
}

template<typename KEY, typename T>
inline bool GameResourceManager<KEY, T>::Unload(const std::string& id){
	auto itr = m_resources.find(id);
	if (itr == m_resources.end()) { return false; }
	delete itr->second.first;
	m_resources.erase(itr);
	return true;
}

template<typename KEY, typename T>
inline std::string GameResourceManager<KEY, T>::GetPath(const std::string& l_id){
	auto path = m_paths.find(l_id);
	return(path != m_paths.end() ? path->second : "");
}

template<typename KEY, typename T>
inline T* GameResourceManager<KEY, T>::GetResource(const std::string& l_id){
	auto res = Find(l_id);
	return(res ? res->first : nullptr);
}


} // End namespace.

