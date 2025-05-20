#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/types.h>
#endif

int main() {
    // Allocate 10 MB of memory and initialize it to 0 before forking
    size_t tenMB = 10 * 1024 * 1024; // 10 MB
    char *buffer = (char *)malloc(tenMB);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    memset(buffer, 0, tenMB);

#ifdef _WIN32
    // Windows implementation using CreateProcess
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create a new process (this will run the same executable)
    if (!CreateProcess(NULL,   // No module name (use command line)
                       GetCommandLine(), // Command line
                       NULL,   // Process handle not inheritable
                       NULL,   // Thread handle not inheritable
                       FALSE,  // Set handle inheritance to FALSE
                       0,      // No creation flags
                       NULL,   // Use parent's environment block
                       NULL,   // Use parent's starting directory
                       &si,    // Pointer to STARTUPINFO structure
                       &pi))   // Pointer to PROCESS_INFORMATION structure
    {
        fprintf(stderr, "CreateProcess failed (%lu).\n", GetLastError());
        free(buffer);
        return 1;
    }

    // Parent process continues here
    int i = 0;
    while (1) {
        printf("Parent process: PID = %lu, buffer[0] = %d\n", GetCurrentProcessId(), buffer[0]);
        buffer[0]++; // Modify first byte
        Sleep(1000); // Sleep for 1 second (Windows uses milliseconds)
    }

    // Cleanup (never reached in this example)
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    free(buffer);
#else

    pid_t pid = fork(); // Fork a new process
    int i = 0;
    if (pid == -1) {
        // Error handling: if fork() returns -1, an error occurred
        perror("Failed to fork");
        free(buffer); // Clean up memory allocation
        return 1;
    } else if (pid > 0) {
        // Parent process
        while (1) { // Infinite loop
            printf("Parent process: PID = %d, buffer[0] = %d\n", getpid(), buffer[0]);
            buffer[0]++; // Modify first byte
            sleep(1); // Sleep for 1 second to avoid flooding the output
        }
        free(buffer); // Ideally, this should be reached if the loop ends
    } else {
        // Child process
        int Y = 20; // Child process's new variable
        while (1) { // Infinite loop
            printf("Child process: PID = %d, Y = %d, buffer[0] = %d\n", getpid(), Y, buffer[0]);
            buffer[(i++)*1000]++; // Modify first byte
            sleep(1); // Sleep for 1 second to avoid flooding the output
        }

        // Child process also needs to free memory if it ever exits the loop
    }
#endif

    return 0; // This line will never be reached in the current setup
}
