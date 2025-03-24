

Operating System Concepts: Process Management Essentials
(Saved responses are view only)
# Important Questions: Operating System Concepts (Up to Process Management)



## Unit 1: Introduction

### What is the purpose of an operating system?
An operating system (OS) acts as an intermediary between hardware and users. It manages resources such as CPU, memory, and I/O devices, ensuring efficient execution of processes.

### How does the distinction between kernel mode and user mode function as a rudimentary form of protection?  
The OS operates in two modes:  
- **Kernel mode:** Allows direct access to hardware and critical system functions.  
- **User mode:** Restricts access to prevent unauthorized system modifications.  

#### Examples of privileged instructions:
- Direct access to I/O devices  
- Modifying memory management settings  
- Changing CPU mode  

### What are the major resources managed by an operating system?  
The OS manages:  
- **CPU:** Schedules and executes processes.  
- **Memory:** Allocates and deallocates RAM.  
- **Storage:** Manages file systems and disk access.  
- **I/O Devices:** Handles input and output operations.  
- **Networking:** Facilitates communication between systems.  

---

## Unit 2: Operating System Structures

### What are operating system services?  
OS services provide functionalities such as process execution, file handling, I/O operations, and security to enhance user and system efficiency.

### What are system calls?  
System calls act as an interface between user applications and the OS, enabling process control, file operations, and communication.

#### Types of system calls:
- **Process control:** `fork()`, `exec()`, `exit()`
- **File manipulation:** `open()`, `read()`, `write()`
- **Device management:** `ioctl()`, `read()`, `write()`
- **Information maintenance:** `getpid()`, `alarm()`
- **Communication:** `pipe()`, `send()`, `recv()`

### What is process control as a responsibility of the OS?  
The OS is responsible for creating, scheduling, and terminating processes, ensuring proper execution and resource management.

### OS Structures

#### What is the layered approach to system design?  
A layered OS is divided into hierarchical levels, where each layer depends on the one below.

**Advantages:**  
- Modularity  
- Simplified debugging  

**Disadvantages:**  
- Performance overhead  
- Increased complexity  

#### What is the microkernel approach?  
A microkernel provides minimal core services while moving others to user space.

**Advantages:**  
- Enhanced security and stability  
- Modular design  

**Disadvantages:**  
- Slower communication between kernel and user space  

### What is inter-process communication (IPC)?  
IPC allows processes to communicate and share data.

**Models of IPC:**  
- **Message passing:** Processes exchange messages via system calls.  
- **Shared memory:** Processes communicate via a common memory region.  

### What are system programs?  
System programs provide utilities for file management, process control, and communication using system calls.

### What is the role of a command interpreter (shell)?  
The shell interprets user commands and interacts with the OS. It remains separate from the kernel for flexibility.

---

## Unit 3: Process Management

### What is a process? How does it differ from a program?  
A **process** is an executing instance of a program. It consists of program code, execution state, and allocated resources.

### What are the different states of a process?  

| State        | Description |
|-------------|-------------|
| **New**     | Process is being created. |
| **Ready**   | Process is waiting for CPU allocation. |
| **Running** | Process is executing on the CPU. |
| **Waiting** | Process is waiting for an I/O operation to complete. |
| **Terminated** | Process has finished execution. |

### What is a Process Control Block (PCB)?  
A PCB stores information about a process, including:  
- Process ID  
- Program counter  
- CPU registers  
- Memory allocation  
- Scheduling information  

### What is process scheduling?  
Process scheduling determines which process executes next.

#### Types of Schedulers:  
- **Long-term scheduler:** Controls process admission into memory.  
- **Short-term scheduler (CPU scheduler):** Selects a process for execution.  
- **Medium-term scheduler:** Temporarily suspends processes (swapping).  

### What is context switching?  
Context switching saves the current process state and loads another.

**Steps involved:**  
1. Save current process state in PCB.  
2. Load the new process state.  
3. Update scheduling queues.  
4. Resume execution of the new process.  

### What are operations on processes?  
- **Process creation:** `fork()`, `exec()`  
- **Process termination:** `exit()`, `kill()`  
- **Process attributes modification:** `getpriority()`, `setpriority()`

### What are threads? How do they differ from processes?  
A **thread** is a lightweight unit of execution within a process.

| Feature | Process | Thread |
|---------|---------|--------|
| Memory | Separate memory space | Shared within a process |
| Communication | Requires IPC | Uses shared memory |
| Context switch | Expensive | Faster |
| Creation time | High | Low |

**Benefits of threads:**  
- Faster execution  
- Efficient resource sharing  
- Improved responsiveness  

### What is multicore programming?  
Multicore programming enables parallel execution across multiple CPU cores.

**Challenges:**  
- Synchronization issues  
- Load balancing  
- Thread scheduling  

### What are multithreading models?  
Defines how user threads map to kernel threads:  
- **One-to-One:** Each user thread has a corresponding kernel thread.  
- **Many-to-One:** Multiple user threads share a single kernel thread.  
- **Many-to-Many:** User threads dynamically map to kernel threads.  

### What are the basic CPU scheduling algorithms?

1. **First Come First Served (FCFS)**  
   - Processes execute in arrival order.  
   - Non-preemptive.  

2. **Shortest Job First (SJF)**  
   - Chooses the shortest execution time.  
   - Preemptive or non-preemptive.  

3. **Priority Scheduling**  
   - Executes highest-priority process first.  

4. **Round Robin (RR)**  
   - Time-sharing with a fixed time slice.  

### What are scheduling queues?  
- **Job queue:** Contains all system processes.  
- **Ready queue:** Holds processes ready for execution.  

**Multilevel queue scheduling:**  
- Divides ready queue into priority-based queues.  

**Multilevel feedback queue:**  
- Allows dynamic process movement between queues.  

---

This markdown file provides structured and concise answers for OS process management concepts.