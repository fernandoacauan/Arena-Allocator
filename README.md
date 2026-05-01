# Arena Allocator
> **Author: Fernando A.**

A high-performance, block-based **Arena Allocator** implemented in C++. This project provides a fast and efficient way to manage memory in performance-critical applications by allocating large contiguous blocks and serving memory linearly.

## Key Features

*   **O(1) Allocation**: Memory allocation is performed by simply incrementing a pointer, providing constant time performance.
*   **Automatic Alignment**: Ensures all allocated memory is properly aligned for the target architecture using a dedicated `union align` logic.
*   **Mass Deallocation**: Entire memory arenas can be freed at once, eliminating the need to track or delete individual objects manually.
*   **Multiple Independent Arenas**: Supports a pool of up to 3 independent arenas for different subsystems.
*   **Placement New Support**: Compatible with C++ object construction directly into arena-managed memory.

## Technical Architecture

The allocator manages memory in chunks of **64KB** (you can change this by changing ARENA_SIZE). When a request is made, the internal pointer "bumps" forward by the requested size, plus any necessary padding for alignment. If a block lacks sufficient space, a new block is automatically allocated and linked to the chain.

### Memory Alignment
The system uses a `union` of primitive types (pointers, longs, doubles, functions) to determine the strictest alignment requirements of the host CPU. All allocations are rounded up to this alignment boundary using fast bitwise operations.

## Usage

### 1. Basic Allocation
```cpp
MyClass* myObj = new ( CArena::Alloc(sizeof(MyClass), 0) ) MyClass();
```
### 2. Deallocation
```cpp
// Release all memory blocks associated with Arena 0
CArena::Free( 0 );
```
