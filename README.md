🚗 Fleet Management Console System
=====================================

A C++ console-based Fleet Management System developed as part of my learning journey as I am a ​Computer Science Student (Year 1).

-----------------------------------------------------------------------------------
This project demonstrates practical usage of:
=============================================

1- Structures

2- STL containers (vector, set, maps )

3- Input validation

4- Basic data filtering and searching

-----------------------------------------------------------------------------

The system currently allows the user to:
==========================================

🟢Add a new vehicle

🟢Display all vehicles in the fleet

🟢Display unique brands in the fleet (using set as a STL in order to display each brand one time )

🟢Display vehicle count per brand (The amount of each brand in the fleet )

🟢Search vehicles by brand

🟢Search vehicles by model

🟢Search vehicles by year

--------------------------------------------------------------------------------------------------------

🚀v2.0 Update 
==========

​I have significantly upgraded my Fleet Management System, focusing on structural improvements, performance optimization, and the advanced application of C++ Standard Template Library (STL) containers.

-------------------------------------------------------------------------------------
​✨ Key Improvements
=======================

​Modular Architecture:
=======================
Refactored the code by moving logic from main() into dedicated functions, significantly improving readability and maintainability.

​Performance Optimization:
========================
Eliminated all nested loops, transitioning to more efficient data processing techniques. 


​Memory Efficiency:
====================
Implemented references (&) for passing vector and map objects to avoid unnecessary data copying and reduce memory overhead.

​Advanced Data Structures:
===========================
-​Integrated std::unordered_map to achieve O(1) average time complexity for data lookups.
**replacing all std::map (O log n ) with std::unordered_map O(1) for better performance (as long as no need for arrangement).
-​Utilized std::priority_queue to implement dynamic sorting features.

​New Functionality:
===================
🟢​Sort vehicles from newest to oldest.
​🟢Sort vehicles from oldest to newest.

​🛠 Tech Stack
==============
​Language: C++
​STL Containers: vector, set, unordered_map, priority_queue.

You could check the history to see how the code has changed over time.
**********************************************************************
-----------------------------------------------------------------------------------

​🏗 Project Status & Roadmap
=============================
​The project is under active development. My next major goal is to refactor the entire system using Object-Oriented Programming (OOP) principles to move from a procedural design to a robust class-based architecture . In addition, the project can be extended to use more advanced concepts such as pointers and smart pointers.

------------------------------------------------------------------------------------------

Click here to watch the program Demo on Google drive :

https://drive.google.com/file/d/1kv-THPVH5eGIAUaWLXsLh85TWHUJlX2H/view?usp=sharing





