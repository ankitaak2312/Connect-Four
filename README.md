# 🎮 Connect Four AI Solver  
**C++ | Minimax Algorithm | Alpha–Beta Pruning | Adversarial Search**

This project implements a fully playable **Connect Four** game along with an intelligent **AI agent** that uses Minimax + Alpha–Beta Pruning to choose the optimal move.  
It demonstrates adversarial search, recursion, heuristics, and game-tree optimization.

---

## 🚀 Features
- Human vs AI gameplay
- Minimax algorithm for optimal decision-making
- Alpha–Beta Pruning for efficient search (60–80% nodes pruned)
- Adaptive AI difficulty (based on search depth)
- Gravity-based dropping logic
- Multi-directional win detection: horizontal, vertical, diagonal

---

## 🧠 How the AI Works
The AI builds a game tree of possible moves using **Minimax**, evaluating positions using a heuristic function.  
Alpha–Beta pruning eliminates unnecessary branches, reducing computation time drastically.

### Minimax Flow:
1. Generate all possible child states  
2. Evaluate recursively  
3. Maximize AI score, minimize opponent score  
4. Prune branches using (alpha, beta) bounds  

---

## 🧩 Project Structure
