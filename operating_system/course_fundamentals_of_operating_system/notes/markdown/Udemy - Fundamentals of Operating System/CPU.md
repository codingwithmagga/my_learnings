- Basic components
    - Mention the basic components of a CPU >>>
        - ALU (Arithmetic Logic Unit)
        - CU (Control Unit)
        - Registers
        - MMU (Memory Management Unit)
        - Caches
        - ![](https://remnote-user-data.s3.amazonaws.com/9gDRYvXjcdk_sVuLQxPBIeI1tfjZNKU9uW3_fdm8AiZCi8qeSuu4miFddNJ1aDwCV5CaPtbcRxfVeRFERAnzsvncICZKLICLGLpE0mh_EGZj5IwI-jN4Us9_zG-MYH1t.png)
    - 
    -  What is the ALU?→Short for arithmetic logical unit and part of the CPU. The basic unit that actually does the computation in the CPU. These are addition, subtraction, multiplication and division, which are basically done using logic like AND, OR and XOR.
    - 
    - What is the CU?→Short for control unit and part of the CPU. Controls/Manages the execution, fetching and decoding of instructions in the CPU. The execution of an instruction does not always include the ALU, for example just a memory access or fetching data from a register.
    - 
    - What are the main characteristics and types of registers? >>>
        - Registers provide very fast data access (1-2 ns).
        - They are small memory units (32 or 64 bits).
        - They are expensive to build.
        - Examples include program counters, instruction registers, stack pointers, and base pointers.
    - 
    - What are the main functions of the MMU?
        - MMU is short for Memory Management Unit and is part of the CPU
        - Reads from memory and uses caches.
        - Translates virtual to physical addresses.
        - Contains the TLB, which caches the translation table.
        - Requires flushing during context switches.
        - Manages memory protection and access control
        - Handles memory paging (fixed-size blocks) and segmentation (variable-size blocks)
        - Swapping: Moves data between RAM and disk storage to free up memory for active processes, essential in systems with limited physical memory.
    - 
    - CPU Caches
        - What is cached to allow faster access?→Data and instructions.
        - Describe different cache levels
            - L1 cache is the fastest, smallest cache closest to the CPU, followed by L2 and then L3, each progressively larger and slower. 
            - L1 local to Core, separated in a data and instruction cache.
                - ○ CU can fetch data and instructions at the same time
                - ○ 1 ns
                - ○ ca. 128 KB
            - L2 local to Core in newer Cores, shared in older ones
                - ○ 5 ns
                - ○ ca. 256 KB - 2 MB
            - L3 shared btw all cores, missing in older cores
                - ○ 15 ns
                - ○ ca. 64 MB
            - Main Memory
                - ○ 50-100 ns
                - 
        - Why should cache invalidation be avoided?→Cache invalidation can cause performance bottlenecks due to the time-consuming process of updating all cached data. Accessing data from memory is time consuming.
        - What is the purpose of caches?→Caches store frequently accessed data closer to the CPU, reducing access time. Reduced Latency: Decreases the time it takes for applications to retrieve data, enhancing performance.
        - 
    - 
    - What is the purpose of a BUS for the CPU?→A bus is an electronic communication system that transfers data between the CPU and other components. 
    - 
    - DSM
        - ![](https://remnote-user-data.s3.amazonaws.com/cLyo3CG3HEE8nQG2E9yQ2cpdtZskKAxE_cRon76GLFfv3w93-ymBnwZEVKicaEcwmj5vWS8ot0MtW4suVPAQQRBcxzU3BKBF3PgKSizXXWZWefax5-lrdQUiyRI4CJT4.png?loading=false?loading=false?loading=false)
        - What does DSM stand for and what is the primary function of DSM? >>>
            - Distributed Shared Memory (DSM) 
            - Allows multiple processes on different machines to access a common memory space, facilitating inter-process communication. 
            - The memory is presented as a single logical space, abstracted from the physical memory locations.  
            - This allows multiple process to access a unified memory model, which simplifies programming and resource management.
        - What is a NUMA in this context and what does it stand for?→NUMA stands for Non-Uniform Memory Access, a memory architecture that allows a system to access multiple memory nodes with varying access times, optimizing performance in multi-processor environments.
        - 
    - CPU architecture
        - RISC
            - What does RISC stand for and what are the main characteristics? >>>
                - Reduced Instruction Set Computer
                - Simple instructions, single task, single cycle
                - Low power, predictable
                - Example: ARM
        - CISC
            - What does CISC stand for and what are the main characteristics? >>>
                - Complex Instruction Set Computer
                - One instruction, multiple tasks, multiple cycles
                - More power, unpredictable due to multiple tasks in one instruction
                - Example: An addition that loads two variables from memory, adds them, and writes the result back
                - Example: x86 (Intel/AMD)
            - 
    - What is the clock speed of a CPU?→Expresses how many cycles per second a CPU can do, for example 3 GHz are 3 billion clock cycles per second. In RISC this could mean 3 billion instructions per second, in CISC these are less. Additionally, there is cost (cylces needed) for fetching and decoding instructions (pipelining helps here).
    - 
    - 
- Instruction Life Cycle
    - CPU
        - Describe shortly the life cycle of an instruction >>>
            - Fetch from memory (MMU)
            - Decode (CU)
            - Execute (ALU)
            - Memory read (optional)
            - Write back to register/memory
    - 
- Improving CPU Performance
    - What is the purpose of separating a CPU into multiple units? >>>
        - To enable pipelining, allowing simultaneous execution of multiple tasks. 
        - For example, the next instruction can be fetched, while the previous one is decoded. 
        - Without pipelining, the CPU or at least parts of the CPUs are (more) idle.
    - 
    - Explain Hyper Threading and which problem is solves >>>
        - Hyper Threading exposes a single core as multiple logical cores with dedicated registers, sharing  everything else (CU, ALU and L cache). 
        - It improves CPU utilization by allowing multiple threads to run simultaneously, reducing idle time.
        - Overhead of context switch is reduced/removed, since the registers (which are normally replaced) are dedicated and the memory stays more or less the same.
        - This was achieved by adding more registers to a CPU
        - Hyper Threading does not work well, when the processes work on different data and the cache is invalidated anyway during a context switch
    - 
    - Explain SIMD and how it improves the CPU performance >>>
        - SIMD stands for Single Instruction Multiple Data
        - With a single instruction, multiple values are added (or subtracted or...)
            - Traditional: Add a1,b1; Add a2,b2; Add a3,b3; Add a4,b4
            - SIMD: Add [a1,a2,a3,a4], [b1,b2,b3,b4]
        - This is like a vector operation with a fixed size, e.g. 32 bits
        - It allows parallel processing of data, enhancing throughput and efficiency.
        - E.g. ARM Neon architecture extension
    - 
    - Speculative execution
        - What is speculative execution?→Speculative execution is a performance optimization where the CPU predicts the direction of branch instructions and executes subsequent instructions in advance.
        - How does speculative execution improve performance?→It keeps the CPU busy during idle times, such as while waiting for memory operations to complete, saving time when predictions are correct.
        - 
