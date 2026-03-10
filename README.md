*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-rush01.png" alt="Rush 01 Cover" width="100%" />
</div>

<div align="center">
  <h1>🚀 Rush 01: The Skyscraper Puzzle</h1>
  <p><i>Algorithmic problem solving, recursive backtracking, and data parsing.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-125%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**Rush 01** is the second collaborative weekend project of the 42 C Piscine. Teams are tasked with creating a C program that solves a complex 4x4 grid puzzle based on visibility constraints.

The objective is to place boxes of height 1 to 4 on each available square. The placement must follow two strict rules:
1. **Uniqueness:** Each row and column must contain exactly one box of each size.
2. **Visibility:** The numbers provided at the edges of the map dictate exactly how many boxes are visible from that specific point of view. For example, a tall box (height 4) will completely hide any shorter boxes placed behind it.


---

## 🧠 Core Logic Breakdown: Backtracking

To solve this puzzle efficiently without hardcoding millions of possibilities, we use a **Recursive Backtracking Algorithm**. This is a brute-force approach that builds a solution incrementally and abandons it ("backtracks") the moment it determines the current path cannot yield a valid result.

| Phase | Concept & Implementation |
| :--- | :--- |
| **1. Parsing Input** | The program receives exactly one argument: a single string containing 16 numbers separated by spaces. We must extract these values (`col1up` through `row4right`) and store them in an array to represent our boundary constraints. Any deviation from this format must be considered an error. |
| **2. Grid Initialization** | We initialize a 4x4 2D array (our grid) filled with zeros, representing empty spaces. |
| **3. Recursive Placement** | The core algorithm starts at the top-left coordinate `(0, 0)`. It attempts to place the number `1`. Before placing it, it checks the *Uniqueness* rule: does `1` already exist in this row or column? If not, it places the `1` and recursively moves to the next coordinate `(0, 1)`. |
| **4. The Backtrack** |  If the algorithm reaches a cell where no numbers (1-4) can be legally placed, it hits a dead end. The function returns `false`, effectively taking a step backward to the previous cell. It changes that cell's number to the next available option and tries again. |
| **5. View Validation** | Once the algorithm successfully fills all 16 cells, it runs a final check against the 16 boundary numbers provided in the input. It counts the visible "boxes" from the top, bottom, left, and right. If the grid perfectly matches the input constraints, we print the first solution encountered. If it fails, it backtracks and continues searching. |

---

## 🛠️ Instructions

### 🧪 Compilation & Testing
The program must be compiled combining all necessary `.c` files in your `ex00` directory.

1. **Clone the repository:**
   ```bash
   git clone git@github.com:rfs-hybrid-42-piscine/Rush-01.git Rush-01
   cd Rush-01/ex00
   ```

2. **Compile the executable:**
   The subject strictly requires the executable to be named `rush-01` and compiled with specific flags.
   ```bash
   cc -Wall -Wextra -Werror -o rush-01 *.c
   ```

3. **Execute with valid input:**
   Provide the 16 boundary numbers as a single formatted string.
   ```bash
   ./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
   ```
   **Expected Output:**
   ```text
   1 2 3 4
   2 3 4 1
   3 4 1 2
   4 1 2 3
   ```

4. **Execute with invalid input/unsolvable puzzle:**
   If the puzzle is impossible, or if the input is improperly formatted, the program must display exactly `Error` followed by a line break.
   ```bash
   ./rush-01 "1 2 3 4"
   ```
   **Expected Output:**
   ```text
   Error
   ```

### 🚨 The Norm & Constraints
* **Allowed Functions:** You are strictly limited to `write`, `malloc`, and `free`. 
* **The Norm:** Every single `.c` and `.h` file must pass the 42 Norm. 
* **Errors:** If you have bonus files or functions, they are included in the norm check, and a norm error will result in a 0.
* **The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:18:37 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/09 21:22:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command before pushing:
```bash
norminette -R CheckForbiddenSourceHeader *.c *.h
```

---

## 📚 Resources & References

* [Backtracking Algorithms Explained](https://www.geeksforgeeks.org/backtracking-algorithms/) - Understanding the core recursive concept required to solve Rush 01.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.
* [Official 42 Norminette Repository](https://github.com/42School/norminette) - The open-source linter enforcing the strict 42 coding standard.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions were built manually to strictly comply with the 42 Norm and deeply understand nested logic and recursive algorithms.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
