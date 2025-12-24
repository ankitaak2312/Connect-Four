# Connect Four AI Solver

A terminal-based implementation of the Connect Four game featuring an AI opponent built using the Minimax algorithm with Alpha–Beta pruning.

This project focuses on adversarial search, recursion, and game-tree optimization rather than graphical interfaces.

---

## Overview

Connect Four is a two-player, turn-based game played on a 6×7 grid. Players alternate turns dropping pieces into columns, with the goal of connecting four pieces horizontally, vertically, or diagonally.

In this project, a human player competes against an AI agent that computes optimal moves using depth-limited Minimax search with Alpha–Beta pruning.

---

## Key Features

- Minimax algorithm with Alpha–Beta pruning for efficient game-tree exploration  
- Depth-based difficulty levels (Easy → God Mode)  
- Correct gravity-based move simulation with undo support  
- Full win detection: horizontal, vertical, and diagonal  
- Clean recursive structure for adversarial search  

---

## Algorithm Details

### Minimax with Alpha–Beta Pruning

The AI evaluates possible game states recursively:

- **Maximizing player:** AI  
- **Minimizing player:** Human  

Alpha–Beta pruning eliminates branches that cannot influence the final decision, significantly reducing the number of evaluated states compared to naive Minimax.


Time Complexity (worst-case): O(b^d)
With Alpha–Beta pruning: significantly reduced in practice
b = branching factor (~7), d = search depth
