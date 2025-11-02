## Team ANÉ

```markdown
# Build and Run Instructions
  ```
- **Compilation**:  
  ```bash
  cd SystemFiles
  make all
  ```

- **Demo Main**:  
  ```bash
  make run_demo
  ```

- **Unit Tests**:  
  ```bash
  make run_tests
  ```
```

# COS 214 Project - Plant Nursery Simulator

<a href="https://cdn.pixabay.com/animation/2023/04/16/19/38/19-38-30-94_512.gif"><img src="https://cdn.pixabay.com/animation/2023/04/16/19/38/19-38-30-94_512.gif" style="width: 300px; max-width: 100%; height: auto" title="Click to enlarge picture" /></a>

# Contents

- [Description](#description)
- [Documentation and UML diagrams](#documentation)
- [Setup](#setup)
- [Team](#team)

# Description

The Plant Nursery Simulator is a C++ project that models a complete plant nursery ecosystem. Staff can manage plant growth, coordinate inventory activities, and handle customer interactions through a system that implements 10+ design patterns for flexibility, maintainability, and scalability.

The simulation demonstrates object-oriented design excellence through patterns like Factory Method for plant creation, State for plant life cycles, Decorator for customer customizations, and Chain of Responsibility for staff request handling to name a few.

# Documentation

[Report](Documents/Report.pdf)

[Functional Requirements](Documents/Functional_Requirements.pdf)

[Design Pattern Specifications](Documents/Specifications.pdf)

[Doxygen Documentation](Documents/Doxygen/)

[UML Diagrams](UML/)

# Setup

### Prerequisites

(finalise once gui is done)
sudo apt-get install doctest-dev

### Cloning

git clone https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen.git
cd COS214_Prac_GIT_Doxygen/SystemFiles/src


### Building

This project can be built using Makefile:

Compilation: make all (Ensure you are currently in the SystemFiles/src directory)
Demo Main: make run
Testing: make run_tests (//add run_tests to Makefile)


### Running

When the program runs:
1. Browse available plants using the inventory system
2. Select plants and apply customizations (pots, wrapping, arrangements)
3. Staff will handle requests through the command system
4. Complete purchases with undo capability
5. Monitor plant growth and care routines

# Team

<table>
    <tr><th>Member</th><th>Roles</th><th>Description</th></tr>
    <tr>
      <td align="center">
        Ané de Ridder<br>Team Leader<br>
        <img src="https://cdn-icons-png.flaticon.com/512/7662/7662083.png" width="200" height="200">
      </td>
      <td align="center">
        Project Coordination<br>System Architecture<br>Design Patterns
        <a href="#">
          <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
        </a>
      </td>
      <td>
        //add description later
      </td>
    </tr>
    <tr>
      <td align="center">
        Bridget Nkosi<br>Core Developer<br>
        <img src="https://cdn-icons-png.flaticon.com/512/2907/2907253.png" width="200" height="200">
      </td>
      <td align="center">
        System Development<br>Pattern Implementation<br>Documentation
        <a href="https://github.com/nkosibridgett">
          <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
        </a>
      </td>
      <td>
        //add description later
      </td>
    </tr>
    <tr>
      <td align="center">
        David Kalu<br>System Developer<br>
        <img src="https://cdn-icons-png.flaticon.com/512/7662/7662005.png" width="200" height="200">
      </td>
      <td align="center">
        Pattern Logic<br>State Management<br>Testing
        <a href="#">
          <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
        </a>
      </td>
      <td>
        //add description later
      </td>
    </tr>
    <tr>
      <td align="center">
        Joshua Kretschmer<br>Backend Developer<br>
        <img src="https://cdn-icons-png.flaticon.com/512/7662/7662081.png" width="200" height="200">
      </td>
      <td align="center">
        System Architecture<br>Facade & Command<br>Integration
        <a href="#">
          <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
        </a>
      </td>
      <td>
        //add description later
      </td>
    </tr>
    <tr>
      <td align="center">
        Keagan<br>Developer<br>
        <img src="https://cdn-icons-png.flaticon.com/512/7662/7662129.png" width="200" height="200">
      </td>
      <td align="center">
        Pattern Implementation<br>System Development<br>Testing
        <a href="#">
          <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
        </a>
      </td>
      <td>
       //add description later
      </td>
    </tr>
    <tr>
      <td align="center">
        Michelle Njoroge<br>Frontend & Testing<br>
        <img src="https://cdn-icons-png.flaticon.com/512/7662/7662129.png" width="200" height="200">
      </td>
      <td align="center">
        UI Integration<br>Testing<br>Documentation
        <a href="#">
          <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
        </a>
      </td>
      <td>
        //add description later
      </td>
    </tr>
    <tr>
      <td align="center">
        Ophelia Greyling<br>Quality Assurance<br>
        <img src="https://cdn-icons-png.flaticon.com/512/7662/7662124.png" width="200" height="200">
      </td>
      <td align="center">
        Quality Control<br>Testing<br>Documentation
        <a href="#">
          <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
        </a>
      </td>
      <td>
        //add description later
      </td>
    </tr>
</table>


