#include <stdio.h>
#include "util.h"
#include "design.h"

int UI_boundary[UI_SIZE_Y][UI_SIZE_X] = {};

void set_UI()
{
    for (int i = 0; i < UI_SIZE_Y; i++)
    {
        for (int j = 0; j < UI_SIZE_X; j++)
        {
            if (i == 0 || i == UI_SIZE_Y - 1 || j == 0 || j == UI_SIZE_X - 1)
                UI_boundary[i][j] = 1;
            else
                UI_boundary[i][j] == 0;
        }
    }
}

void print_UI()
{
    set_UI();
    gotoxy(0, 32);
    setColor(yellow, black);
    for (int i = 0; i < UI_SIZE_Y; i++)
    {
        for (int j = 0; j < UI_SIZE_X; j++)
        {
            int type = UI_boundary[i][j];
            switch (type)
            {
            case 1:
                printf("=");
                break;
            case 0:
                printf(" ");
                break;
            }
        }
        printf("\n");
    }

    gotoxy(0, 0);
}



int map_boundary[MAP_SIZE_Y][MAP_SIZE_X] = {};

void set_map()
{
    for (int i = 0; i < MAP_SIZE_Y; i++)
    {
        for (int j = 0; j < MAP_SIZE_X; j++)
        {
            if (i == 0 || i == MAP_SIZE_Y - 1 || j == 0 || j == MAP_SIZE_X - 1)
                map_boundary[i][j] = 1;
            else
                map_boundary[i][j] == 0;
        }
    }
}

void print_map()
{
    set_map();
    for (int i = 0; i < MAP_SIZE_Y; i++)
    {
        for (int j = 0; j < MAP_SIZE_X; j++)
        {
            int type = map_boundary[i][j];
            switch (type)
            {
            case 1:
                printf("#");
                break;
            case 0:
                printf(" ");
                break;
            }
        }
        printf("\n");
    }
}