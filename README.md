🚗 Fleet Management Console System
=====================================

A C++ console-based Fleet Management System developed as part of my Computer Science learning journey. The project evolved from a basic procedural application into a modular, object-oriented system focused on clean code, reusability, and efficient data processing.
---------------------------------------------------------------------------------------------------------------------------------------------------

Features
========

-🟢 Vehicle Management: Add new vehicles and display all vehicles in the fleet.
-🟢 Brand Management: Display unique vehicle brands without duplication.
-🟢 Fleet Statistics: Count the number of vehicles for each brand.
-🟢Search Functionality: Search for vehicles by brand, model, or manufacturing year.
-🟢Sorting: Sort vehicles from newest to oldest and from oldest to newest.
-🟢Input Validation: Handle invalid user input to improve reliability.
-🟢Modular Architecture: Organize the code into separate header (".h") and source (".cpp") files.
-🟢Reusable Components: Use templates and shared functionality to reduce code duplication and improve maintainability.

Object-Oriented Programming (OOP)
=================================

Applied the four fundamental pillars of OOP:
---------------------------------------------

-🔴 Encapsulation: Organizing data and related functionality within classes.
-🔴 Abstraction: Hiding implementation details behind clear interfaces.
-🔴 Inheritance: Reusing and extending functionality through class hierarchies.
-🔴 Polymorphism: Using function overriding to provide specialized behavior in derived classes.

Additional Design Concepts
===========================

-🔴 Association: Representing relationships between independent classes that interact with each other.
-🔴 Composition: Integrating "Engine" and "Battery" components into the "Car" and "Motorcycle" classes to represent vehicle composition.
-🔴 Templates: Writing reusable, type-independent code to reduce duplication and improve maintainability.
-🔴 Modular Design: Separating class declarations (".h") from implementations (".cpp").

Data Structures & Algorithms
=============================
-◾STL Containers: "vector", "set", and "unordered_map".
-◾ Hash-Based Searching: Using "unordered_map" for average (O(1)) lookups by key, where applicable.
-◾Binary Search: Searching sorted data in (O(\log n)) time.
-◾Searching & Filtering: Finding vehicles by brand, model, and manufacturing year.
-◾ Sorting: Organizing vehicles chronologically.
-◾ Time Complexity Awareness: Choosing suitable data structures and algorithms, avoiding unnecessary nested loops, and using references to reduce unnecessary copying.

Tech Stack
==========

- Language: C++
- Concepts: OOP, Templates, STL, Data Structures, Algorithms, and Input Validation.
- Tools: Git, GitHub, and CLion.

Project Evolution
=================

- _Version 1.0_
  ===========
-  Initial Implementation: A basic implementation with nested loops and all logic written inside "main()".
- _Version 2.0_
  =============
- _ — Functional Refactoring: Introduced reusable functions to improve code organization and reduce code duplication, while keeping the implementation in a single file.
- _Version 3.0_
  ==============
-  — OOP Refactoring: Restructured the project into multiple ".h" and ".cpp" files, applying OOP principles, class relationships, templates, and polymorphism to improve modularity, reusability, and maintainability.

Explore the "Git commit history" (https://github.com/marcellino-cpu/Fleet-Management-system/commits/main/) to see how the project evolved across these versions.


Future Improvements
=====================

- Persistent data storage through file handling or database integration.
- Expanded unit testing and error handling.

Project Status
===============

Actively developing.

This project is part of my ongoing journey in C++, data structures, algorithms, and software design.
