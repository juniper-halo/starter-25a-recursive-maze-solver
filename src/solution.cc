#include "solution.hpp"

/*std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x,
    unsigned int start_y) {
  std::vector<std::pair<unsigned int, unsigned int>> path;
  std::vector<std::vector<bool>> visited;

  return path;
}

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int x,
    unsigned int y,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {
  return false;
}*/

bool SolveMazeRecursive(const std::vector<std::vector<char>>& maze,
                        unsigned int x, unsigned int y,
                        std::vector<std::pair<unsigned int, unsigned int>>& path,
                        std::vector<std::vector<bool>>& visited)
{
    // Check bounds: if x or y is out of range, return false.
    if (x >= maze.size() || y >= maze[0].size())
        return false;

    // If the current cell is a wall or has been visited, return false.
    if (maze[x][y] == '#' || visited[x][y])
        return false;

    // Mark the cell as visited and add it to the path.
    visited[x][y] = true;
    path.push_back({x, y});

    // If the current cell is the exit, we've found a solution.
    if (maze[x][y] == 'X')
        return true;

    // Down: (x + 1, y)
    if (x + 1 < maze.size() && SolveMazeRecursive(maze, x + 1, y, path, visited))
        return true;
    // Up: (x - 1, y) -- ensure x > 0 before subtracting.
    if (x > 0 && SolveMazeRecursive(maze, x - 1, y, path, visited))
        return true;
    // Right: (x, y + 1)
    if (y + 1 < maze[0].size() && SolveMazeRecursive(maze, x, y + 1, path, visited))
        return true;
    // Left: (x, y - 1) -- ensure y > 0 before subtracting.
    if (y > 0 && SolveMazeRecursive(maze, x, y - 1, path, visited))
        return true;

    //no solution
    path.pop_back();
    return false;
}


std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x, unsigned int start_y)
{
    std::vector<std::pair<unsigned int, unsigned int>> path;
    if (maze.empty() || maze[0].empty())
        return path;

    
    unsigned int rows = maze.size();
    unsigned int cols = maze[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));


    SolveMazeRecursive(maze, start_x, start_y, path, visited);
    return path;
}
