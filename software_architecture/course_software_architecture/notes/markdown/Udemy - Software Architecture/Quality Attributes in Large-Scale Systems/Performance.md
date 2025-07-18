- Response time (also called End to End Latency)
    - Definition→Time between a client sending a request and receiving a response
    - Broken in two parts, name them→Processing time + Waiting time
    - Define Processing Time→Time spent in our system actively processing the request and building/sending the response.
    - Define waiting time (latency)→Duration of time request/response spends inactively in our system, for example waiting in a queue for processing
    - What should be considered when measuring the response time? >>>
        - Don't forget the waiting time!
        - Calculate the x-th Percentile Distribution
            - ![](https://remnote-user-data.s3.amazonaws.com/ASX9sdX14bjk3n4BtwFnM9cS-5rUJ4s0nOcb1C-6O0nFVHIRJT0GHUzz6iACZsjcQjNgwoqI2M9r-yKn7TSZMuVfXwLZN1gtvQp2fX8op7Mmcs0psUCF2iClaPRQCiZs.png)
            - ![](https://remnote-user-data.s3.amazonaws.com/AyXvzbjQSv5lSkhbGPjf7rm3QLEc3cE32FakniI2ahwH03-4-741LH3VEmaFI7ot1x9RdivtxHHcssRjL351R_BkgTVl6_8BGBC55RrPxA2zhc1GsrsRuRiYtjTy8Ecz.png)
    - ![](https://remnote-user-data.s3.amazonaws.com/NNGSsQ_wIKcd-XoTzHU0hcPGN27NUEPA3uZ1-g1AHo0JB45hkg2-dHxZj5_QgPJNzLnwV-fR4TM8SKvipMJuDpIGzoSTvr6tdmiT9vMANt7S8X1SbENK8sQUC9jPikDv.png)
    - Tail Latency
        - Definition→The small percentage of response times from a system, that take the longest in comparison to the rest of values.
    - How should goals regarding the response time of a service be defined?→Define them using percentiles. For example: 30ms at 95th percentile of response time.
- 
- Throughput
    - Definition→Amount of work performed/data processed by our system per unit of time. Measured in tasks per second or bytes per second.
- 
- Performance degradation
    - Define→Performance degradation is a decrease in a system's speed, responsiveness, or efficiency.
    - Name potential overly utilized resources >>>
        - High CPU utilization
        - High memory consumption
        - Too many connections/IO 
        - Message queue is at capacity
    - ![](https://remnote-user-data.s3.amazonaws.com/2q3xJtR4pdC2D4k0MvIMZpfzx91ju77K8Wwml8iOfZzjyuhRZkYwoWyViIlgQndWvchwY_rADMKZHppnXrQyNVE7rvq2kITlkusoIO-YilFjKSFng1s1qmvrS1FjOPWw.png)
