

Operating System Concepts: Process Management Essentials
(Saved responses are view only)
# Important Questions: Operating System Concepts (Up to Process Management)

## Unit 1: Introduction

*   What is the **purpose of an operating system**? [1]
*   How does the distinction between **kernel mode** and **user mode** function as a rudimentary form of protection? [2] What are examples of **privileged instructions** that should execute in kernel mode?
*   What are the **major resources managed by an operating system**? How does the OS manage these resources to ensure efficient and fair utilization? [1]

## Unit 2: Operating System Structures

*   What are **operating system services**? [1] How do these services provide convenience to users?
*   What are **system calls**? What is their **purpose**? How do user programs interact with the operating system kernel through system calls? What are different **types of system calls**? What system calls are necessary for a command interpreter to start a new process? [3]
*   What is **process control** as a responsibility of the operating system? [3]
*   **OS Structures**:
    *   What is the **layered approach** to system design? What are its **advantages and disadvantages**?
    *   What is the **microkernel approach**? What is its **main advantage**? How do user programs and system services interact in a microkernel architecture? What are the **disadvantages** of this approach?
*   What is **inter-process communication (IPC)**? What are the different **models of IPC**? What are the strengths and weaknesses of these approaches? How do **pipes** facilitate communication between processes? [4-6]
*   What are **system programs**? What is their **purpose**? How do they relate to system calls?
*   What is the role of a **command interpreter** (or shell)? Why is it usually kept **separate from the kernel**? Could a user develop a new command interpreter using the system call interface?

## Unit 3: Process Management (Up to Scheduling Algorithms)

*   What is a **process**? [3] How does it differ from a program? What does a process typically include in memory?
*   What are the different **states of a process**? Draw a diagram illustrating the **process state transitions**. [3, 7]
*   What is a **Process Control Block (PCB)**? What kind of **information is stored in a PCB**? [8]
*   What is **process scheduling**? What is the role of the **process scheduler**? What are the different **types of schedulers**: **short-term (CPU scheduler)**, **medium-term**, and **long-term**? What are their responsibilities? [9]
*   What is **context switching**? What are the steps involved in a **kernel context switch between processes**? What happens when a context switch occurs if the new context is already loaded into a processor register set versus when it's in memory? [3]
*   What are **operations on processes**? This includes creation (e.g., using `create process()` or `submit job()`), termination (`terminate process()`), and setting process attributes (`get process attributes()` and `set process attributes()`). When a parent process creates a child process, what states are shared between them? [3]
*   What are **threads**? How do they differ from processes? What are the **benefits of using threads**? What components of a program state are **shared across threads** in a multithreaded process? [10-14]
*   What is **multicore programming**? What are some of the challenges programmers face in developing multithreaded applications for multicore systems? How does the operating system schedule threads on multicore systems?
*   What are **multithreading models**? The sources mention mapping user-level threads to kernel threads (e.g., one-to-one mapping). [11, 14]
*   What are the basic **CPU scheduling algorithms**: **First Come First Served (FCFS)**, **Shortest-Job-First (SJF)**, **Priority scheduling**, and **Round Robin (RR)**? For each algorithm, how does it work? What are its advantages and disadvantages in terms of metrics like turnaround time, waiting time, and throughput? How to calculate the turnaround time and waiting time for a given set of processes under these algorithms? What is the effect of the **time quantum** in the RR algorithm? How does **preemptive** scheduling differ from **nonpreemptive** scheduling?
*   What are **scheduling queues**? What are the job queue and the ready queue? What is a **multilevel queue scheduling algorithm**? How does it differ from a **multilevel feedback queue scheduler**? What are the parameters that define a multilevel feedback queue scheduler?
