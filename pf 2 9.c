#include <stdio.h>

#define SIZE 5

void displayGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    
    int playerX = 4, playerY = 4; // Player starts at (4, 4)
    char move;
    int itemsCollected = 0;

    while (1) {
        displayGrid(grid);
        printf("Items collected: %d\n", itemsCollected);
        printf("Enter your move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        if (move == 'Q' || move == 'q') {
            break;
        }

        int newX = playerX;
        int newY = playerY;

        if (move == 'W' || move == 'w') newX--;
        else if (move == 'S' || move == 's') newX++;
        else if (move == 'A' || move == 'a') newY--;
        else if (move == 'D' || move == 'd') newY++;
        else {
            printf("Invalid move! Please use W, A, S, D or Q.\n");
            continue;
        }

        if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
            printf("Invalid move! You can't move outside the grid.\n");
            continue;
        }

        if (grid[newX][newY] == 'X') {
            printf("You hit an obstacle! You can't move there.\n");
            continue;
        }

        if (grid[newX][newY] == 'I') {
            itemsCollected++;
            printf("You collected an item!\n");
        }

        grid[playerX][playerY] = ' '; // Clear the old position
        grid[newX][newY] = 'P'; // Move the player to the new position
        playerX = newX;
        playerY = newY;
    }

    printf("Thank you for playing!\n");
    return 0;
}