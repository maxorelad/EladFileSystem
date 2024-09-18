#include "FileSys.h"
void FileSys::createFile(const std::string& fileName, const char* content) {
	size_t size = std::strlen(content) + 1;
	size_t numBlocks = (size + disk.BLOCK_SIZE - 1) / disk.BLOCK_SIZE;
	if (fat.fileExists(fileName)) {
		std::cout << "File already exists\n";
		return;
	}
	std::vector<int> freeBlocks = disk.findFreeBlocks(static_cast<int>(numBlocks));
	if (freeBlocks[0] == -1) {
		std::cout << "No avilable memory\n";
		return;
	}
	for (int i = 0; i < freeBlocks.size(); ++i)
	{
		char buffer[disk.BLOCK_SIZE]{};
		size_t startIdx = disk.BLOCK_SIZE * static_cast<size_t>(i);
		size_t endIdx = std::min(size, startIdx + disk.BLOCK_SIZE);
		std::copy(content + startIdx, content + endIdx, buffer);
		disk.writeBlock(freeBlocks[i], buffer);
	}
	fat.addFile(fileName, freeBlocks);
	std::cout << "File created: " << fileName << "\n";
}

void FileSys::deleteFile(const std::string& fileName) {
	if (!fat.fileExists(fileName))
	{
		std::cout << "File does not exist\n";
		return;
	}
	auto usedBlocks = fat.getFileBlocks(fileName);
	for (auto blockIndex : usedBlocks) disk.freeBlock(blockIndex);
	fat.deleteFile(fileName);
	std::cout << "File deleted:" << fileName << "\n";
}

void FileSys::readFile(const std::string& fileName) {
	if (!fat.fileExists(fileName)) {
		std::cout << "File does not exist\n";
		return;
	}
	std::vector<int> fileBlocks{ fat.getFileBlocks(fileName) };

	char* buffer = new char[fileBlocks.size() * disk.BLOCK_SIZE];

	std::cout << "Reading from " << fileName << ": ";
	for (int i{ 0 }; i < fileBlocks.size(); ++i)
	{
		disk.readBlock(fileBlocks[i], buffer + i * disk.BLOCK_SIZE);
	}
	std::cout << buffer;
	delete[] buffer;
	std::cout << "\n";
}