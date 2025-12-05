# CSCI 200 - Fall 2025

## Foundational Programming Concepts & Design

## [source](https://cs-courses.mines.edu/csci200/homework/hw6.html)

→This assignment is due by Thursday, December 11, 2025, 11:59 PM.←

→ As with all assignments, this must be an individual effort and cannot be pair programmed. Any debugging assistance must follow the course collaboration policy and be cited in the comment header block for the assignment.←

Jump To: · [Rubric](#rubric) · [Submission](#submit) ·

For this assignment you will build upon [Lab6C](../labs/lab6c.html). This piece will now animate a solution to the maze, such as Maze 7 below.

![Maze 7](images/maze7.png)

## Solve the Maze (Maybe)

Before the maze has been drawn, ask the user via the terminal how they wish to solve the maze. Either by BFS or by DFS.

Based on the user's selection, search the maze using BFS with a Queue or DFS with a Stack as appropriate. Begin your search at the `S` space and continue until the `E` space is reached or the search is exhausted.

When the search is complete, draw the maze with visited cells colored Magenta.

An example of a successful BFS search is shown below:

![Maze 7 BFS](images/maze7_bfs.png)

An example of a successful DFS search is shown below:

![Maze 7 DFS](images/maze7_dfs.png)

An example of an unsuccessful search is shown below:

![Maze 4 Unsolvable](images/maze4_unsolved.png)

## Animating the Solve

To animate each step of the search process, we'll use the draw loop as the loop for our search process. Each iteration, we will do a few steps:

- clear the current window
- Draw the current maze state (walls = Black, unvisited = white, visited = Magena, start = Green, end = Red)
- Get our next location to process (if it exists)
- Check if it's the end location
  - Print end reached
  - For the purposes of our animation - empty the list of nodes to process to halt the search
- If it's not the end location
  - Check each neighbor to potentially add to list to process
- display the current window
- check for events (window close, q or escape keypress)
- Tell SFML to sleep for a brief amount of time - without this, the animation will run as fast as the window can redraw. We'll explicitly put in a delay before drawing the next frame. This delay equates to our framerate. Choose a delay of 50 milliseconds, which equates to 20 frames per second. The following SFML call will sleep for `n` milliseconds:

```cpp
sf::sleep( sf::milliseconds(n) );
```

You may tune this value up or down as you are testing to trace the process of your search algorithm.

An example of a partial search in progress is shown below:

![Maze 3 Partially Solved](images/maze3_partial_solve.png)

## Extra Credit

There are two potential extra credit pieces:

- Color potential cells to explore Blue. These are locations that have been added to the neighbors to process list but not yet visited to check.
- Color the path from start to end in Yellow.

An example of both is shown below;

Breadth-First Search of Maze 3

Depth-First Search of Maze 3

## Testing

The graders will build your program with the Makefile you provide to match your code structure and run your program against five private test mazes.

## Grading Rubric

Your submission will be graded according to the following rubric:

| Points | Requirement Description                                      |
| ------ | ------------------------------------------------------------ |
| 0.5    | Submitted correctly by Thursday, December 11, 2025, 11:59 PM |
| 0.5    | Project builds without errors nor warnings.                  |
| 2.0    |                                                              |

| Extra Credit Points | Requirement Description                                                                                           |
| ------------------- | ----------------------------------------------------------------------------------------------------------------- |
| +0.25               | Display neighboring squares to be checked in blue                                                                 |
| +0.25               | When a solution is found, color the path from start to end in yellow (this does not need to be the shortest path) |

## Submission

Always, always, ALWAYS update the header comments at the top of your main.cpp file. And if you ever get stuck, remember that there is LOTS of [help](../resources/help.html) available.

Zip together your `main.cpp`, `Makefile`, `*.hpp`, `*.h`, `*.cpp` files and name the zip file `A6_USERNAME.zip`. Upload this zip file to Canvas under A6.

→This assignment is due by Thursday, December 11, 2025, 11:59 PM.←

→ As with all assignments, this must be an individual effort and cannot be pair programmed. Any debugging assistance must follow the course collaboration policy and be cited in the comment header block for the assignment.←
