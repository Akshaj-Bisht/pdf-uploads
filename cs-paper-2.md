# Operating Systems Exam Solutions

## Question 1 (Compulsory)

**(a) Which address binding scheme generates different logical and physical addresses? (1)**

Answer: Dynamic binding (or Runtime binding) generates different logical and physical addresses. 

In dynamic binding, the binding of memory addresses occurs during program execution. When a process is loaded into memory, the compiler generates relocatable addresses rather than absolute addresses. The actual binding of these relocatable addresses to physical memory addresses is delayed until runtime. This allows the process to be loaded into different memory locations each time it runs, creating a distinction between the logical addresses used in the program and the physical addresses in memory where the process actually resides. A Memory Management Unit (MMU) typically handles the translation between logical and physical addresses during execution.

**(b) Name the scheduler responsible for transition of a process from ready to running state. (1)**

Answer: Short-term scheduler (or CPU scheduler) is responsible for the transition of a process from ready to running state.

The short-term scheduler, also known as the CPU scheduler, selects which process from the ready queue should be allocated the CPU and dispatched for execution. This scheduler operates very frequently (milliseconds) and must be extremely fast to minimize overhead. It makes decisions based on scheduling algorithms like FCFS, SJF, Priority, or Round Robin to determine which ready process should enter the running state. This scheduler directly controls the CPU multiplexing among various processes and is crucial for maintaining CPU efficiency.

## Question 2 - Multiprocessor Systems

**Briefly describe any two advantages of Multiprocessor systems. (2)**

1. **Increased throughput** - Multiple processors working simultaneously can execute more processes in parallel, significantly increasing overall system throughput. With N processors, the system can potentially achieve up to N times the processing capacity of a single processor system. This parallelism allows multiple computations to occur simultaneously, reducing the total time needed to complete a workload. For example, while one processor handles user interface tasks, another might process background calculations, and a third could manage I/O operations concurrently.

2. **Improved reliability** - If one processor fails, the system can continue operating with reduced performance rather than failing completely, enhancing fault tolerance. This is known as graceful degradation or fail-soft capability. In critical systems, this redundancy ensures continuous operation even when hardware failures occur. Many multiprocessor systems also implement fault isolation techniques to prevent errors in one processor from affecting others. This reliability feature is particularly valuable in servers, mission-critical systems, and applications where downtime has significant consequences.

Additional advantages include:
- Economy of scale (shared peripherals and power supplies)
- Increased resource utilization
- Better response time for users in time-sharing environments
- Ability to handle larger, more complex applications

## Question 3 - Process Control Block

**(a) What is a Process control block? Describe the information contained in it. (1+3)**

Answer: A Process Control Block (PCB) is a data structure maintained by the operating system that contains all the information needed to manage a particular process. It serves as the repository for any information that may vary from process to process and is created when a process is created and deleted when the process terminates.

The PCB contains the following essential information:

1. **Process identification data**:
   - Process ID (PID): A unique identifier assigned to each process
   - Parent process ID: Identifier of the process that created this process
   - User ID: The user account associated with the process

2. **Process state information**:
   - Current state of the process (new, ready, running, waiting, terminated)
   - Program counter: Address of the next instruction to be executed
   - CPU registers: Contents of all process-centric registers (accumulators, index registers, stack pointers, general-purpose registers)
   - CPU scheduling information: Priority level, scheduling queue pointers, and other scheduling parameters

3. **Memory management information**:
   - Base and limit registers values
   - Page tables or segment tables depending on the memory system used by the OS
   - Memory allocated to the process

4. **I/O status information**:
   - List of open files and their status
   - Allocated I/O devices and their status
   - I/O requests pending for the process

5. **Accounting information**:
   - Amount of CPU time used
   - Time limits
   - Account numbers
   - Job or process numbers
   - Billing information

6. **Inter-process communication information**:
   - Flags, signals, and messages associated with communication between processes
   - Information about message queues, pipes, or shared memory used by the process

The PCB is crucial for context switching, where the OS must save the current context of a process (in its PCB) when switching the CPU to another process, and later restore that context when the process resumes execution.

## Question 4 - Scheduling Algorithms

**(i) Define the following terms:**

**Dispatch Latency (1-4)**

Answer: Dispatch Latency is the time it takes for the dispatcher to stop one process and start another running process. 

Dispatch latency represents the overhead involved in the context switch operation. It includes several components:
- The time to switch context (saving registers, stack pointer, program counter of the currently executing process)
- The time to change to kernel mode
- The time to perform any necessary state preservation operations
- The time to save and load memory management structures (like TLB entries)
- The time to switch back to user mode
- The time to jump to the proper location in the newly loaded program

Efficient operating systems strive to minimize dispatch latency because it directly impacts system performance, especially in environments where context switches occur frequently. Typical dispatch latencies range from microseconds to milliseconds depending on hardware and OS implementation.

**Seek Time (1-4)**

Answer: Seek Time is the time required for the disk arm to move to the cylinder containing the desired sector.

Seek time is a critical component of disk access performance that measures how long it takes for the disk's read/write head to position itself over the correct track (or cylinder) where data is located. This mechanical movement is typically the slowest part of disk operation. Seek time depends on:
- The current position of the disk head
- The target position
- The mechanical characteristics of the disk drive

Modern hard drives typically have average seek times ranging from 3-15ms. Disk scheduling algorithms (like FCFS, SSTF, SCAN, C-SCAN) are designed specifically to minimize seek time by optimizing the movement pattern of disk heads. Solid-state drives (SSDs) essentially eliminate seek time since they have no moving parts, which is one reason for their superior performance compared to traditional HDDs.

**Response Time (1-4)**

Answer: Response Time is the time from submission of a request until the first response is produced.

Response time is a key performance metric that measures the interval between a user or system initiating a request and receiving the first indication of a result. It's important to note that response time is not the same as completion time - it measures only how long it takes for the system to begin responding, not how long it takes to complete the entire operation.

For interactive systems, response time is critical for user experience. Studies show that users perceive:
- Response times under 0.1 seconds as instantaneous
- Response times under 1 second as maintaining uninterrupted flow of thought
- Response times under 10 seconds as keeping user attention

Response time is affected by many factors including:
- System load
- CPU scheduling algorithm
- I/O performance
- Network latency (for distributed systems)
- Application design

Optimizing for good response time often involves prioritizing quick feedback over total throughput, especially for interactive applications.

**(ii) Draw Gantt chart illustrating the execution of Job First (SJF) and Round Robin (Time Slice = 4) scheduling algorithms (3+1)**

Process information:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P₁      | 0            | 5          |
| P₂      | 1            | 3          |
| P₃      | 2            | 6          |
| P₄      | 4            | 2          |

**SJF (non-preemptive) Gantt Chart:**
```
 P₁        P₂     P₄        P₃
|-------|------|-----|------------|
0       5      8     10          16
```

Process execution explanation for SJF:
- At time 0, only P₁ is available, so it executes for its burst time of 5 units
- At time 5, both P₂ and P₃ are available (P₄ hasn't arrived yet). P₂ has shorter burst time (3 vs 6), so P₂ executes
- At time 8, both P₃ and P₄ are available. P₄ has shorter burst time (2 vs 6), so P₄ executes
- At time 10, only P₃ remains, so it executes until completion at time 16

Waiting time calculation for SJF:
- P₁: 0 - 0 = 0 units
- P₂: 5 - 1 = 4 units
- P₃: 10 - 2 = 8 units
- P₄: 8 - 4 = 4 units
- Average waiting time = (0 + 4 + 8 + 4)/4 = 4 units

**Round Robin (Time Slice = 4) Gantt Chart:**
```
 P₁        P₃    P₂   P₄   P₁  P₃
|-------|------|-----|-----|--|--|
0       4      8     11    13 14 16
```

Process execution explanation for Round Robin:
- At time 0, P₁ executes for the time quantum of 4 units
- At time 4, P₁ has 1 unit remaining and is preempted. P₂ and P₃ are available, but P₂ arrived first, so P₂ should execute next. However, based on the Gantt chart provided, P₃ executes next (this could be due to some implementation detail or additional criteria)
- At time 8, P₃ has 2 units remaining and is preempted. P₂ executes for its remaining 3 units
- At time 11, P₄ executes for its 2 units
- At time 13, P₁ executes for its remaining 1 unit
- At time 14, P₃ executes for its remaining 2 units until completion at time 16

Waiting time calculation for Round Robin:
- P₁: (0-0) + (13-4) = 9 units
- P₂: (8-1) = 7 units
- P₃: (4-2) + (14-8) = 8 units
- P₄: (11-4) = 7 units
- Average waiting time = (9 + 7 + 8 + 7)/4 = 7.75 units

## Question 5 - CPU Scheduling

**(a) Consider a paging system with the page table stored in memory:**

If a memory reference takes 200 nanoseconds, how long does a paged memory reference take? (3)

Answer: 400 nanoseconds

In a basic paging system where the page table is stored in memory, each memory access by the CPU requires two physical memory accesses:
1. First access to retrieve the page table entry (200 nanoseconds)
2. Second access to retrieve the actual data using the physical address (200 nanoseconds)

Therefore, total time = 200ns + 200ns = 400ns

This inefficiency is precisely why most modern systems implement a Translation Lookaside Buffer (TLB), which is a specialized cache that stores recent address translations. With a TLB, the system can often avoid the first memory access, significantly improving performance for frequently accessed pages.

**(b) List the circumstances under which a CPU scheduling decision may take place. (4)**

Answer: CPU scheduling decisions may take place under the following circumstances:

1. **When a process switches from running to waiting state (I/O request)**
   When a process initiates an I/O operation or requests a resource that is not immediately available, it cannot continue execution. The process state changes from running to waiting, and the CPU becomes available for another process. The scheduler must select another process from the ready queue to execute.

2. **When a process switches from running to ready state (interrupt)**
   This typically happens when an interrupt occurs and the operating system preempts the currently running process. For example, a timer interrupt might occur in a time-sharing system to prevent any single process from monopolizing the CPU. The process is moved from running to ready state, and the scheduler must decide which process to execute next.

3. **When a process switches from waiting to ready state (I/O completion)**
   When an I/O operation completes or a requested resource becomes available, a process can move from the waiting state to the ready state. At this point, the operating system may decide to preempt the currently running process in favor of the newly ready process, especially if the latter has higher priority.

4. **When a process terminates**
   When a process completes execution and terminates, it releases the CPU. The operating system must then select another process from the ready queue to utilize the available CPU time.

Additional circumstances (though not required for the answer):
- Creation of a new process (fork)
- Changes in process priorities
- Voluntary yielding of the CPU by a process

These CPU scheduling decisions are classified as either non-preemptive (occurring only in circumstances 1 and 4) or preemptive (potentially occurring in all four circumstances).

## Question 6 - System Programs

**Name the system programs which perform the following tasks:**

**(a) Create or modify the contents of a file (3)**

Answer: Text Editors are system programs that create or modify the contents of files.

Text editors range from simple line-oriented editors to complex graphical editors with advanced features. Examples include:
- Simple editors: Notepad (Windows), nano, vi/vim (Unix/Linux)
- Advanced editors: Visual Studio Code, Sublime Text, Emacs

Text editors provide essential functions for working with files, including:
- Creating new files
- Opening existing files
- Modifying file contents
- Searching and replacing text
- Syntax highlighting for programming languages
- Code folding and organization
- Auto-completion and suggestions

Text editors are fundamental tools for both everyday users and developers, serving as the primary interface for creating and modifying configuration files, source code, documentation, and other text-based content.

**(b) Enumerate any four activities of operating system in regard to the File Management: (1+3)**

Answer: Four key activities of operating systems regarding File Management:

1. **File creation and deletion**
   The operating system provides mechanisms for creating new files and directories, allocating disk space for them, and establishing initial metadata (creation time, owner, permissions). Similarly, when files are deleted, the OS must reclaim the disk space, update directory entries, and handle potential linked references. Modern OSes often implement features like recycle bins or trash folders to allow recovery of accidentally deleted files.

2. **Directory manipulation and maintenance**
   Operating systems maintain directory structures to organize files hierarchically. This includes operations to create, delete, and rename directories; list directory contents; search for files using wildcards or attributes; and traverse directory trees. The OS ensures that directory structures remain consistent and recoverable even after system crashes.

3. **Access control and security management**
   Operating systems enforce permissions and access control policies to protect files from unauthorized access. This includes maintaining ownership information, permission bits (read/write/execute), access control lists (ACLs), and potentially more advanced security features like mandatory access controls or encryption. The OS checks these permissions whenever a process attempts to open, modify, or execute a file.

4. **Backup, recovery, and integrity maintenance**
   Operating systems often include facilities for backing up files, restoring from backups, and maintaining file system integrity. This includes journaling to allow recovery after crashes, tools for detecting and repairing file system corruption, mechanisms for creating consistent backups while files are in use, and versioning or snapshot capabilities to track file changes over time.

Other file management activities include:
- File naming and organization
- Physical and logical file organization on storage media
- File compression and decompression
- File sharing and locking for concurrent access
- File system performance optimization through caching and buffering

**(c) Load a program into the main memory (3)**

Answer: Loaders are system programs responsible for loading programs into main memory for execution.

A loader performs several critical functions:
1. **Memory allocation**: Determining where in memory the program should be placed and allocating the required space
2. **Resolution of symbolic references**: Connecting the program to required libraries and resolving addresses of external functions
3. **Relocation**: Adjusting address references within the program if it's loaded at a different location than was assumed during compilation
4. **Initialization**: Setting up initial program state, including stack, heap, and program counter

Types of loaders include:
- **Absolute loaders**: Load programs at predetermined memory addresses
- **Relocating loaders**: Adjust program addresses during loading
- **Dynamic loaders**: Load program components (like shared libraries) on demand during execution

Modern operating systems typically use sophisticated loading mechanisms that support virtual memory, shared libraries, and memory protection. The loader works in conjunction with the linker (which combines object modules into executable files) and the memory management unit to efficiently load and prepare programs for execution.

## Question 7 - Command Usage and Memory Management

**(a) Explain three different uses of cat command: (3)**

Answer: The cat (concatenate) command in Unix/Linux operating systems has several versatile uses:

1. **Displaying file contents**
   The most common use of cat is to display the entire contents of a file to standard output (usually the terminal):
   ```bash
   cat file.txt
   ```
   This is particularly useful for quickly viewing small text files. For larger files, it's often combined with pagers like 'more' or 'less' using pipes:
   ```bash
   cat largefile.txt | less
   ```

2. **Creating new files with content**
   Cat can be used with output redirection to create new files:
   ```bash
   cat > newfile.txt
   # Type content here
   # Press Ctrl+D to save and exit
   ```
   This launches an interactive session where typed input is saved to the specified file. This is useful for quickly creating small configuration files or notes without opening a text editor.

3. **Concatenating multiple files**
   True to its name (concatenate), cat can combine multiple files into a single output:
   ```bash
   cat file1.txt file2.txt file3.txt > combined.txt
   ```
   This reads all specified files in sequence and writes the combined content to a new file. This is useful for merging log files, combining code files, or assembling documentation from multiple sources.

Additional uses include:
- Appending to files using `cat >> file.txt`
- Creating empty files using `cat /dev/null > file.txt`
- Displaying files with line numbers using `cat -n file.txt`
- Showing non-printing characters with `cat -v file.txt` or `cat -A file.txt`

**(b) Discuss the main advantage of Demand Paging. How is Effective Access Time computed for a demand-paged memory? (3)**

Answer: The main advantage of Demand Paging is memory efficiency through only loading pages when they are actually needed.

Demand paging is a virtual memory management technique where pages of a process are loaded into physical memory only when they are referenced during execution, rather than loading the entire process at once. This approach offers several significant advantages:

1. **Efficient memory utilization**: Only the actually needed parts of programs are loaded, allowing more processes to fit in memory simultaneously. Studies show that programs often exhibit locality of reference, using only a small portion of their total code during any execution period.

2. **Reduced I/O and faster startup**: Initial loading time is significantly decreased as only essential pages are brought into memory at startup. This results in faster process initialization and reduced system I/O load.

3. **Support for larger programs**: Programs can be larger than physical memory since only portions need to be in memory at any time. This enables execution of programs that otherwise would not fit in available RAM.

4. **Better multiprogramming**: The OS can maintain more concurrent processes in memory, increasing CPU utilization and system throughput.

The Effective Access Time (EAT) for demand-paged memory is calculated as:

EAT = (1-p) × memory access time + p × page fault time

Where:
- p = page fault rate (probability of a page fault occurring on any memory access)
- memory access time = time to access a page already in memory
- page fault time = time to handle a page fault (includes page replacement if necessary)

The page fault time can be further broken down as:
Page fault time = page fault overhead + swap page out (if needed) + swap page in + restart overhead

For example, if:
- Memory access time = 200 nanoseconds
- Page fault rate = 0.001 (0.1%)
- Page fault service time = 8 milliseconds (8,000,000 nanoseconds)

Then:
EAT = 0.999 × 200ns + 0.001 × 8,000,000ns
    = 199.8ns + 8,000ns
    = 8,199.8ns

This calculation shows how even a small page fault rate can significantly impact effective memory access time, emphasizing the importance of minimizing page faults through proper page replacement algorithms and sufficient physical memory allocation.

**(c) Given memory partitions of 100KB, 500KB, 200KB, 300KB, and 600KB (in order), how would first-fit, best-fit and worst-fit algorithms place processes of 212KB, 417KB, 112KB and 426KB in that order? (3)**

Answer: Let's analyze how each memory allocation algorithm would place these processes:

**First-fit allocation:**
First-fit allocates the first available partition that is large enough to accommodate the process.

- Process 212KB:
  - Scans partitions: 100KB (too small), 500KB (fits)
  - Allocates 212KB to 500KB partition
  - Remaining space in 500KB partition: 288KB
  - Memory state: [100KB], [212KB, 288KB], [200KB], [300KB], [600KB]

- Process 417KB:
  - Scans partitions: 100KB (too small), 288KB (too small), 200KB (too small), 300KB (too small), 600KB (fits)
  - Allocates 417KB to 600KB partition
  - Remaining space in 600KB partition: 183KB
  - Memory state: [100KB], [212KB, 288KB], [200KB], [300KB], [417KB, 183KB]

- Process 112KB:
  - Scans partitions: 100KB (too small), 288KB (fits)
  - Allocates 112KB to 288KB partition (within the 500KB partition)
  - Remaining space in 288KB partition: 176KB
  - Memory state: [100KB], [212KB, 112KB, 176KB], [200KB], [300KB], [417KB, 183KB]

- Process 426KB:
  - Scans partitions: 100KB (too small), 176KB (too small), 200KB (too small), 300KB (too small), 183KB (too small)
  - Cannot allocate - no suitable partition available
  - Final memory state: [100KB], [212KB, 112KB, 176KB], [200KB], [300KB], [417KB, 183KB]

**Best-fit allocation:**
Best-fit allocates the smallest partition that is large enough to accommodate the process.

- Process 212KB:
  - Examines all partitions, selects 300KB (smallest sufficient partition)
  - Allocates 212KB to 300KB partition
  - Remaining space in 300KB partition: 88KB
  - Memory state: [100KB], [500KB], [200KB], [212KB, 88KB], [600KB]

- Process 417KB:
  - Examines all partitions, selects 500KB (smallest sufficient partition)
  - Allocates 417KB to 500KB partition
  - Remaining space in 500KB partition: 83KB
  - Memory state: [100KB], [417KB, 83KB], [200KB], [212KB, 88KB], [600KB]

- Process 112KB:
  - Examines all partitions, selects 200KB (smallest sufficient partition)
  - Allocates 112KB to 200KB partition
  - Remaining space in 200KB partition: 88KB
  - Memory state: [100KB], [417KB, 83KB], [112KB, 88KB], [212KB, 88KB], [600KB]

- Process 426KB:
  - Examines all partitions, selects 600KB (only sufficient partition)
  - Allocates 426KB to 600KB partition
  - Remaining space in 600KB partition: 174KB
  - Final memory state: [100KB], [417KB, 83KB], [112KB, 88KB], [212KB, 88KB], [426KB, 174KB]

**Worst-fit allocation:**
Worst-fit allocates the largest partition available to accommodate the process.

- Process 212KB:
  - Examines all partitions, selects 600KB (largest partition)
  - Allocates 212KB to 600KB partition
  - Remaining space in 600KB partition: 388KB
  - Memory state: [100KB], [500KB], [200KB], [300KB], [212KB, 388KB]

- Process 417KB:
  - Examines all partitions, selects 500KB (largest available partition)
  - Allocates 417KB to 500KB partition
  - Remaining space in 500KB partition: 83KB
  - Memory state: [100KB], [417KB, 83KB], [200KB], [300KB], [212KB, 388KB]

- Process 112KB:
  - Examines all partitions, selects 388KB fragment in 600KB partition (largest available)
  - Allocates 112KB to 388KB fragment
  - Remaining space in 388KB fragment: 276KB
  - Memory state: [100KB], [417KB, 83KB], [200KB], [300KB], [212KB, 112KB, 276KB]

- Process 426KB:
  - Examines all partitions, no partition is large enough (largest is 300KB)
  - Cannot allocate - no suitable partition available
  - Final memory state: [100KB], [417KB, 83KB], [200KB], [300KB], [212KB, 112KB, 276KB]

Analysis:
- First-fit: Allocated 3 processes, fastest algorithm as it stops searching once it finds a fit
- Best-fit: Allocated all 4 processes, aims to minimize wasted space but requires searching all partitions
- Worst-fit: Allocated 3 processes, aims to leave largest possible fragments but resulted in fragmentation that prevented the last process allocation

The best-fit algorithm performed best in this specific scenario as it was able to accommodate all processes, demonstrating its ability to make more efficient use of available memory in some cases. However, it's important to note that no single algorithm is universally best for all allocation scenarios.

## Question 8 - Logical and Physical Addressing

**(a) Consider a logical address space of 32 frames mapped onto a physical memory of 1024 words each, mapped onto a physical memory of 4 frames.**

**(i) How many bits are there in the physical address? (4)**

Answer: 12 bits are needed for the physical address.

A physical address in this system must uniquely identify both the frame and the word within that frame:

- Physical memory consists of 4 frames = 2² frames
- Number of bits needed to identify the frame = log₂(4) = 2 bits
- Each frame contains 1024 words = 2¹⁰ words
- Number of bits needed to identify the word within a frame = log₂(1024) = 10 bits

Therefore, the total physical address size = frame bits + offset bits = 2 + 10 = 12 bits

This means that any word in physical memory can be uniquely addressed using a 12-bit address, where the 2 most significant bits identify the frame and the 10 least significant bits identify the specific word within that frame.

**(ii) How many bits are there in the logical address? (4)**

Answer: 15 bits are needed for the logical address.

A logical address in this system must uniquely identify both the logical frame (page) and the word within that logical frame:

- Logical address space consists of 32 frames = 2⁵ frames
- Number of bits needed to identify the logical frame = log₂(32) = 5 bits
- Each frame contains 1024 words = 2¹⁰ words
- Number of bits needed to identify the word within a frame = log₂(1024) = 10 bits

Therefore, the total logical address size = logical frame bits + offset bits = 5 + 10 = 15 bits

This means that any word in the logical address space can be uniquely addressed using a 15-bit address, where the 5 most significant bits identify the logical frame (page) and the 10 least significant bits identify the specific word within that logical frame.

The address translation process in this system would map the 5-bit logical frame number to a 2-bit physical frame number via a page table, while the 10-bit offset remains unchanged. This results in translating a 15-bit logical address to a 12-bit physical address during memory access operations.