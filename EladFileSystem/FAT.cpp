#include "FAT.h"
void FAT::addFile(const std::string& fileName, const std::vector<int>& blocks) {
	this->fileTable[fileName] = blocks;
}

void FAT::deleteFile(const std::string& fileName) {
	fileTable.erase(fileName);
}

std::vector<int> FAT::getFileBlocks(const std::string& fileName) const {
	return fileTable.at(fileName);
}

bool FAT::fileExists(const std::string& fileName) const {
	return fileTable.find(fileName) != fileTable.end();
}