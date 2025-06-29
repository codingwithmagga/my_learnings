- Introduction
    - What are software architectural patterns?→These are general, repeatable solutions to commonly occurring system design problems. This involves, in general, multiple components that run as separate units.
    - 
    - Why use software architectural patterns? >>>
        - Save valuable time and resources
        - Avoid the risk to make our architecture resemble a Big Ball of Mud (anti-Pattern, no structure, tightly coupled system, ...)
        - Other engineers/architects can follow the pattern
- Multi-Tier Architecture
    - Describe what is a multi-tier architecture→A multi-tier architecture is a system which is separated into multiple logical (limiting the scope) and physical distinct tiers. The physical separation allows each tier to be separately developed, upgraded and scaled. 
    - What is the difference to a multi layer architecture?→Multi-tier architecture distributes application components across multiple physical tiers, while multi-layer architecture separates components into logical layers within a single tier.
    - Name restrictions, which allow this architecture to be loosely coupled >>>
        - Usage of client-server model
        - It is not allowed to skip tiers, they must call each other in a specific order.
    - 
    - The three-tier architecture is the most common and popular architectural pattern for client-server, web-based services.
        - Describe >>>
            - A three-tier architecture separates an application into presentation, application, and data tiers for improved organization and scalability.
            - Presentation tier: Displays information, takes user input, no business logic
            - Application tier: Contains business logic and processes user requests, communicates with the data tier. Sometimes also called business or logic tier.
            - Data tier: Manages data storage, retrieval, and manipulation, ensuring data (user and business) integrity and security.
        - Advantages >>>
            - Easy to scale horizontally
            - Easy to maintain, the logic is concentrated in the application tier
        - Drawback→Monolithic structure of the logic tier. Business concentrated in a single codebase. Possible high CPU and memory consumption and low development policy.
    - 
    - Two tier architecture
        - Describe→One tier for presentation and business tier, for example desktop applications. One tier for data and storage, often remotely.
        - Advantages >>>
            - Eliminates overhead of the logic tier in the three tier architecture
            - Faster, more native experience for the user
    - 
    - There is also a four and five (not often used) tier architecture.
- Microservice Architecture
    - Describe→Microservice architecture organizes our business logic as a collection of loosely coupled and independently deployed services. Each service is owned by a small team and has a narrow scope of responsibility. 
    - 
    - Advantages >>>
        - Small codebase ⇒ faster and easier development, test, and deployment
        - Better performance and horizontal scalability
        - Better organizational scalability
        - Better security (fault isolation)
    - 
    - Drawbacks >>>
        - All the advantages don't come out-of-the-box by switching from a monolithic (tier) architecture to a microservice architecture. 
        - Overhead 
        - Additional challenges (for example, each change should only happen in one service)
    - 
    - Name important best practices >>>
        - Single Responsibility Principle (SRP)
        - Separate Database per service
- Event-Driven Architecture
    - Instead of direct messages that issues command or requests that ask for data in an event-driven architecture, we have only {{events}}.
    - 
    - What is an event?→An event is an immutable statement of a fact or a change.
    - 
    - Which components do we have? >>>
        - Event producers
        - Event consumers
        - Message brokers
    - 
    - What benefits do we get? >>>
        - Decoupled components
        - Asynchronous messages
        - Scalability and flexibility (more services can be added without any changes)
        - Real-time stream analysis (Data analysis, Pattern detection, act upon data in real-time)
    - 
    - Describe the event sourcing pattern→Event sourcing is an architectural pattern where state changes are stored as a sequence of events, enabling reconstruction of past states and facilitating auditing and replayability.
    - 
    - CQRS pattern
        - Stands for→Command Query Responsibility Segregation.
        - Which problems does it solve? >>>
            - Optimizing a database with high load of Read and Update operations (concurrent operations)
                - One database optimized for write, one for read
                - Events from Database A to B to update the data
            - Joining multiple tables located in separate databases that belong to different microservices
                - Changes in two databases of service A and B were sent as event which is taken from service C.
                - Joins the data and provides a read-only "materialized view".
    - 
