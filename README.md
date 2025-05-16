# My Learnings Repository  

## Overview  

This repository contains my personal learning journey through various programming courses, books, and online resources. It serves as a collection of code examples, projects, and notes from my studies in software development and computer science topics.  

## Structure  

The repository is organized by learning source (course, book, or website), with each containing its own set of examples, projects, and notes. Most learning modules include:  
- Source code examples  
- Implementation exercises  
- Practical projects (rarely)
- Relevant notes  

### Notes Export  
Some of the notes were exported from [Remnote](https://www.remnote.com/) as **HTML** and **Markdown** files. The Markdown files can be re-imported into Remnote or other note-taking apps if needed.  

**However**, I encourage taking your own notes rather than relying solely on these exports. The process of summarizing and rewriting information is a crucial part of the learning process!

## Building the Code  

Most learning modules include a `CMakeLists.txt` file in their root directory for easy compilation. The standard build process is:  

```bash  
mkdir build  
cd build  
cmake ..  
cmake --build .  
```  

**Important:** Always use the provided `CMakeLists.txt` in each learning module's root directory, as these often include necessary external dependencies via `FetchContent` (such as Boost or Microsoft GSL).  

## Dependencies  

Dependencies are typically handled automatically through CMake's `FetchContent` mechanism. Common dependencies include:  
- Boost libraries  
- Microsoft Guidelines Support Library (GSL)  
- Various testing frameworks  
- Other course/book-specific libraries  

## Contents  

The repository includes learnings from:  
- Online courses (Udemy, Coursera, etc.)  
- Programming books  
- Documentation/tutorials from official websites  
- Personal exploration projects  

## Notes  

- This is a personal learning repository—code may not represent production-ready quality.  
- Some examples are modified versions of course/book materials for experimentation.  
- The structure and content will evolve as I continue learning.  

## License  

Unless otherwise specified in individual directories, code is available under the MIT License. See the `LICENSE` file for details.  

Happy coding! 🚀