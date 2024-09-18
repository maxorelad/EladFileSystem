#pragma once
#include <map>
#include <vector>
#include <string>
class FAT
{
private:
	std::map<std::string, std::vector<int>> fileTable;

public:
	void addFile(const std::string& fileName, const std::vector<int>& blocks);

	void deleteFile(const std::string& fileName);

	std::vector<int> getFileBlocks(const std::string& fileName) const;

	bool fileExists(const std::string& fileName) const;
};

