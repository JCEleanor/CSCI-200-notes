#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

/**
 * @brief draw maze
 *
 * @param rowCount
 * @param colCount
 * @param maze
 * @param window
 */
void drawMaze(const int rowCount, const int colCount, const vector<string> &maze, sf::RenderWindow &window)
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
                cell.setFillColor(sf::Color::White);
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
    string filename;

    if (argc == 1)
    {
        cout << "Enter filename for maze: ";
        cin >> filename;
    }
    else
    {
        filename = argv[1];
    }

    fstream fin("./mazePack/" + filename);

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

    cout << "starting point " << startRow << " " << startCol << endl;
    fin.close();
    // Create an SFML window that has a width of 15*C and height of 15*R
    sf::Vector2u windowSize(static_cast<unsigned int>(15 * colCount), static_cast<unsigned int>(15 * rowCount));
    sf::RenderWindow window(sf::VideoMode(windowSize), "A Maze");

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
        drawMaze(rowCount, colCount, maze, window);
        window.display();
    }

    return 0;
}