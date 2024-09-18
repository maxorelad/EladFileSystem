# Simple File System Simulator

This project is a **Simple File System Simulator** written in C++. It mimics basic file system operations such as creating, reading, and deleting files, using a simulated disk and free block management.

**Note:** The system assumes that all files are strings (text files) and not binary files.

## Features

- **File Creation**: Create files with content, and the file system automatically splits large files across multiple blocks.
- **File Reading**: Retrieve and display content stored in files.
- **File Deletion**: Remove files and reclaim their associated disk blocks.
- **Free Block Management**: Keeps track of free and used disk blocks using a bitmap.
- **File Allocation Table (FAT)**: Maps file names to their respective disk blocks.

### Class Descriptions

#### `Disk`
- Simulates the physical disk storage.
- Manages blocks of fixed size.
- Uses a bitmap to track free and occupied blocks.
- Contains methods for reading, writing, and freeing blocks.

#### `FAT (File Allocation Table)`
- Maps file names to their respective disk blocks.
- Handles file creation, deletion, and block tracking.

#### `FileSys (File System)`
- High-level interface for file operations: creation, reading, and deletion.
- Interfaces with `Disk` and `FAT` classes to manage file storage and block usage.

## How It Works

1. **Block Allocation**: The disk is divided into fixed-size blocks. Each file occupies one or more blocks depending on its size.
2. **File Creation**: When a file is created, the system finds free blocks, splits the content across those blocks, and stores them on the disk.
3. **File Deletion**: When a file is deleted, the associated blocks are marked as free and can be reused.
4. **File Reading**: The content of a file is read block-by-block and concatenated into the final output.

