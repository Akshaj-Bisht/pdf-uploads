

Operating System Concepts: Process Management Essentials
(Saved responses are view only)
# Important Questions: Operating System Concepts (Up to Process Management)

Here are the questions from your file:

### Unit 1: Introduction
1. What is the **purpose of an operating system**?
2. How does the distinction between **kernel mode** and **user mode** function as a rudimentary form of protection? What are examples of **privileged instructions** that should execute in kernel mode only?
3. What are the **major resources managed by an operating system**? How does the OS manage these resources to ensure efficient and fair utilization?

### Unit 2: Operating System Structures
1. What are **operating system services**? How do these services provide convenience to users?
2. What are **system calls**? What is their **purpose**? How do user programs interact with the operating system kernel through system calls? What are different **types of system calls**?
3. What is **process control** as a responsibility of the operating system?
4. **OS Structures**:
   - What is the **layered approach** to system design? What are its **advantages and disadvantages**?
   - What is the **microkernel approach**? What is its **main advantage**? How do user programs and system services interact in a microkernel architecture? What are the **disadvantages** of this approach?
5. What is **inter-process communication (IPC)**? What are the different **models of IPC**? What are the strengths and weaknesses of these approaches? How do **pipes** facilitate communication between processes?
6. What are **system programs**? What is their **purpose**? How do they relate to system calls?
7. What is the role of a **command interpreter** (or shell)? Why is it usually kept **separate from the kernel**? Could a user develop a new command interpreter using the system call interface?

### Unit 3: Process Management (Up to Scheduling Algorithms)
1. What is a **process**? How does it differ from a program? What does a process typically include in memory?
2. What are the different **states of a process**? Draw a diagram illustrating the **process state transitions**.
3. What is a **Process Control Block (PCB)**? What kind of **information is stored in a PCB**?
4. What is **process scheduling**? What is the role of the **process scheduler**? What are the different **types of schedulers**: **short-term (CPU scheduler)**, **medium-term**, and **long-term**?
5. What is **context switching**? What are the steps involved in a **kernel context switch between processes**? What happens when a context switch occurs if the new context is already loaded into memory?
6. What are **operations on processes**? This includes creation (e.g., using `create process()` or `submit job()`), termination (`terminate process()`), and setting process attributes (`get process attributes()`).
7. What are **threads**? How do they differ from processes? What are the **benefits of using threads**? What components of a program state are **shared across threads** in a multithreaded process?
8. What is **multicore programming**? What are some of the challenges programmers face in developing multithreaded applications for multicore systems? How does the operating system schedule threads on multicore processors?
9. What are **multithreading models**? The sources mention mapping user-level threads to kernel threads (e.g., one-to-one mapping).
10. What are the basic **CPU scheduling algorithms**: **First Come First Served (FCFS)**, **Shortest-Job-First (SJF)**, **Priority scheduling**, and **Round Robin (RR)**? For each algorithm, how do they determine the next process to execute?
11. What are **scheduling queues**? What are the job queue and the ready queue? What is a **multilevel queue scheduling algorithm**? How does it differ from a **multilevel feedback queue scheduler**?