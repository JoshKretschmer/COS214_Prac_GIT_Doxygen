<!--  PROFILE VIEWS COUNTER -->
<img align="right" src="https://komarev.com/ghpvc/?username=TeamBridgetCOS214&label=Profile%20views&color=4caf50&style=flat"><br>

<!--  PROJECT BANNER -->
<h1 align="center">
  <img src="https://cdn.pixabay.com/animation/2023/04/16/19/38/19-38-30-94_512.gif" alt="COS214 PlantCare Banner">
</h1>

<!-- ANIMATED TEXT -->
<h1 align="center">  
  <a href="https://git.io/typing-svg">
    <img src="https://readme-typing-svg.herokuapp.com?font=Poppins&size=40&pause=1000&color=00B67A&center=true&vCenter=true&width=435&height=50&lines=WHat's+Up+Geeks;Welcome+to+Team+Git_doxygen+Repo!;COS214+Design+Patterns+Project"/>
  </a>
</h1>

<!-- ABOUT OUR PROJECT -->
<h4 align="center">
  A C++ project showcasing <strong>Strategy</strong>, <strong>Observer</strong>, <strong>State</strong>, <strong>Command</strong>, and <strong>Memento</strong> design patterns.<br>
  Built with care, precision, and a little too much coffee.<br>
  Developed by <strong>Git_doxygen Team</strong> for the University of Pretoria's COS214 course.
</h4>

<!-- TEAM BADGES -->
<div align="center">
    <a href="https://www.up.ac.za/"><img src="https://img.shields.io/badge/University%20of%20Pretoria-002F6C?style=for-the-badge&logo=google-scholar&logoColor=white" target="_blank"></a>
    <a href="https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen/tree/Bridget" target="_blank"><img src="https://img.shields.io/badge/GitHub%20Branch-Bridget-181717?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a>
    <a href="https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen/tree/Josh" target="_blank"><img src="https://img.shields.io/badge/GitHub%20Branch-Josh-181717?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a>
    <a href="https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen/tree/Kalu" target="_blank"><img src="https://img.shields.io/badge/GitHub%20Branch-Kalu-181717?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a>
    <a href="https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen/tree/Ophelia_Dev" target="_blank"><img src="https://img.shields.io/badge/GitHub%20Branch-Ophelia_Dev-181717?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a>
    <a href="https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen/tree/Keagan" target="_blank"><img src="https://img.shields.io/badge/GitHub%20Branch-Keagan-181717?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a>
    <a href="https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen/tree/Ane" target="_blank"><img src="https://img.shields.io/badge/GitHub%20Branch-Ane-181717?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a>
    <a href="https://github.com/JoshKretschmer/COS214_Prac_GIT_Doxygen/tree/Michelle" target="_blank"><img src="https://img.shields.io/badge/GitHub%20Branch-Michelle-181717?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a>
    <a href="mailto:nkosibridgett43@gmail.com"><img src="https://img.shields.io/badge/Contact%20Us-Email-EA4335?style=for-the-badge&logo=gmail&logoColor=white"></a>
</div>


## 📝 Project Overview

**Project Name:** Git_Doxygen  
**Date:** 28-10-2025  

**Team Lead:** Ane

### Overview
The COS214 PlantCare project is a C++ system designed to simulate a greenhouse and nursery environment.  
It handles plant growth, care routines, inventory management, staff coordination, and customer interactions, implementing multiple design patterns to maintain clean and scalable architecture.

### Goals
- Enable staff to execute plant care routines (watering, fertilizing, pruning, sunlight management).  
- Track plant growth stages and lifecycle states for different plant types.  
- Maintain real-time inventory that synchronizes greenhouse stock with the sales floor.  
- Support staff-customer coordination for purchases, recommendations, and browsing.  
- Allow customers to customize orders and revert actions (undo/redo functionality).  
- Ensure a modular and extendable system architecture using design patterns.

### Specifications
- **Staff Plant Care Execution**: Staff perform care routines on plants using the Strategy and Command patterns to adapt dynamically.  
- **Plant Monitoring**: Plants notify staff of required care; Observer and State patterns manage reactive updates and lifecycle stages.  
- **Staff–Inventory Coordination**: Mediator and Composite patterns ensure staff can update inventory in a centralized, organized way.  
- **Customer Interactions**: Customers can browse plants (Iterator), customize orders (Decorator & Builder), and receive recommendations (Strategy).  
- **Purchase Process**: Simplified via Facade and Bridge patterns, integrating staff, inventory, and payment handling.  
- **Undo/Redo Orders**: Memento pattern captures snapshots of order states for safe reversal of actions.  
---

## 🌼 Meet the Team

- **Ané de Ridder** – Always curious, bringing energy and fresh ideas to the team.  
- **Bridget Nkosi** – Loves problem-solving and exploring creative solutions.
- **David Kalu** – Curious and analytical, always ready to tackle challenges head-on.  
- **Joshua Kretschmer** – Keeps the team connected and ensures things run smoothly. 
- **Joshua Kretschmer** – Keeps the team connected and ensures things run smoothly.  
- **Michelle Njoroge** – Brings creativity and a sense of style to everything she touches.
- **Ophelia Greyling** – Detail-oriented and passionate about making things clear and organized.     

---

## 🧩 Implemented Design Patterns

| Pattern | Purpose | Key Files |
|:--|:--|:--|
| **Strategy** | Allows customizable plant care routines (watering, fertilizing, sunlight) | `PlantCare.cpp`, `Strategy.cpp` |
| **Command** | Encapsulates plant care and purchase actions as commands for flexibility | `Command.cpp`, `PlantCare.cpp` |
| **Observer** | Notifies staff/customers of plant updates and stock changes in real time | `Observer.cpp`, `PlantState.cpp` |
| **State** | Models plant life cycles (seedling → mature → sellable → dying) | `PlantState.cpp`, `State.cpp` |
| **Mediator** | Coordinates communication between staff, inventory, and customers | `Mediator.cpp`, `Inventory.cpp` |
| **Composite** | Structures inventory collections and plant groups | `Inventory.cpp`, `PlantCollection.cpp` |
| **Decorator** | Allows dynamic customization of plants and orders (pots, gift wrapping) | `Decorator.cpp`, `Plant.cpp` |
| **Abstract Factory** | Introduces new stock/families of plants without tightly coupling code | `AbstractFactory.cpp`, `PlantFactory.cpp` |
| **Iterator** | Enables browsing and traversing of available plant collections | `Iterator.cpp`, `PlantCollection.cpp` |
| **Facade** | Simplifies purchase process by providing a unified interface | `Facade.cpp`, `PurchaseSystem.cpp` |
| **Memento** | Supports undo/redo of orders and customization history | `Memento.cpp`, `Order.cpp` |
| **Chain of Responsibility** | Handles customer queries in sequence, escalates if needed | `Chain.cpp`, `CustomerRequest.cpp` |
| **Bridge** | Separates abstraction (e.g., purchase interface) from implementation | `Bridge.cpp`, `PurchaseSystem.cpp` |
| **Template** | Defines skeleton of operations while allowing certain steps to vary | `Template.cpp`, `PlantCare.cpp` |
| **Adapter** | Integrates external or legacy modules into the system | `Adapter.cpp`, `ExternalModule.cpp` |

---

## Compilation Instructions

```bash
# Option 1 — Using Makefile
make
./demo

# Option 2 — Manual build
g++ -std=c++11 *.cpp -o demo
./demo
>>>>>>> origin/Bridget
