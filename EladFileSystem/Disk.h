#pragma once
#include <cstring>
#include <vector>
class Disk
{
public:
	static const int DISK_SIZE{ 1024 };
	static const int BLOCK_SIZE{ 128 };


	Disk();

	void readBlock(int blockNum, char* buffer) const;

	void writeBlock(int blockNum, const char* data);

	void freeBlock(const int blockNum);

	std::vector<int> findFreeBlocks(int amount);
private:
	char blocks[DISK_SIZE][BLOCK_SIZE];
	bool blockBitmap[DISK_SIZE];
};

