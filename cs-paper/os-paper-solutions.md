# Operating Systems Paper Solutions

## Section-A

### 1(a) Differentiate between user mode and Kernel mode execution of a process. (3 marks)

**User Mode:**
- Restricted access to system resources and hardware
- Cannot execute privileged instructions or directly access memory
- Programs run with limited privileges for safety

**Kernel Mode:**
- Full access to all system resources and hardware
- Can execute privileged instructions and directly manipulate memory
- Used by the OS kernel to perform critical system operations

When a process needs system services, it switches from user mode to kernel mode through system calls.

### 1(b) Explain the purpose of system programs. (3 marks)

System programs provide a convenient environment for program development and execution. They serve as an interface between users and the computer hardware. Their purposes include:

- Managing system resources like files, memory, and devices
- Providing utilities for file manipulation, status information, and programming language support
- Handling program loading, execution, and debugging
- Offering communication interfaces between processes and users
- Supporting system maintenance and management tasks

### 1(c) What is the context switching? (3 marks)

Context switching is the process of saving the state (context) of a currently executing process and restoring the saved state of another process when switching CPU control between them. The context includes:

- Program counter value
- Register contents
- Memory mapping information
- Process state information in PCB

Context switching is essential for multitasking but introduces overhead as it consumes CPU time for saving and restoring contexts rather than executing processes.

### 1(d) What is the compaction? (3 marks)

Compaction is a memory management technique used to eliminate external fragmentation in systems using contiguous memory allocation. It involves:

- Relocating all occupied memory blocks to one end of memory
- Combining all free memory blocks into a single large block
- Updating all memory references in the relocated processes

This process is time-consuming as it requires stopping normal execution, moving processes in memory, and updating their addresses, but it significantly improves memory utilization.

### 1(e) What is the drawback of priority scheduling algorithm? How it can be resolved? (3 marks)

**Drawback:** Priority scheduling can lead to indefinite blocking or starvation of low-priority processes if high-priority processes continuously arrive, preventing lower priority processes from ever executing.

**Resolution:** This can be resolved through aging, a technique where the priority of a process is gradually increased the longer it waits in the ready queue. This ensures that a low-priority process will eventually reach a high enough priority level to be executed, preventing indefinite starvation.

### 1(f) What are the three different types of process scheduler in operating system? (3 marks)

The three types of process schedulers in an operating system are:

1. **Long-term scheduler (Job scheduler)**: Selects processes from the job pool and loads them into memory for execution. Controls the degree of multiprogramming.

2. **Mid-term scheduler**: Temporarily removes processes from memory to reduce system load (swapping), and reintroduces them later when conditions improve.

3. **Short-term scheduler (CPU scheduler)**: Selects which process in the ready queue should be allocated the CPU next. Executes most frequently of all schedulers.

### 1(g) What is convoy effect in CPU scheduling? (3 marks)

The convoy effect is a phenomenon that occurs in CPU scheduling when a long-running process blocks shorter processes, causing a "convoy" of waiting processes behind it. This typically happens in First-Come-First-Served (FCFS) scheduling algorithm where:

- A CPU-intensive process holds the processor for extended periods
- All other processes (even short ones) must wait for their turn
- Results in high average waiting time and poor system throughput

This is one of the major reasons FCFS is not optimal for interactive systems.

### 1(h) Consider a logical address space of 64 pages of 1024 words each, mapped onto a physical memory of 32 frames. (3 marks)

(i) How many bits are there in the logical address?

Logical address space = 64 pages × 1024 words = 65,536 words
To represent 65,536 distinct addresses, we need log₂(65,536) = 16 bits.

(ii) How many bits are required to address each word in a frame?

Each frame contains 1024 words.
To address 1024 distinct words within a frame, we need log₂(1024) = 10 bits.

### 1(i) Distinguish between absolute and relative path name. (3 marks)

**Absolute Path Name:**
- Starts from the root directory and contains the complete path hierarchy
- Always begins with a root symbol (/ in UNIX-based systems)
- Specifies the exact location regardless of the current working directory
- Example: `/home/user/documents/file.txt`

**Relative Path Name:**
- Defined in relation to the current working directory
- Does not begin with a root symbol
- Location changes if the current working directory changes
- Example: `documents/file.txt` (when in `/home/user/`)

### 1(j) Explain the use of UNIX commands: (3 marks)

(i) **mkdir (Make Directory)**:
- Creates a new directory in the file system
- Syntax: `mkdir [options] directory_name`
- Example: `mkdir projects` creates a new directory named "projects"

(ii) **pwd (Print Working Directory)**:
- Displays the current working directory's absolute path
- Shows the full path from root to the current location
- Essential for orientation in the file system hierarchy

(iii) **cd (Change Directory)**:
- Changes the current working directory to specified location
- Syntax: `cd [directory]`
- Examples: `cd /home/user`, `cd ..` (move up one level), `cd ~` (go to home directory)

## Section-B

### 2(a)(i) What are the goals of operating System? Explain Batch Operating System, multiprocessor system and real time Operating with suitable example? (4 marks)

**Goals of Operating Systems:**
- Provide a convenient interface between users and hardware
- Efficiently manage computer resources (CPU, memory, I/O devices)
- Execute user programs and solve user problems
- Make the computer system easy to use
- Ensure data security and system stability

**Batch Operating System:**
A batch operating system processes jobs in batches without user interaction. Multiple similar jobs are grouped together and executed sequentially.
Example: IBM's OS/360 processed payroll calculations for companies by taking batches of punch cards, executing the jobs, and providing output without interaction.

**Multiprocessor System:**
These systems contain two or more processors sharing the same physical memory and peripheral devices. They provide increased throughput, enhanced reliability, and economy of scale.
Example: Modern server systems like those running in data centers often have multiple processors to handle large workloads simultaneously.

**Real-time Operating System:**
Designed for applications where data processing must be done within defined time constraints. Used when rigid time requirements exist.
Example: Aircraft control systems that must process sensor data and adjust flight surfaces within milliseconds to maintain stability, or patient monitoring systems in hospitals that must respond immediately to critical changes.

### 2(a)(ii) List any two different types of mass storage devices. Explain seek time, rotational latency time, and data transfer rate in the disk? (4 marks)

**Two types of mass storage devices:**

1. **Hard Disk Drives (HDDs)**: Mechanical storage devices using magnetic platters for data storage.
2. **Solid State Drives (SSDs)**: Electronic storage devices using flash memory with no moving parts.

**Seek Time:**
The time taken by the disk arm to position the read/write head from its current location to the desired track where data is located. For HDDs, it typically ranges from 3-15ms, while SSDs have negligible seek times (near 0ms) due to no mechanical movement.

**Rotational Latency Time:**
The time required for the desired sector to rotate under the read/write head after the head has been positioned over the correct track. It depends on the rotational speed of the disk (e.g., 7200 RPM) and averages half a rotation. For HDDs, typical values are 2-8ms. SSDs have no rotational latency.

**Data Transfer Rate:**
The speed at which data can be transmitted between the disk and computer once the read/write head is positioned at the correct location. It's measured in MB/s or GB/s. Modern HDDs typically offer 80-160 MB/s, while SSDs can achieve 500-3500 MB/s depending on the interface (SATA vs. NVMe).

### 2(b)(i) Briefly explain the layered approach and discuss its advantages and disadvantages for system design. (4 marks)

**Layered Approach in System Design:**
The layered approach organizes an operating system into a hierarchy of layers, each built upon the one below it. Each layer provides functions that higher layers can use, and uses functions provided by lower layers. A typical layered OS structure might include:

- Layer 5: User interface layer
- Layer 4: User program and utilities
- Layer 3: I/O management
- Layer 2: Communication between processes
- Layer 1: Memory and device management
- Layer 0: Hardware (CPU, memory, devices)

**Advantages:**
- Simplifies debugging and system verification as errors can be localized to specific layers
- Provides modularity, making the system easier to understand and modify
- Enables incremental development where each layer can be implemented and tested independently
- Enhances security by restricting access to lower-level functions

**Disadvantages:**
- Reduced performance due to additional overhead from layer traversal
- Difficulty in appropriately layering some OS functions
- May require careful planning to define functions in each layer
- Functions may need to be duplicated in different layers
- Decreased efficiency compared to non-layered approaches

### 2(b)(ii) What are system calls? Explain different types of system calls. (3 marks)

**System Calls:**
System calls are programming interfaces provided by the operating system to allow user-level programs to request services from the kernel. They serve as the interface between user applications and the operating system.

**Types of System Calls:**

1. **Process Control**: Create/terminate processes, load/execute programs, get/set process attributes
   Examples: fork(), exit(), wait(), exec()

2. **File Management**: Create/delete files, open/close/read/write files, get/set file attributes
   Examples: open(), close(), read(), write(), unlink()

3. **Device Management**: Request/release devices, read/write to devices, get/set device attributes
   Examples: ioctl(), read(), write() (when applied to devices)

4. **Information Maintenance**: Get/set time/date, get/set system data, get process/file/device attributes
   Examples: getpid(), alarm(), sleep()

5. **Communication**: Create/delete communication connections, send/receive messages
   Examples: pipe(), shmget(), mmap(), socket(), send(), recv()

6. **Protection**: Control access to resources, get/set permissions
   Examples: chmod(), chown(), umask()

### 3(a) Consider the following set of processes, with the length of the CPU burst time given in milliseconds: (8 marks)

| Process | Arrival time | Burst Time |
|---------|-------------|------------|
| P1      | 0           | 7          |
| P2      | 1           | 5          |
| P3      | 2           | 3          |
| P4      | 3           | 1          |
| P5      | 4           | 2          |
| P6      | 5           | 4          |

(i) Draw Gantt chart that illustrate the execution schedule of these processes using preemptive SJF scheduling algorithm.

For Preemptive Shortest Job First (also known as Shortest Remaining Time First), we need to re-evaluate at each arrival time:

Time 0: Only P1 is available, so P1 starts execution.
Time 1: P2 arrives with burst time 5, which is shorter than P1's remaining time (6), so P1 is preempted and P2 starts.
Time 2: P3 arrives with burst time 3, which is shorter than P2's remaining time (4), so P2 is preempted and P3 starts.
Time 3: P4 arrives with burst time 1, which is shorter than P3's remaining time (2), so P3 is preempted and P4 starts.
Time 4: P4 completes. P5 arrives with burst time 2, which is equal to P3's remaining time (2), but P3 arrived earlier, so P3 resumes.
Time 5: P6 arrives with burst time 4, longer than both P3's remaining time (1) and P5's burst time (2), so P3 continues.
Time 6: P3 completes. P5 with burst time 2 is the shortest, so P5 starts.
Time 8: P5 completes. P2 with remaining time 4 is shorter than P1's remaining time (6) and P6's burst time (4), but since P2 arrived earlier, P2 starts.
Time 12: P2 completes. P6 with burst time 4 is shorter than P1's remaining time (6), so P6 starts.
Time 16: P6 completes. Only P1 remains with 6 time units, so P1 executes until completion.
Time 22: P1 completes and all processes are finished.

Gantt Chart:
```
0      1      3      4      6      8             12            16            22
|---P1--|--P3--|--P4--|--P3--|--P5--|-----P2------|-----P6------|------P1------|
```

(ii) Calculate the turnaround time and waiting time of each process. Also compute average turnaround time and average waiting time.

Turnaround Time = Completion Time - Arrival Time
Waiting Time = Turnaround Time - Burst Time

P1: Completion Time = 22
    Turnaround Time = 22 - 0 = 22
    Waiting Time = 22 - 7 = 15

P2: Completion Time = 12
    Turnaround Time = 12 - 1 = 11
    Waiting Time = 11 - 5 = 6

P3: Completion Time = 6
    Turnaround Time = 6 - 2 = 4
    Waiting Time = 4 - 3 = 1

P4: Completion Time = 4
    Turnaround Time = 4 - 3 = 1
    Waiting Time = 1 - 1 = 0

P5: Completion Time = 8
    Turnaround Time = 8 - 4 = 4
    Waiting Time = 4 - 2 = 2

P6: Completion Time = 16
    Turnaround Time = 16 - 5 = 11
    Waiting Time = 11 - 4 = 7

Average Turnaround Time = (22 + 11 + 4 + 1 + 4 + 11) / 6 = 53 / 6 = 8.83 ms
Average Waiting Time = (15 + 6 + 1 + 0 + 2 + 7) / 6 = 31 / 6 = 5.17 ms

### 3(b)(i) What is PCB? What information is contained in the PCB? (3 marks)

**Process Control Block (PCB):**
A PCB is a data structure maintained by the operating system for every process. It serves as the repository for all the information needed to manage a process throughout its lifecycle.

**Information contained in PCB:**

1. **Process Identification**:
   - Process ID (PID)
   - Parent process ID
   - User ID

2. **Processor State Information**:
   - Program Counter (PC) - indicates the next instruction
   - CPU registers
   - Processor Status Word (PSW)
   - Stack pointers

3. **Process Control Information**:
   - Process state (new, ready, running, waiting, terminated)
   - Scheduling information (priority, pointers to scheduling queues)
   - Memory management information (base and limit registers, page tables)
   - I/O status information (list of open files, pending I/O requests)
   - Accounting information (CPU time used, time limits)
   - Interprocess communication information

The PCB is created when a process is created and deleted when it terminates, acting as the process's representation within the operating system.

### 3(b)(ii) Explain the different states of a Process with a suitable diagram? (4 marks)

**Process States:**

1. **New**: The process is being created. The operating system is allocating resources to the process.

2. **Ready**: The process is loaded into main memory and is waiting to be assigned to a processor. It has all the resources needed except the CPU.

3. **Running**: The process is currently being executed by the CPU. The program counter of the CPU points to an instruction of the process.

4. **Waiting/Blocked**: The process is waiting for some event to occur, such as completion of an I/O operation or receipt of a signal. It cannot proceed until the event occurs.

5. **Terminated**: The process has finished execution. The operating system will recover resources allocated to this process.

**Process State Diagram:**
```
                  ┌───────────────┐
                  │               │
                  ▼               │ CPU Scheduler
            ┌───────────┐  dispatch
New ───────►│   Ready   ├─────────────┐
            └───────────┘             │
                  ▲                   │
                  │                   │
                  │                   ▼
┌──────────┐      │            ┌───────────┐
│ Waiting/ │      │            │  Running  │───────► Terminated
│ Blocked  │◄─────┴────────────┘───────────┘
└──────────┘    I/O or event    I/O or event wait
                 completion
```

The process moves from:
- New to Ready when admitted to the system
- Ready to Running when the CPU scheduler selects it
- Running to Waiting when it requests I/O or waits for an event
- Waiting to Ready when the I/O completes or event occurs
- Running to Ready when interrupted (preemption)
- Running to Terminated when execution completes

### 4(a) Given four memory partitions of 100KB, 500KB, 200KB and 600KB (in order), how would each of the first fit, best fit and worst fit algorithms place processes of 212KB, 417KB, 112KB and 426KB (in order)? (6 marks)

**Memory Partitions**: 100KB, 500KB, 200KB, 600KB

**First Fit Algorithm**:
- Process 212KB: Allocated to the 500KB partition (leaving 288KB)
- Process 417KB: Allocated to the 600KB partition (leaving 183KB)
- Process 112KB: Allocated to the 288KB fragment in the 500KB partition (leaving 176KB)
- Process 426KB: Cannot be allocated (no partition large enough)

Final state:
- 100KB partition: Free
- 500KB partition: 176KB free (fragmented)
- 200KB partition: Free
- 600KB partition: 183KB free (fragmented)

**Best Fit Algorithm**:
- Process 212KB: Allocated to the 500KB partition (closest fit, leaving 288KB)
- Process 417KB: Allocated to the 500KB partition's 288KB fragment (not enough space)
  So it goes to 600KB partition (leaving 183KB)
- Process 112KB: Allocated to the 200KB partition (closest fit, leaving 88KB)
- Process 426KB: Cannot be allocated (no partition large enough)

Final state:
- 100KB partition: Free
- 500KB partition: 288KB free (fragmented)
- 200KB partition: 88KB free (fragmented)
- 600KB partition: 183KB free (fragmented)

**Worst Fit Algorithm**:
- Process 212KB: Allocated to the 600KB partition (largest, leaving 388KB)
- Process 417KB: Allocated to the 500KB partition (largest remaining, leaving 83KB)
- Process 112KB: Allocated to the 388KB fragment in the 600KB partition (largest, leaving 276KB)
- Process 426KB: Cannot be allocated (no partition large enough)

Final state:
- 100KB partition: Free
- 500KB partition: 83KB free (fragmented)
- 200KB partition: Free
- 600KB partition: 276KB free (fragmented)

### 4(b)(i) What is Demand Paging in Operating System? Explain its advantages and disadvantages. (5 marks)

**Demand Paging:**
Demand paging is a memory management technique where pages are loaded into physical memory only when they are requested (demanded) by a process during execution, rather than loading the entire process into memory at once. The operating system brings a page into memory only when a reference is made to a location on that page, causing a page fault.

**Advantages:**

1. **Less Memory Usage**: Only necessary pages are loaded, allowing more processes to fit in memory simultaneously.

2. **More Efficient Use of CPU**: CPU time is not wasted loading pages that may never be used.

3. **Less I/O Required**: Less data transfer from disk to memory since only needed pages are loaded.

4. **Faster Process Startup**: Processes can begin execution without waiting for their entire memory space to be allocated and loaded.

5. **Support for Large Address Spaces**: Processes can have address spaces much larger than physical memory.

**Disadvantages:**

1. **Page Fault Overhead**: Each page fault introduces significant overhead due to:
   - Trap to operating system
   - Saving process state
   - Determining page location on disk
   - Reading the page from disk
   - Updating page tables
   - Restoring process state

2. **Performance Impact**: High rate of page faults can severely degrade system performance (thrashing).

3. **Complexity**: Requires hardware support (page tables, MMU) and more complex OS algorithms.

4. **Additional Storage**: Requires secondary storage for page swapping.

5. **Unpredictable Performance**: Execution time can vary based on page fault frequency, making real-time guarantees difficult.

### 4(b)(ii) Consider a system which has main memory access time of 100ns and TLB access time of 20ns, and TLB hit ratio of 95%. What will be the effective memory access time with TLB and without TLB? (4 marks)

**Without TLB:**
Without a TLB, every memory access requires a direct access to the page table in main memory followed by the actual memory access.

Effective Memory Access Time = Page Table Access Time + Memory Access Time
                             = 100ns + 100ns
                             = 200ns

**With TLB:**
With a TLB, we have two scenarios:
1. TLB Hit (95% of times): TLB Access Time + Memory Access Time
2. TLB Miss (5% of times): TLB Access Time + Page Table Access Time + Memory Access Time

Effective Memory Access Time = (TLB Hit Ratio × Time for TLB Hit) + (TLB Miss Ratio × Time for TLB Miss)
                             = (0.95 × (20ns + 100ns)) + (0.05 × (20ns + 100ns + 100ns))
                             = (0.95 × 120ns) + (0.05 × 220ns)
                             = 114ns + 11ns
                             = 125ns

Therefore, the effective memory access time with TLB is 125ns, which is significantly better than the 200ns without TLB.

### 5(a)(i) Explain the purpose of the open() and close() system calls in file operations. (4 marks)

**open() System Call:**
The open() system call is used to establish a connection between a file and a process. Its purposes include:

1. **File Access**: It creates a file descriptor (an integer) that the process can use to access the file in subsequent operations.

2. **Permission Verification**: It checks whether the process has appropriate permissions to access the file in the requested mode (read, write, execute).

3. **File Creation**: With appropriate flags, it can create a new file if it doesn't exist.

4. **Mode Specification**: It allows the specification of how the file will be accessed (read-only, write-only, read-write).

5. **File Position**: It sets up the file position pointer to the beginning of the file (or to the end with appropriate flags).

Syntax: `int open(const char *pathname, int flags, mode_t mode);`

**close() System Call:**
The close() system call is used to terminate the connection between a file and a process. Its purposes include:

1. **Resource Release**: It releases the file descriptor and associated resources, making them available for reuse.

2. **Buffer Flushing**: It ensures that any buffered data is written to the file before closing.

3. **System Limit Management**: It helps manage the limit on the number of open files per process.

4. **File Integrity**: It properly finalizes file operations, preventing data corruption.

Syntax: `int close(int fd);`

Together, these system calls form the foundation of file I/O operations in operating systems.

### 5(a)(ii) Consider a system which has main memory access time of 35ns and page fault service time of 175ns and page hit ratio is 75%. What will be the effective memory access time? (3 marks)

For a system with paging, the effective memory access time depends on:
- Memory access time (when the page is in memory)
- Page fault service time (when the page is not in memory)
- Page hit ratio (percentage of times the page is found in memory)

Given:
- Main memory access time = 35ns
- Page fault service time = 175ns
- Page hit ratio = 75% (or 0.75)
- Page fault ratio = 1 - 0.75 = 0.25

The effective memory access time can be calculated as:

Effective Access Time = (Page Hit Ratio × Memory Access Time) + (Page Fault Ratio × Page Fault Service Time)
                      = (0.75 × 35ns) + (0.25 × (175ns + 35ns))
                      = 26.25ns + (0.25 × 210ns)
                      = 26.25ns + 52.5ns
                      = 78.75ns

Therefore, the effective memory access time is 78.75ns.

### 5(b)(i) What is file system? Explain various file operations in file system? (5 marks)

**File System:**
A file system is the part of an operating system that organizes, stores, retrieves, names, and protects data on storage devices. It provides an abstraction layer between the physical storage hardware and the logical representation of data as files and directories that applications can interact with.

**File Operations:**

1. **Creation**: Establishing a new file in the file system
   - Allocates space for the file
   - Creates a new directory entry
   - Initializes file attributes and metadata
   - Example: `create()`, `open()` with O_CREAT flag

2. **Opening**: Preparing a file for access
   - Locates the file on disk
   - Creates in-memory structures to track file access
   - Verifies access permissions
   - Returns a file descriptor or handle
   - Example: `open()`, `fopen()`

3. **Reading**: Retrieving data from a file
   - Transfers data from file to memory buffer
   - Updates file position pointer
   - May involve caching for performance
   - Example: `read()`, `fread()`

4. **Writing**: Storing data to a file
   - Transfers data from memory buffer to file
   - May allocate additional space if needed
   - Updates file size and modification time
   - Example: `write()`, `fwrite()`

5. **Seeking**: Repositioning within a file
   - Changes the current position pointer
   - Allows random access to file contents
   - Example: `lseek()`, `fseek()`

6. **Deletion**: Removing a file from the file system
   - Removes directory entry
   - Deallocates file storage space
   - Updates parent directory information
   - Example: `unlink()`, `remove()`

7. **Truncation**: Reducing file size
   - Shortens file to specified length
   - Frees unused space
   - Example: `truncate()`, `ftruncate()`

8. **Closing**: Terminating access to a file
   - Flushes any cached data to disk
   - Frees in-memory structures
   - Updates file metadata
   - Example: `close()`, `fclose()`

9. **Attribute Manipulation**: Changing file properties
   - Modifies permissions, timestamps, ownership
   - Example: `chmod()`, `chown()`, `utime()`

### 5(b)(ii) Briefly, explain single-level, multi-level, and acyclic graph directories? (3 marks)

**Single-Level Directory:**
A flat directory structure where all files reside in one directory without any hierarchical organization.

- All files must have unique names
- Limited organization capability for large numbers of files
- Difficult to manage as number of files increases
- Multiple users cannot have files with the same name
- Example: Early simple operating systems

**Multi-Level Directory:**
A hierarchical structure with directories containing both files and other directories (subdirectories), forming a tree structure.

- Allows efficient organization of files
- Provides path names to locate files
- Supports grouping of related files
- Different users can have same file names in different directories
- Enables efficient searching and navigation
- Example: Most modern file systems (Windows, Unix)

**Acyclic Graph Directory:**
An extension of the multi-level directory structure that allows sharing of files/directories without duplication through links, while maintaining no cycles.

- Subdirectories can be shared (appear in multiple directories)
- Files can have multiple paths (aliases or shortcuts)
- Reduces redundancy by allowing shared access to files
- Maintains hierarchy but with controlled sharing
- Delete operations need special handling to prevent dangling references
- Example: Unix file systems with symbolic links, Windows with shortcuts

### 6(a) Explain the terms: (6 marks)

**(i) Swapping**

Swapping is a memory management mechanism where entire processes are temporarily moved from main memory to secondary storage (swap space or backing store) and later brought back into memory for continued execution. Key aspects include:

- Involves transferring complete process images between memory and disk
- Used to free up memory when the system is overcommitted
- Processes chosen for swapping are typically those in a blocked or waiting state
- Allows for higher degree of multiprogramming than physical memory would normally support
- Introduces overhead due to time spent in disk transfers
- Less granular than paging as it operates on entire processes
- Modern systems often use a combination of swapping and paging

Swapping is particularly useful for managing memory in systems where physical memory is limited relative to the demands of active processes.

**(ii) Virtual Memory**

Virtual memory is a memory management technique that provides an idealized abstraction of the storage resources that are actually available on a given machine. Key characteristics include:

- Creates an illusion of a very large, contiguous memory space (address space) for each process
- Allows processes to use more memory than physically available in RAM
- Separates logical memory as viewed by the process from physical memory
- Enables processes to run with only parts of their address space loaded in physical memory
- Implemented through paging or segmentation, with paging being more common
- Uses demand loading to bring pages into memory only when needed
- Includes page replacement algorithms to manage which pages stay in memory
- Enables memory protection between processes
- Supports efficient memory utilization and sharing

Virtual memory is fundamental to modern operating systems, enabling robust multitasking and efficient resource utilization.

**(iii) Page Fault**

A page fault is an exception raised by the memory management unit (MMU) when a process attempts to access a page that is not currently mapped to physical memory. Key elements include:

- Occurs when a referenced page is valid but not in physical memory
- Triggers the operating system's page fault handler
- Results in the OS locating the page on disk and loading it into memory
- May require replacing an existing page if memory is full
- Includes updating page tables to reflect the new page mapping
- Incurs significant overhead due to disk I/O operations
- Has three main types:
  * Minor: Page is in memory but not marked in MMU (e.g., shared pages)
  * Major: Page must be loaded from disk
  * Invalid: Illegal memory access (segmentation fault)
- Performance is heavily influenced by page fault rate

Page faults are essential to the functioning of virtual memory systems, but excessive page faults (thrashing) can severely degrade performance.

### 6(b)(i) Explain the single threaded and multithreaded process. What are the advantages of Threads in Operating Systems? (6 marks)

**Single-Threaded Process:**
A single-threaded process contains exactly one thread of execution. The process executes its instructions sequentially, with one program counter tracking execution progress. It has a single stack for function calls and local variables, and cannot perform multiple tasks simultaneously within the process.

Key characteristics:
- One flow of control
- Sequential execution of instructions
- Single point of execution at any time
- Simple programming model
- Limited ability to utilize multiple processors

**Multithreaded Process:**
A multithreaded process contains multiple threads of execution within the same process address space. Each thread has its own program counter, stack, and register set, but shares code, data, and other resources with other threads in the same process.

Key characteristics:
- Multiple flows of control within a single process
- Parallel execution of tasks
- Shared memory space among all threads
- Independent scheduling of threads
- Ability to utilize multiple processors simultaneously

**Advantages of Threads in Operating Systems:**

1. **Resource Sharing**: Threads share memory and resources of the process, making communication between threads more efficient and reducing resource overhead compared to separate processes.

2. **Responsiveness**: Applications remain responsive to user input while performing background operations in separate threads (e.g., typing in a word processor while spell checking runs).

3. **Economy**: Creating and managing threads requires fewer system resources than creating and managing processes. Thread context switching is usually faster than process context switching.

4. **Scalability**: Multithreaded applications can take advantage of multiprocessor or multi-core architectures, improving performance through parallel execution.

5. **Improved Throughput**: Multiple threads can perform different tasks simultaneously, increasing overall system throughput and efficiency.

6. **Better Communication**: Communication between threads is simpler and faster than inter-process communication since threads share the same address space.

7. **Enhanced Program Structure**: Some problems naturally decompose into multiple concurrent tasks, making multithreaded programming a logical design choice.

### 6(b)(ii) What are the major entries to evaluate the performance of CPU scheduling algorithms? (3 marks)

The major criteria for evaluating CPU scheduling algorithms include:

1. **CPU Utilization**: The percentage of time the CPU is busy. Higher utilization indicates better performance, with the goal being to keep the CPU as busy as possible (ideally 100%).

2. **Throughput**: The number of processes completed per time unit. Higher throughput indicates more efficient processing capacity.

3. **Turnaround Time**: The interval from process submission to completion. Shorter average turnaround time indicates better responsiveness of the system to process execution.

4. **Waiting Time**: The total time a process spends in the ready queue waiting for CPU allocation. Lower average waiting time indicates better scheduling efficiency.

5. **Response Time**: The time from submission of a request until the first response is produced. Critical for interactive systems where user experience depends on quick feedback.

Different scheduling algorithms optimize for different criteria, and the importance of each criterion varies based on the system's purpose (batch system, interactive system, real-time system, etc.).

### 7. Differentiate between following: (15 marks)

**(i) Paging and segmentation**

**Paging:**

1. **Definition**: Paging is a memory management scheme that eliminates the need for contiguous allocation of physical memory by dividing each process's virtual address space into fixed-size blocks called pages, which correspond to fixed-size blocks of physical memory called frames.

2. **Size**: Uses fixed-size blocks (typically powers of 2, e.g., 4KB, 8KB)

3. **Address Structure**: 
   - Virtual address divided into page number and page offset
   - Page number is used as an index into the page table
   - Physical address consists of frame number and offset

4. **Memory Allocation**: Allocation is performed by the operating system and is transparent to the programmer

5. **Internal Fragmentation**: May cause internal fragmentation when process size is not a multiple of page size

6. **External Fragmentation**: Eliminates external fragmentation since frames are fixed-size

7. **Protection**: Protection is implemented at the page level, typically with protection bits in page table entries

8. **Hardware Support**: Requires MMU (Memory Management Unit) with page tables

9. **Sharing**: Sharing of pages among processes is possible but at page granularity

10. **Implementation Complexity**: Relatively simpler to implement

**Segmentation:**

1. **Definition**: Segmentation is a memory management scheme that divides a process's address space into logical segments based on the program's natural divisions (code, stack, heap, data), each with its own length.

2. **Size**: Uses variable-size blocks based on logical divisions of the program

3. **Address Structure**: 
   - Virtual address divided into segment number and segment offset
   - Segment table maps segment numbers to physical addresses
   - Physical address is base address + offset

4. **Memory Allocation**: Allocation reflects the logical view of memory that is visible to the programmer

5. **Internal Fragmentation**: No internal fragmentation as segments are exactly the size needed

6. **External Fragmentation**: Can suffer from external fragmentation as segments vary in size

7. **Protection**: Protection can be implemented at a logical level (read, write, execute permissions per segment)

8. **Hardware Support**: Requires segment tables and base/limit registers

9. **Sharing**: Better suited for sharing code or data as segments represent logical units

10. **Implementation Complexity**: More complex to implement than paging

**(ii) Dispatcher and scheduler**

**Dispatcher:**

1. **Definition**: The dispatcher is the module that gives control of the CPU to the process selected by the short-term scheduler.

2. **Functions**:
   - Context switching (saving state of current process and loading state of new process)
   - Switching to user mode from kernel mode
   - Jumping to the proper location in the user program to restart

3. **Timing**: Invoked during every context switch after a scheduling decision

4. **Performance Metric**: Dispatcher latency (the time it takes to stop one process and start another)

5. **Frequency**: Activated every time a process switch occurs

6. **Role**: Implementation mechanism for the decisions made by the scheduler

7. **Operation Level**: Works at the micro level of actually performing the context switch

8. **CPU Control**: Physically transfers CPU control to the chosen process

9. **Decision Making**: Does not make decisions about which process to run next

10. **Execution Environment**: Runs in privileged (kernel) mode

**Scheduler:**

1. **Definition**: The scheduler is the component that selects which process should be executed next and allocates CPU time accordingly.

2. **Functions**:
   - Selecting processes from various queues
   - Making decisions based on scheduling algorithms
   - Maintaining scheduling queues (ready queue, waiting queue)

3. **Types**:
   - Long-term (job) scheduler: controls degree of multiprogramming
   - Mid-term scheduler: handles swapping
   - Short-term (CPU) scheduler: selects which process gets CPU next

4. **Performance Metrics**: CPU utilization, throughput, turnaround time, waiting time, response time

5. **Algorithms**: Implements scheduling algorithms like FCFS, SJF, Round Robin, Priority Scheduling, etc.

6. **Role**: Decision-making component that determines execution order

7. **Operation Level**: Works at the policy level of deciding which process runs next

8. **CPU Control**: Does not directly control the CPU, but makes decisions about allocation

9. **Decision Making**: Responsible for choosing the next process to execute

10. **Execution Trigger**: Invoked when scheduling decisions need to be made (process termination, I/O block, quantum expiration, new process arrival)

The scheduler makes decisions about which process should run next, while the dispatcher implements these decisions by performing the actual context switch and transferring control to the selected process.