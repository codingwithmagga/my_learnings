- Asynchronous Programming
    - Explain→Asynchronous programming allows multiple tasks to run concurrently without blocking each other, improving efficiency. Using asynchronous programming can reduce the need to lock, but may not avoid it completely.
    - Explain Non-blocking synchronization→In contrast to blocking synchronization using mutex and/or atomic variables, Non-blocking synchronization is a technique that allows multiple threads to access shared data concurrently, without blocking program execution. It's used to implement non-blocking data structures in a parallel system, for example a concurrent message queue
    - Missing features in std C++ (as of C++23) >>>
        - Continuations - "do this task, then this task"
        - Only supports waiting on one future at a time
        - Waiting on multiple threads has to be done sequentially
        - Concurrent queue
- 
- `std::packaged_task<T>`
    - Describe:>Encapsulates a task. Expects a callable object for the task's code in the constructor, and contains a `std::promise` for the result of the task. A functor class, where the `operator()` invokes the callable object. The task starts after that call, not when the object is created. It starts in the same thread when called directly and in another one when it is used as an argument for a new thread.
    - How is `T` specified?→`T` is specified as the function type which is called in the constructor of std::packaged_task. Example `int(int, int)`. A function which returns an `int` and accepts two `int`'s as parameters. 
    - Advantages and disadvantages:>Best choice if tasks should be represented as objects. Lower-level abstraction than `std::async<T>`, we can control when a task is executed and can control which thread it executes. Disadvantage: Lower level, so more complex and possible error-prone code.
- 
- `std::future <...> std::async<F, Args...>` 
    - Describe:>`std::async` launches a function asynchronously, returning a `std::future` that holds the result. Higher-level abstraction than `std::thread`. Different launch flags, which decide if to start in another thread and/or directly.
    - Advantages and disadvantages→Simplest way to execute a task. Easy to obtain the return value or exception and the choice of running synchronously or not. The library manages the threads for the programmer and inter-thread communication, no need to use shared data. Disadvantages: Tasks cannot be detached. Async tasks are "implicitly joined", the returned future's destructor will be blocked until the task completes.
- 
