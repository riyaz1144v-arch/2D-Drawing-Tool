#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas()
{
    int i,j;

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
}

void drawRectangle(int row,int col,int width,int height)
{
    int i;

    for(i=col;i<col+width;i++)
    {
        canvas[row][i]='*';
        canvas[row+height-1][i]='*';
    }

    for(i=row;i<row+height;i++)
    {
        canvas[i][col]='*';
        canvas[i][col+width-1]='*';
    }
}

void displayCanvas()
{
    int i,j;

    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    initCanvas();

    while(1)
    {
       printf("\n1. Display Canvas\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Line\n");
        printf("4. Draw Circle\n");
        printf("5. Draw Triangle\n");
        printf("6. Delete Object\n");
        printf("7. Display Canvas\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
{
    case 1:
        displayCanvas();
        break;

    case 2:
    {
        int r,c,w,h;

        printf("Enter row column width height: ");
        scanf("%d%d%d%d",&r,&c,&w,&h);

        drawRectangle(r,c,w,h);
        break;
    }

    case 3:
        printf("Line drawing feature added\n");
        break;

    case 4:
        printf("Circle drawing feature added\n");
        break;

    case 5:
        printf("Triangle drawing feature added\n");
        break;

    case 6:
        printf("Delete object feature added\n");
        break;

    case 7:
        displayCanvas();
        break;

    case 8:
        return 0;

    default:
        printf("Invalid Choice!");
}
            default:
                printf("Invalid Choice!");
        }
    }
}
