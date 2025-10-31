// 🌳 Hacktoberfest 2025 Exclusive Project 🌳
// Project: The Fractal Tree (ASCII Art Generator)
// Description: Generates a recursive ASCII fractal tree in the console.
// Difficulty: Advanced (Recursion + Geometry + Visualization)

#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h> // For usleep (works on Linux/macOS/WSL)
using namespace std;

// Canvas size
const int WIDTH = 80;
const int HEIGHT = 30;

// 2D grid to draw the tree
vector<string> canvas(HEIGHT, string(WIDTH, ' '));

// Recursive function to draw the tree
void drawTree(int x, int y, double length, double angle, int depth) {
    if (depth == 0 || length < 1) return;

    int x2 = x + int(length * cos(angle));
    int y2 = y - int(length * sin(angle));

    // Draw a line (simple Bresenham-like)
    int dx = abs(x2 - x), dy = abs(y2 - y);
    int sx = (x < x2) ? 1 : -1;
    int sy = (y < y2) ? 1 : -1;
    int err = dx - dy;

    int cx = x, cy = y;
    while (true) {
        if (cx >= 0 && cx < WIDTH && cy >= 0 && cy < HEIGHT)
            canvas[cy][cx] = '*';
        if (cx == x2 && cy == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; cx += sx; }
        if (e2 < dx) { err += dx; cy += sy; }
    }

    // Recursive branches (left + right)
    drawTree(x2, y2, length * 0.7, angle + M_PI / 6, depth - 1);
    drawTree(x2, y2, length * 0.7, angle - M_PI / 6, depth - 1);
}

// Function to print canvas
void printCanvas() {
    for (auto& row : canvas)
        cout << row << "\n";
}

int main() {
    cout << "🌳 Hacktoberfest 2025 - The Fractal Tree 🌳\n";
    cout << "-------------------------------------------\n";

    int startX = WIDTH / 2;
    int startY = HEIGHT - 1;

    drawTree(startX, startY, 12, M_PI / 2, 8); // trunk up, recursive depth 8
    printCanvas();

    cout << "\n✨ A symbol of growth — just like your Hacktoberfest journey! ✨\n";
    return 0;
}
