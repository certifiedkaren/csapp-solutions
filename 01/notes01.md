# Chapter 1 - A Tour of Compuer Systems

## 1.1 - Information is Bits + Context
- All information in a system is represented using bits, the context in which we view data distinguishes it. 
- Each letter in the hello.c program has an ascii code which is associated with a byte

## 1.2 - Programs Are Translated by other programs into different forms 
hello.c is translated like this 
1. preprocessor - inserts stdio.h code into file
2. compiler - translates c into assembly
3. assemblers - translates assembly into binary inside an object file
4. linker - merges object files

## 1.3 - It pays to understand how compilation systems work
1. Optimizing code performanec
2. Understanding link-time errors
3. Avoiding security holes

## 1.4 - Processors Read and Interpret Instructions Stored in Memory
### Hardware organization of a system 
**Buses** - carry information between components in fixed-size chunkos of bytes called **buses**
**I/O devices** - a systems connection to external world such as keyword, display, and mousethrough an *controller* or *adapter*
**Main Memory** - temporary storage device which holds a program and data it manipulates. Stored in *dynamic random access memory*
**Processor** - executes instructions stored in main memory

## 1.5 - Caches Matter
- The system spends a lot of time moving information from one place to another
- Processors registers are small, so L1, L2, and L3 **caches** were created to serve as places to store data the cpu will likely need. These are faster to access than the main memory.
- CPU can read data from registers about 100x faster than from main memory. 
- L1 Cache can be accessed nearly as fast as register file, while L2 cache can be 5-10 times faster than main memory.

## 1.6 - Storage Devices Form a Hierarchy
- Pyramid like hierachy of smaller, faster storage devices at the top.
ex. Regs -> L1 cache -> L2 cache -> L3 cache -> Main Memory -> Local Secondary Storage -> Remote secondary storage

## 1.7 - The Operating System Manages the Hardware
- Operating system is the layer between software and hardware
- **Process** - operating system's abstraction for running a program
- The cpu can execute multiple processes concurrently
- The operating system keeps track of all the information a process needs to run, and can transfer control to some new process. This is known as **context switching**
- A process contains multiple execution units called **Threads**  
- **Virtual Memory** is an abstraction that gives each process the illusion that it has exclusive access to the main memory

## 1.8 - Systems Communicate with Other Systems Using Networks
- Network allows computers to send and recieve data and copy this into the memory
- Bytes pass through the network instead of a bus

## 1.9 - Important Themes
### Amdahl's Law
- **Amdahl's Law** - If one part of a system is sped up, the effect on the overall system depends on how big a role that part plays in the system and the speed increase of that part. 
a = fraction part makes up
k = performance improvement
- S = 1 / ((1-a) + a/k)

### Concurrency and Parallelism
**concurrency** - a system with multiple, simulatneous activites
**parallelism** - use of concurrency to make a system faster

- modern multicore-processors contain **cores**, which are CPUS intergrated onto a single board.
- **simultaneous multi-threading** - CPU can execute multiple tasks at once, switching between the processes.
**instruction-level parallelism** - executing multiple instructions at one time
**single-instruction, multiple-data (SIMD)** - single instruction can cause multiple operations to be performed in parralel

