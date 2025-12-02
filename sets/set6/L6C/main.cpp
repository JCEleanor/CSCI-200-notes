#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
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
        // use a try catch block?
        cout << "Failed to open file" << endl;
        return -1;
    }

    int rowCount, colCount, startRow = -1, startCol = -1;
    fin >> rowCount >> colCount;

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

    // print out maze for test
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << maze[static_cast<size_t>(i)][static_cast<size_t>(j)];
        }
        cout << endl;
    }

    cout << "starting point " << startRow << " " << startCol << endl;
    fin.close();
    return 0;
}