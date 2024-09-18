#include "Disk.h"

Disk::Disk() {
	memset(blocks, 0, sizeof(blocks));
	memset(blockBitmap, 0, sizeof(blockBitmap));
}

void Disk::readBlock(int blockNum, char* buffer) const {
	memcpy(buffer, blocks[blockNum], BLOCK_SIZE);
}

void Disk::writeBlock(int blockNum, const char* data) {
	memcpy(blocks[blockNum], data, BLOCK_SIZE);
	blockBitmap[blockNum] = true;
}

void Disk::freeBlock(const int blockNum) {
	blockBitmap[blockNum] = false;
	memset(blocks[blockNum], 0, BLOCK_SIZE);
}

std::vector<int> Disk::findFreeBlocks(int amount) {
	std::vector<int> freeBlocks;
	for (int i{ 0 }; i < DISK_SIZE; ++i) {
		if (!blockBitmap[i]) freeBlocks.push_back(i);
		if (freeBlocks.size() == amount) break;
	}
	if (freeBlocks.size() != amount) return (std::vector<int>(1, -1));
	for (auto blockNum : freeBlocks) blockBitmap[blockNum] = true;
	return freeBlocks;
}