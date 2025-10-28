<!--  PROFILE VIEWS COUNTER -->
<img align="right" src="https://komarev.com/ghpvc/?username=TeamBridgetCOS214&label=Profile%20views&color=4caf50&style=flat"><br>

<!--  PROJECT BANNER -->
<h1 align="center">
  <img src="https://i.imgur.com/7MQqC4s.jpeg" alt="COS214 PlantCare Banner">
</h1>

<!-- ANIMATED TEXT -->
<h1 align="center">  
  <a href="https://git.io/typing-svg">
    <img src="https://readme-typing-svg.herokuapp.com?font=Poppins&size=40&pause=1000&color=00B67A&center=true&vCenter=true&width=435&height=50&lines=Hey+there!;Welcome+to+Team+Bridget's+Repo!;COS214+Design+Patterns+Project"/>
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
    <a href="mailto:teambridget.cos214@gmail.com"><img src="https://img.shields.io/badge/Contact%20Us-Email-EA4335?style=for-the-badge&logo=gmail&logoColor=white"></a>
</div>

---

## Meet the Team

| Member | Role | Favourite Quote |
|--------|------|----------------|
| **Bridget Nkosi** | Database & Logic Developer | “Undo() your mistakes, redo() your greatness.” |
| **Ané de Ridder** | State & Observer Architect | “If it compiles, it works. Probably.” |
| **Ophelia Greyling** | UML & Documentation Lead | “The UML is my canvas.” |
| **Joshua Kretschmer** | Project Maintainer | “Makefile is life.” |
| **Michelle Njoroge** | UI/UX Analyst | “Design should whisper, not scream.” |
| **David Kalu** | Debugger & QA | “Segmentation fault? My old friend.” |

---

## Implemented Design Patterns

| Pattern | Purpose | Key Files |
|:--|:--|:--|
| **Strategy + Command** | Customizable plant care actions (watering, fertilizing, sunlight) | `PlantCare.cpp`, `Command.cpp` |
| **Observer + State** | Reactive plant lifecycle and monitoring | `Observer.cpp`, `PlantState.cpp` |
| **Memento** | Undo/Redo order functionality | `Order.cpp`, `Memento.cpp` |

---

## Compilation Instructions

```bash
# Option 1 — Using Makefile
make
./demo

# Option 2 — Manual build
g++ -std=c++11 *.cpp -o demo
./demo



