- Multiple native OS
    - Many OS on top of the hardware
    - Switch at startup
    - One active at a time
    - High isolation
    - ![](https://remnote-user-data.s3.amazonaws.com/JRKK6mkE0Yf68Gotdan1toJ4QAN37S4I6uTZZuylcCIZVzX6yjeIp1EvnsbETYYOyEyoeVGGBZW6Q4uZankL8l_VkQ_ErzjluUlU66N_OeO-z_-gsLGnmByMfPkMBbP1.png)
- 
- Virtualization
    - Explain the concept >>>
        - Many OSs on top of one base OS
        - Hypervisor (software) controls upper OS
        - Hypervisor  proxies syscalls to lower kernel
        - Full isolation but lots of redundancy
        - ![](https://remnote-user-data.s3.amazonaws.com/lXmLWdbBV1g50m_oCHZWiI3fcDHTn7VM2Z2d9rXo8jX2jH5H31CXmrLyrPhFBKkiWvYDBP9LVcvPviEI8z0ksBltmzZsiGKbk-qe5Uq0rnJBgF2LLr1uY41y4fBAoYnQ.png)
    - E.g. VMWare, Oracle VirtualBox
- 
- Containerization
    - Explain the concept >>>
        - Containerization packages apps and dependencies into portable, lightweight containers that run consistently across environments.
        - Efficiency: Unlike VMs, containers share the host OS kernel, reducing overhead and improving performance.
        - Isolation: Linux namespaces (PID, network, mount, etc.) virtualize system resources, keeping containers separated.
        - CPU/Memory usage is limited by cgroups (control groups), kernel feature
        - ![](https://remnote-user-data.s3.amazonaws.com/vzHcpwLs0SQvvJdaNU8h7r5Ru-jf95T_E58n0roQhXQSlvVZ1blg3jlKaes5OdUIBIbcBSIuIbi2xfOlqj5K7W8UoNLZvrDMsK3dM5s7BQggok4BiGoVqshePXjQR7JO.png)
    - E.g. docker or Kubernetes
