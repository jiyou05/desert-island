#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <map>
#include <list>
#include <string>

#include "storylib.h"
#include "story.h"
#include "util.h"

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

// 키보드 키의 아스키 코드 값
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define SPACE 32

// 게임맵의 크기
#define MAP_SIZE_X 60
#define MAP_SIZE_Y 30

using namespace std;

// 전역변수
extern status M;    // 상태
extern inventory I; // 인벤토리

void print_menu();
void set_map();
void print_map();
void map_init();



// 커서 위치 구조체
typedef struct cursor_position
{
    int x;
    int y;
} POS;

// 커서 위치 범위 구조체
typedef struct cursor_position_bound
{
    int x_min;
    int x_max;
    int y_min;
    int y_max;
}POS_BOUND;

// 맵에서 커서(@)를 움직일 수 있는 범위
POS_BOUND map_bound = { 1, MAP_SIZE_X-2, 1, MAP_SIZE_Y-2 };
POS_BOUND* p_map_bound = &map_bound;
// 인벤토리에서 커서(>)를 움직일 수 있는 범위
POS_BOUND inventory_bound = { -1, 1, 2, 6 };
POS_BOUND* p_inventory_bound = &inventory_bound;

// 커서를 상하좌우로 움직이는 함수
// p_pos: 현재 커서 위치, p_bound: 커서 범위, key: 키보드 키, object: 이동할 문자
void move_cursor(POS* p_pos, POS_BOUND* p_bound, int key, char object)
{
    int delta_x; // x 변화량
    int delta_y; // y 변화량

    // 기존 위치의 플레이어를 지운다
    gotoxy(p_pos->x, p_pos->y);
    printf("  ");

    switch (key)
    {
    case UP: 
        if (p_pos->y > p_bound->y_min) // 커서의 y 위치가 범위내에 있다면
            p_pos->y--; // 위치를 변화시킨다
        break;
    case DOWN:
        if (p_pos->y < p_bound->y_max) 
            p_pos->y++; 
        break;
    case LEFT:
        if (p_pos->x > p_bound->x_min) 
            p_pos->x--; 
        break;
    case RIGHT:
        if (p_pos->x < p_bound->x_max) 
            p_pos->x++;
        break;
    }
    //새로운 위치에 플레이어를 출력한다
    gotoxy(p_pos->x, p_pos->y);
    printf("%c", object);
}

void print_status()
{
    cursor_visible(false);
    setColor(red, black);
    printf("[ 배고픔 ]");
    setColor(white, black);
    printf("은 최대값이 100이며, 10까지 내려가면 쓰러집니다. \n");
    setColor(red, black);
    printf("[ 체온 ]");
    setColor(white, black);
    printf("은 정상 체온이 36, 최대값이 40이며 이에 도달하면 죽고 32까지 내려가도 죽습니다. \n");

    gotoxy(0, 20);
    printf("종료하려면 [esc]를 누르세요");
}

void print_inventory()
{
    cursor_visible(true);
    setColor(white, black);

    POS pos = { 0, 2 };

    // 위에서부터 순서대로 아이템 목록을 출력한다.
    gotoxy(pos.x, pos.y); // -2 한 이유는 > 를 출력해야하기 때문에  
    setColor(green, black);
    printf("> [부싯돌]");
    setColor(white, black);
    printf(" : 주변에 굴러다리는 평범한 돌. 이걸로 불을 피울 수 있을까?\n\n");
    gotoxy(pos.x+2, pos.y + 1);
    setColor(green, black);
    printf("[안경]");
    setColor(white, black);
    printf(" : 눈이 나빠 돋보기 안경을 쓴다. 닦은지 오래되어 뿌옇게 보인다. \n\n");
    gotoxy(pos.x+2, pos.y + 2);
    setColor(green, black);
    printf("[동전]");
    setColor(white, black);
    printf(" : 주머니에 굴러다니는 동전 몇 개. 총 300원 있다. \n\n");
    gotoxy(pos.x+2, pos.y + 3);
    setColor(green, black);
    printf("[바나나]");
    setColor(white, black);
    printf(" : 옆에 있는 나무에서 따온 바나나. 평범하다. \n\n");
    gotoxy(pos.x+2, pos.y + 4);
    setColor(green, black);
    printf("[자몽]");
    setColor(white, black);
    printf(" : 옆에 있는 나무에서 따온 자몽. 난 자몽을 싫어한다. \n");



    gotoxy(pos.x, pos.y + 5);
    printf("아이템을 사용하려면 [space]를 누르세요");
    gotoxy(0, 20);
    printf("종료하려면 [esc]를 누르세요");

    gotoxy(pos.x - 2, pos.y);
    pos = { 0, 2 };
    POS* p_inventory_pos = &pos;
    while (1)
    {
        if (kbhit())
        {
            int key = getch(); // 입력받은 키의 아스키 코드 값을 저장한다
            if (key == 224) // 키가 방향키라면
            {
                int sub_key = getch();
                if (sub_key == UP || sub_key == DOWN)
                    move_cursor(p_inventory_pos, p_inventory_bound, sub_key, '>');
            }

            else if (key == ESC)
                return;
            else if (key == SPACE)
            {
                string storyKey = buildStoryKey(); // 현재 스토리 이름을 저장한다
                if (pos.y == 2) // 부싯돌을 사용했을 때,
                {
                    if (find(I.firestone.begin(), I.firestone.end(), storyKey) != I.firestone.end()) // I.firestone 리스트에 현재 스토리가 있다면,
                    {
                        if (storyKey == "2") // 현재 스토리가 2이라면,
                        {
                            rebuildStoryPath(list<char>{'2', '1'});
                            //callStoryFunc(); // 스토리 2_1을 호출한다
                            return;
                        }
                    }
                    else
                    {
                        gotoxy(pos.x, pos.y + 6);
                        printf("아이템을 사용할 수 없습니다.");
                    }
                }
                else if (pos.y == 3) // 안경을 사용했을 때,
                {
                    if (find(I.glasses.begin(), I.glasses.end(), storyKey) != I.glasses.end()) // I.glasses 리스트에 현재 스토리가 있다면,
                    {
                        if (storyKey == "2") // 현재 스토리가 2이라면,
                        {
                            rebuildStoryPath(list<char>{'2', '2'}); 
                            //callStoryFunc(); // 스토리 2_2를 호출한다
                            return;
                        }
                        else
                        {
                            printf("아이템을 사용할 수 없습니다.");
                        }
                    }
                }
                    else if (pos.y == 4) // 동전을 사용했을 때,
                    {
                        if (find(I.coin.begin(), I.coin.end(), storyKey) != I.coin.end()) // I.coin 리스트에 현재 스토리가 있다면,
                        {
                            printf("아이템을 사용할 수 있습니다.");
                        }
                        else
                        {
                            printf("아이템을 사용할 수 없습니다.");
                        }
                    }
                    else if (pos.y == 5) // 바나나를 사용했을 때,
                    {
                        if (find(I.banana.begin(), I.banana.end(), storyKey) != I.banana.end()) // I.banana 리스트에 현재 스토리가 있다면,
                        {
                            if (storyKey == "1_1") // 현재 스토리가 1_1이라면,
                            {
                                rebuildStoryPath(list<char>{'1', '1', '1'});
                                //callStoryFunc(); // 스토리 1_1_1를 호출한다
                                return;
                            }
                        }
                        else
                        {
                            printf("아이템을 사용할 수 없습니다.");
                        }
                    }
                    else if (pos.y == 6) // 자몽을 사용했을 때, 
                    {
                        if (find(I.grapefruit.begin(), I.grapefruit.end(), storyKey) != I.grapefruit.end()) // I.grapefruit 리스트에 현재 스토리가 있다면,
                        {
                            if (storyKey == "1_1") // 현재 스토리가 1_1이라면,
                            {
                                rebuildStoryPath(list<char>{'1', '1', '2'});
                                //callStoryFunc(); // 스토리 1_1_2를 호출한다
                                return;
                            }
                        }
                        else
                        {
                            printf("아이템을 사용할 수 없습니다.");
                        }
                    }
                }


            }

        }
    }

// map에서 키보드로 입력을 받았을 때 실행하는 함수
void key_map(POS* p_map_pos)
{
    int key = getch(); // 입력받은 키의 아스키 코드 값을 저장한다
    if (key == 224)
    {
        int sub_key = getch();
        move_cursor(p_map_pos, p_map_bound, sub_key, '@');
    }

    else
    {
        switch (key)
        {
        case 0:
            break;
        case ESC:
            system("cls");
            map_init();
            break;

        case 's':
        case 'S':
            system("cls");
            print_status();
            break;
        case 'i':
        case 'I':
            system("cls");
            print_inventory();
            break;
        }
        key = 0;
    }
}


void map_init() // 프로그램 실행 후 초기화
{
    system("cls");
    set_map();
    print_map();
    gotoxy(30, 13); // 플레이어 위치지정
    printf("@");    // 플레이어 출력
}

/*
    키를 입력받아 스토리를 진행
*/
void loop_story()
{   
    system("cls");
    list<char> options = callStoryFunc();
   
    while (1)
    {
        if (kbhit())
        {
            int key = getch(); // 입력받은 키의 아스키 코드 값을 저장한다
            switch (key)
            {
            case 0:
                break;
            case ESC:
                options = callStoryFunc();
                break;

            case 's':
            case 'S':
                system("cls");
                print_status();
                break;
            case 'i':
            case 'I':
                system("cls");
                print_inventory();
                options = callStoryFunc();                
                break;
            default:
                // 선택 옵션 i
                if (find(options.begin(), options.end(), (char)key) != options.end())
                {
                    pushStoryPath((char)key);
                    options = callStoryFunc(); // 스토리 함수를 호출하고 다음 스토리 선택지를 지정
                }
                break;
            }
            key = 0;
        }
    }
}

int temp1 = 0;

void loop_map(POS* p_map_pos)
{
    while (1)
    {
        // 조건 1
        if (p_map_pos->x == 30 && p_map_pos->y == 15 && temp1 == 0)
        {
            temp1++;
            system("cls");
            return;
        }

        else if (kbhit())
        {
            key_map(p_map_pos);
        }
    }
}



int main()
{
    init();
    print_menu();
    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }
    map_init();
    story_init();

    POS map_current_pos;
    map_current_pos.x = 30;
    map_current_pos.y = 13;
    POS* p_map_pos = &map_current_pos;
    while (1)
    {
        loop_map(p_map_pos);
        loop_story();
        print_map();
        gotoxy(map_current_pos.x, map_current_pos.y);
        printf("@");
    }

    return 0;
}

int map_game[MAP_SIZE_Y][MAP_SIZE_X] = {};

void print_menu()
{
    printf(" -----------------------------------------------\n");
    printf("|                                               |\n");
    printf("|");
    setColor(yellow, black);
    printf("              무인도 ");
    setColor(white, black);
    printf("에서 살아남기             | \n");
    printf("|                                               |\n");
    printf("|             press 1 key to start              |\n");
    printf(" -----------------------------------------------\n");

}
void set_map()
{
    for (int i = 0; i < MAP_SIZE_Y; i++)
    {
        for (int j = 0; j < MAP_SIZE_X; j++)
        {
            if (i == 0 || i == MAP_SIZE_Y-1 || j == 0 || j == MAP_SIZE_X-1)
                map_game[i][j] = 1;
            else
                map_game[i][j] == 0;
        }
    }
}

void print_map()
{
    for (int i = 0; i < MAP_SIZE_Y; i++)
    {
        for (int j = 0; j < MAP_SIZE_X; j++)
        {
           int type = map_game[i][j];
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
