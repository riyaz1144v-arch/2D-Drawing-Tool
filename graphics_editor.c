#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int row, int col, int width, int height)
{
    int i;

    for(i = col; i < col + width && i < COLS; i++)
    {
        if(row >= 0 && row < ROWS)
            canvas[row][i] = '*';

        if(row + height - 1 >= 0 && row + height - 1 < ROWS)
            canvas[row + height - 1][i] = '*';
    }

    for(i = row; i < row + height && i < ROWS; i++)
    {
        if(col >= 0 && col < COLS)
            canvas[i][col] = '*';

        if(col + width - 1 >= 0 && col + width - 1 < COLS)
            canvas[i][col + width - 1] = '*';
    }
}

void drawLine(int row, int col, int length)
{
    int i;

    for(i = 0; i < length && col + i < COLS; i++)
    {
        canvas[row][col + i] = '-';
    }
}

void drawCircle(int row, int col)
{
    if(row > 0 && row < ROWS - 1 && col > 0 && col < COLS - 1)
    {
        canvas[row][col] = 'O';
        canvas[row-1][col] = 'O';
        canvas[row+1][col] = 'O';
        canvas[row][col-1] = 'O';
        canvas[row][col+1] = 'O';
    }
}

void drawTriangle(int row, int col)
{
    if(row + 2 < ROWS && col + 2 < COLS)
    {
        canvas[row][col+1] = '^';
        canvas[row+1][col] = '^';
        canvas[row+1][col+2] = '^';

        canvas[row+2][col] = '^';
        canvas[row+2][col+1] = '^';
        canvas[row+2][col+2] = '^';
    }
}

void deleteObject(int row, int col)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        canvas[row][col] = '_';
    }
}

void modifyObject(int row, int col, char ch)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        canvas[row][col] = ch;
    }
}

int main()
{
    int choice;
    int row, col, width, height, length;
    char ch;

    initCanvas();

    while(1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Display Canvas\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Line\n");
        printf("4. Draw Circle\n");
        printf("5. Draw Triangle\n");
        printf("6. Delete Object\n");
        printf("7. Modify Object\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayCanvas();
                break;

            case 2:
                printf("Enter row col width height: ");
                scanf("%d%d%d%d", &row, &col, &width, &height);
                drawRectangle(row, col, width, height);
                break;

            case 3:
                printf("Enter row col length: ");
                scanf("%d%d%d", &row, &col, &length);
                drawLine(row, col, length);
                break;

            case 4:
                printf("Enter center row col: ");
                scanf("%d%d", &row, &col);
                drawCircle(row, col);
                break;

            case 5:
                printf("Enter row col: ");
                scanf("%d%d", &row, &col);
                drawTriangle(row, col);
                break;

            case 6:
                printf("Enter row col to delete: ");
                scanf("%d%d", &row, &col);
                deleteObject(row, col);
                break;

            case 7:
                printf("Enter row col and new character: ");
                scanf("%d%d %c", &row, &col, &ch);
                modifyObject(row, col, ch);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
