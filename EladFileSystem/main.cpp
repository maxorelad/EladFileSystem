#include "FileSys.h"
#include <iostream>

void testCreateFile(FileSys& fs, const std::string& fileName, const char* content) {
    std::cout << "\nCreating file: " << fileName << "\n";
    fs.createFile(fileName, content);
}

void testDeleteFile(FileSys& fs, const std::string& fileName) {
    std::cout << "\nDeleting file: " << fileName << "\n";
    fs.deleteFile(fileName);
}

void testReadFile(FileSys& fs, const std::string& fileName) {
    std::cout << "\nReading file: " << fileName << "\n";
    fs.readFile(fileName);
}

int main() {
    FileSys fileSystem;

    // Test 1: Create a small file
    testCreateFile(fileSystem, "file1.txt", "Hello, world!");

    // Test 2: Create a large file that fills several blocks
    std::string largeContent(500, 'A');  // 500 characters long
    testCreateFile(fileSystem, "largeFile.txt", largeContent.c_str());

    // Test 3: Create an empty file
    testCreateFile(fileSystem, "emptyFile.txt", "");

    // Test 4: Try to create a file that already exists
    testCreateFile(fileSystem, "file1.txt", "Duplicate file");

    // Test 5: Read existing files
    testReadFile(fileSystem, "file1.txt");
    testReadFile(fileSystem, "largeFile.txt");
    testReadFile(fileSystem, "emptyFile.txt");

    // Test 6: Read a non-existent file
    testReadFile(fileSystem, "nonExistent.txt");

    // Test 7: Delete a file that exists
    testDeleteFile(fileSystem, "file1.txt");

    // Test 8: Delete a file that doesn't exist
    testDeleteFile(fileSystem, "file1.txt");

    // Test 9: Read a file that was deleted
    testReadFile(fileSystem, "file1.txt");

    // Test 10: Fill the disk completely by creating many small files
    for (int i = 0; i < 1019; ++i) {
        std::string fileName = "smallFile" + std::to_string(i) + ".txt";
        std::string content(100, 'B');  // Each file contains 100 characters
        testCreateFile(fileSystem, fileName, content.c_str());
    }

    // Test 11: Try to create a file when the disk is full
    std::string hugeContent(5000, 'C');  // Large file that exceeds remaining space
    testCreateFile(fileSystem, "hugeFile.txt", hugeContent.c_str());

    // Test 12: Delete a file and create another to reclaim space
    testDeleteFile(fileSystem, "smallFile0.txt");
    testCreateFile(fileSystem, "reclaimSpaceFile.txt", "This file reclaims space.");

    // Test 13: Ensure that creating and deleting files work after disk is nearly full
    testDeleteFile(fileSystem, "largeFile.txt");
    testCreateFile(fileSystem, "newFileAfterDelete.txt", "New content after delete.");

    return 0;
}
