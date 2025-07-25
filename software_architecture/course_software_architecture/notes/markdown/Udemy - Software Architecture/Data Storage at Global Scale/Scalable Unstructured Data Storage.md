- What is unstructured data?→Data which doesn't follow a particular structure, schema or model. For example, "Blob" - Binary Large Object Files, like Audio, Video or Images. Often the data sets and each file or object itself of unstructured data are large.
- Relational/non-relational databases are {{not optimized}}  for unstructured data. They often have also a size limit for binary objects (~megabytes).
- 
- Distributed File System (DFS)
    - Describe→A distributed file system (DFS) is a storage architecture that distributes data across multiple storage nodes. It is similar to a file system on a single computer.
    - Benefits >>>
        - No need for a special API.
        - Files can be modified easily.
        - Efficient for high-performance operations
    - Limitations >>>
        - Number of files is limited
        - No easy access through web API (HTTP+ REST)
- 
- Object Store
    - Describe→An object store is a data storage architecture that manages data as objects rather than files or blocks. Each object contains the data itself, along with metadata and a unique identifier, allowing for easy retrieval and management.
    - Benefits >>>
        - Linear scalability
        - No limit to the number of objects
        - Very high limit on single object size (~5-10 Terabytes)
        - Provides an HTTP + REST API
        - Supports versioning out of the box
        - 
    - Drawbacks >>>
        - Objects are immutable, objects needs to be replaced if changed
        - No easy access like a file-system, access through an SDK or REST API
        - Lower IO performance compared to DFS
- 
- Cloud and Open Source Solutions
    - Cloud-Based Object Store Solutions
        - Amazon S3 (Simple Storage Service) - Amazon's highly scalable cloud storage service that stores object data within buckets. Designed to store and protect any amount of data for various use cases, such as websites, cloud-native applications, backups, archiving machine learning, and analytics.
        - GCP Cloud Storage - Google Cloud's managed service for storing unstructured data for companies of all sizes
        - Azure Blob Storage -  Microsoft's massively scalable and secure object storage for cloud-native workloads, archives, data lakes, high-performance computing, and machine learning
        - Alibaba Cloud OSS (Object Storage Service) - Fully managed enterprise-ready Object Storage Service to store and access any amount of data from anywhere.
    - Open Source and Third-Party Object Store Solutions
        - OpenIO - A software-defined open-source object storage solution ideal for Big Data, HPC, and AI. It is S3 compatible and can be deployed on-premises or cloud-hosted on any hardware that you choose.
        - MinIO - High-performance, S3-compatible object storage. It is native to Kubernetes and 100% open source under GNU AGPL v3.
        - Ceph - Open-source, reliable and scalable storage. Ceph provides a unified storage service with object, block, and file interfaces from a single cluster built from commodity hardware components.
