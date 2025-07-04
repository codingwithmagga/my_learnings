- Introduction
    - Tumbling Window Strategy 
        - Describe→A tumbling window strategy processes data in fixed-size, non-overlapping time intervals.
 ![](https://remnote-user-data.s3.amazonaws.com/0V_eXZjlR5DNB7qBtK1g1vjWg0zAhPlhZCvF_zyL47xU_DYnBRUuqddrkvv9wRtVQkvkmY5eAWx0J1PoiQBi_dBs2SdAil5kVwpzCFpFeBH7ai_L85Ef7dp-ehXZvH-A.png)
        - Advantages? >>>
            - Simple 
            - Minimal memory/computation overhead
        - Disadvantages? >>>
            - Low granularity of results (depends on window size)
            - Not good for pattern/trend recognition
- Hopping Window Event-Stream
    - Describe→A hopping window processes events in overlapping fixed-size time windows that slide forward. Each time a window is closed, the events are processed, and the results are published.
![](https://remnote-user-data.s3.amazonaws.com/-fUFjTa2mUj1hGabVcgucINZb7D79N7OrguMadRcqxSHbL4PzJCJ-_4-zNpuIf8hnHSgqxLDvbAfIwEhJT8MYdklS2nd0t8-22o0VjHNdkzb16BJsYy_7C3_SIk4ReEc.png)
    - Possible Use cases >>>
        - Real-time analytics
        - Error Log analysis
        - Stock trading
    - Advantages? >>>
        - Frequent results
        - Respond to changes insights can be faster
    - Disadvantages? >>>
        - Additional memory usage
        - Additional CPU resources needed
        - More network resources needed
- Sliding Window Event-Stream
    - Describe→In the sliding window event-stream, a new window is created when a new event occurs. The window size is fixed and will be processed and published after the window closes.
![](https://remnote-user-data.s3.amazonaws.com/01tpxs5FrX8La5Sbg71i3TnvvaFGsAnt2zUIBKWIAXySBeYZTycrguXIdL3wLwC5SiufOfQTTq9oDG0waVxjtEvozCjI58AEUVSXyFAl-cwUoNtQI-GkMG3xR36FoJmg.png)
    - Possible Use cases? >>>
        - Fraud detection
        - API Rate Limiter
    - Advantage? >>>
        - Flexible intervals
    - Disadvantage? >>>
        - High memory and CPU consumption
- Session Window Event-Stream
    - Describe→A session window groups events based on a user session (variable time frame), processing events within that session together. Starts with the login and ends when the user leaves the website.
    - Use Case? >>>
        - User Behavior Analysis on a website
![](https://remnote-user-data.s3.amazonaws.com/8D3MixKR30rwJg6iVAOM1QzcbP19RLhlaybnqyCZumYEQujZk0L5m5r6Fs74_0t2t6SnqiX9zff3AmpTe1aQxTJiXwoxygBZeOEJBEFO1QW56YPfIPAGWkqIiX-IZRP5.png)
        - Internet of Things, like a robot cleaner
        - Navigation App, optimizing route for all drivers
    - Advantages >>>
        - Good for real-time analytics for users
        - Dynamic window size
        - No waste of computation, since each event belongs to one window
    - Disadvantages >>>
        - Defining the inactivity threshold/period difficult
        - Potential many windows, depending on users, sessions etc.
- Time in Stream Processing and Handling Late Arrival of Events
    - Types of Timestamps in Event-Stream Processing
        - Event time::Time when the event happened.
        - Application Time / Arrival Time::Time when the event is consumed by the application/consumer microservice
        - Processing Time::Time when the event read/parsed/processed by the consumer microservice.
    - 
    - When to use arrival time? >>>
        - We don't care about "when the event actually happened".
        - Need to act in real-time
        - We don't know/trust the event time
        - For example, for monitoring or altering purposes.
    - 
    - When to use event time? >>>
        - When accurate correlation or ordering of the events is required
        - For example, analyzing trends in the stock market
    - 
    - Name options for handling late arrival of events![](https://remnote-user-data.s3.amazonaws.com/m12-jWU6NaPkliVg3tMc9rDGqp7x3f61qPDKDoZs9H1IsXfxDpyNr4PusX6i1Nkg4ztv3-Xu_Rbt779z-YUfJdDR3fX-xO0Dc-Yh2B5OKWar5Wx6fO5H_Qq2du9i0JWb.png) >>>
        - Discard the event
        - End Window after a grace period, even later events are discarded
        - Watermarking, adapting grace period depending on the arrived event with the latest event time
- Stream processing Technologies
    - Apache Kafka Streams
        - Client library (Java and Scala) for building applications and microservices that process continuous streams of records coming through the Kafka message broker.
        - It supports:
            - Per record, real-time processing
            - Stateful and processing using Windows
                - Tumbling Window code
                - Hopping Window code
                - Session Window code
                - Siding Window code 
            - 
    - Apache Flink
        - Apache Flink is a framework and distributed processing engine for building scalable streaming ETL, analytics, and event-driven applications. It is specifically designed for stateful computations of bounded and unbounded streams of events.
        - Apache Flink can
            - Be used as a distributed system that requires effective allocation and management of computing resources using Hadoop YARN or Kubernetes.
            - Run as a standalone distributed cluster
            - Used as a client library for building microservices
        - For more information, see Apache Flink's architecture and Windowing with Apache Flink (Java and Python code examples).
        - 
    - Azure Stream Analytics
        - Azure Stream Analytics is a real-time analytics service that enables you to process and analyze streaming data from various sources. It's a fully managed, serverless service that uses a SQL-like query language to process data streams using windows.
            - Tumbling Window 
            - Hopping Window
            - Session Window 
            - Siding Window
