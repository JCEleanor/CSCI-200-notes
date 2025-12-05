#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

#include <SFML/Graphics.hpp>

using namespace std;

/**
 * @brief print maze for testing purpose
 *
 * @param rowCount
 * @param colCount
 * @param maze
 */
void printMaze(const int rowCount, const int colCount, const vector<string> &maze)
{
    // print out maze for test
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << maze[static_cast<size_t>(i)][static_cast<size_t>(j)];
        }
        cout << endl;
    }
}

// Pass by value to create a copy
void printQueue(queue<pair<int, int>> q)
{
    std::cout << "Queue contents: " << endl;
    while (!q.empty())
    {
        std::cout << "(" << q.front().first << "," << q.front().second << ")" << endl;
        q.pop();
    }
    std::cout << std::endl;
}

/**
 * @brief draw maze
 *
 * @param rowCount
 * @param colCount
 * @param maze
 * @param window
 * @param visited
 */
void drawMaze(const int rowCount, const int colCount, const vector<string> &maze, sf::RenderWindow &window, vector<vector<int>> &visited)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            sf::RectangleShape cell(sf::Vector2f(15.0f, 15.0f));
            cell.setPosition({j * 15.0f, i * 15.0f});

            // set color
            char mazeChar = maze[static_cast<size_t>(i)][static_cast<size_t>(j)];
            if (mazeChar == '#')
            {
                cell.setFillColor(sf::Color::Black);
            }
            else if (mazeChar == '.')
            {
                if (visited[i][j] == 1)
                {
                    cell.setFillColor(sf::Color::Blue);
                }
                else if (visited[i][j] == 2)
                {
                    cell.setFillColor(sf::Color::Magenta);
                }
                else
                {

                    cell.setFillColor(sf::Color::White);
                }
            }
            else if (mazeChar == 'S')
            {
                cell.setFillColor(sf::Color::Green);
            }
            else if (mazeChar == 'E')
            {
                cell.setFillColor(sf::Color::Red);
            }

            window.draw(cell);
        }
    }
}

int main(int argc, char *argv[])
{
    char searchType;
    string filename;
    cout << "Enter B/b for BFS, D/d for DFS: ";
    cin >> searchType;

    if (argc == 1)
    {
        cout << "Enter filename or maze number for maze: ";
        cin >> filename;
    }
    else
    {
        filename = argv[1];
    }

    fstream fin("./mazePack/" + (filename.find(".maze") != string::npos ? filename : filename + ".maze"));

    if (fin.fail())
    {
        cout << "Failed to open file" << endl;
        return -1;
    }

    int rowCount, colCount, startRow = -1, startCol = -1;
    fin >> rowCount >> colCount;

    string dummy;
    // to get rid of the new line character after R and C
    getline(fin, dummy);

    vector<string> maze;
    for (int i = 0; i < rowCount; i++)
    {
        string row;
        getline(fin, row);
        maze.push_back(row);

        // search for starting point
        for (int j = 0; j < colCount; j++)
        {
            if (row[static_cast<size_t>(j)] == 'S')
            {
                startCol = j;
                startRow = i;
                // S only appear once
                break;
            }
        }
    }

    fin.close();
    cout << "starting point " << startRow << " " << startCol << endl;

    /**
     * @brief
     *
     * 0 = Unvisited (draw as White)
     *
     * 1 = To Be Explored (in the queue/stack, draw as Blue - for extra credit)
     *
     * 2 = Visited (processed, draw as Magenta)
     */
    vector<vector<int>> visited(rowCount, vector<int>(colCount, 0));
    // Create an SFML window that has a width of 15*C and height of 15*R
    sf::Vector2u windowSize(static_cast<unsigned int>(15 * colCount), static_cast<unsigned int>(15 * rowCount));
    sf::RenderWindow window(sf::VideoMode(windowSize), "A Maze");

    // search the maze using BFS with a Queue or
    if (searchType == 'B' || searchType == 'b')
    {
        queue<pair<int, int>> toBeExplored;
        toBeExplored.push({startRow, startCol});

        while (window.isOpen())
        {
            // step 1: handle events
            while (const std::optional event = window.pollEvent())
            {
                // case 1: close event
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            if (!toBeExplored.empty())
            {
                // step 2: perform BFS search
                pair<int, int> current = toBeExplored.front();
                toBeExplored.pop();

                if (maze[current.first][current.second] == 'E')
                {
                    cout << "Endpoint Found" << endl;
                    // break
                    // clean toBeExplore
                    while (!toBeExplored.empty())
                    {
                        toBeExplored.pop();
                    }
                }
                else
                {
                    // marked as visited
                    visited[current.first][current.second] = 2;

                    // find valid neighbors
                    int currentRow = current.first;
                    int currentCol = current.second;
                    static int changeInDirection[4][2] = {
                        {-1, 0}, // up
                        {1, 0},  // down
                        {0, -1}, // left
                        {0, 1},  // right
                    };

                    for (int i = 0; i < 4; i++)
                    {
                        int neighborRow = currentRow + changeInDirection[i][0];
                        int neighborCol = currentCol + changeInDirection[i][1];
                        // check 1: is inside the maze
                        bool isWithinBound = neighborRow >= 0 && neighborRow < rowCount && neighborCol >= 0 && neighborCol < colCount;
                        // check 2: is NOT wall
                        bool isNotWall = maze[neighborRow][neighborCol] != '#';
                        // check 3: is NOT visited
                        bool isNotVisited = visited[neighborRow][neighborCol] == 0;

                        if (isWithinBound && isNotWall && isNotVisited)
                        {
                            visited[neighborRow][neighborCol] = 1;
                            toBeExplored.push({neighborRow, neighborCol});
                            printQueue(toBeExplored);
                        }
                    }
                }

                window.clear();
                // step 2: draw
                drawMaze(rowCount, colCount, maze, window, visited);
                window.display();
                sf::sleep(sf::milliseconds(50)); // Pauses for 50ms
            }
        }
    }
    else
    {
        // DFS with a Stack as appropriate
        stack<pair<int, int>> toBeExplored;

        while (window.isOpen())
        {
            // step 1: handle events
            while (const std::optional event = window.pollEvent())
            {
                // case 1: close event
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            window.clear();
            // step 2: draw
            drawMaze(rowCount, colCount, maze, window, visited);
            window.display();
        }
    }

    return 0;
}