#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime> // srand 함수의 시드

#include "util.h"
#include "storylib.h"
#include "story.h"


#define SLEEP_TIME 0
#define SLEEP_TIME2 10

using namespace std;

int totalscore = 100;
int bunnycatch = 0;

extern status M;      // 상태   - 외부 전역변수 참조

/*
   스토리 함수와 키를 매핑하여 초기화
*/
void story_init()
{
    addStory(string("intro"), story_intro);
    addStory(string("begin"), story_begin);
    addStory(string("1"), story1);
    addStory(string("1_1"), story1_1);
    addStory(string("1_2"), story1_2);
    addStory(string("1_1_1"), story1_1_1);
    addStory(string("1_1_2"), story1_1_2);
    addStory(string("1_2_1"), story1_2_1);
    addStory(string("1_2_1_1"), story1_2_1_1);
    addStory(string("1_2_1_2"), story1_2_1_2);
    addStory(string("1_2_2"), story1_2_2);

    addStory(string("2"), story2);
    addStory(string("2_1"), story2_1);
    addStory(string("2_2"), story2_2);

    addStory(string("3"), story3);
    addStory(string("3_1"), story3_1);
    addStory(string("3_1_m"), story3_1_m);
    addStory(string("3_1_m_0"), story3_1_m_0);
    addStory(string("3_1_m_1"), story3_1_m_1);
    addStory(string("3_1_m_2"), story3_1_m_2);
    addStory(string("3_1_m_3"), story3_1_m_3);

    addStory(string("3_1_e"), story3_1_e);
    addStory(string("3_1_e_1"), story3_1_e_1);
    addStory(string("3_1_e_1_1"), story3_1_e_1_1);
    addStory(string("3_1_e_1_2"), story3_1_e_1_2);
    addStory(string("3_1_e_2"), story3_1_e_2);

    addStory(string("3_2"), story3_2);
    addStory(string("3_2_1"), story3_2_1);
    addStory(string("3_2_1_1"), story3_2_1_1);
    addStory(string("3_2_1_2"), story3_2_1_2);
    addStory(string("3_2_2"), story3_2_2);
    addStory(string("3_2_e_1"), story3_2_e_1);

    addStory(string("3_3"), story3_3);
    addStory(string("3_3_m"), story3_3_m);

    addStory(string("3_3_e_1"), story3_3_e_1);
    addStory(string("3_3_e_2"), story3_3_e_2);


}

int cntintro = 0;
int cntbegin = 0;
int cnt1 = 0;
int cnt1_1 = 0;
int cnt1_1_1 = 0;
int cnt1_1_2 = 0;
int cnt1_2 = 0;
int cnt1_2_1 = 0;
int cnt1_2_1_1 = 0;
int cnt1_2_1_2 = 0;
int cnt1_2_2 = 0;
int cnt2 = 0;
int cnt2_1 = 0;
int cnt2_2 = 0;
int cnt3 = 0;
int cnt3_1 = 0;
int cnt3_1_m = 0;
int cnt3_1_e = 0;
int cnt3_1_e_1 = 0;
int cnt3_1_e_1_1 = 0;
int cnt3_1_e_1_1_1 = 0;
int cnt3_1_e_1_2 = 0;
int cnt3_1_e_2 = 0;
int cnt3_2 = 0;
int cnt3_2_1 = 0;
int cnt3_2_1_1 = 0;
int cnt3_2_1_2 = 0;
int cnt3_2_2 = 0;
int cnt3_2_e_1 = 0;
int cnt3_3 = 0;
int cnt3_3_m = 0;
int cnt3_3_m_3_3_e_1 = 0;
int cnt3_3_m_3_3_e_2 = 0;

int cnt3_1_e_1_1_2 = 0;
int cnt3_3_2 = 0;
int cnt3_3_1 = 0;


void scriptEx(string script)
{
    for (int i = 0; i < script.length(); i++)
    {
        printf("%c", script[i]);
            Sleep(SLEEP_TIME2);
    }
}

void scriptEx(string script, int cnt)
{
    for (int i = 0; i < script.length(); i++)
    {
        printf("%c", script[i]);
        if (cnt == 0)
            Sleep(SLEEP_TIME2);
    }

    if (cnt == 0)
        Sleep(SLEEP_TIME);
}

list<char> story_intro()
{
    string script1 = "이 게임은 플레이어의 선택에 따라 스토리가 좌우됩니다. \n\n";
    scriptEx(script1, cntintro);
    string script2 = "신중하게 선택하여 플레이하시길 바랍니다. \n\n";
    scriptEx(script2, cntintro);
    cntintro++;

    return list<char>{};
}

list<char> story_begin()
{
    string script1 = "갈매기 소리와 함께 눈을 떴다.\n\n";
    scriptEx(script1, cntbegin);
    string script2 = "손가락을 꿈틀거리며 천천히 일어났는데, 이런... 옷이 다 젖었다. \n\n";
    scriptEx(script2, cntbegin);

    printf("1. 옷을 나무에 걸어 잠시 말려둔다. \n");
    printf("2. 옷을 말리지 않는다. \n\n");
    cntbegin++;

    return list<char>{'1', '2'};
}

list <char> story1()
{
    string script1 = "원숭이가 내 옷을 가져갔다! \n\n";
    scriptEx(script1, cnt1);
    string script2 = "어서 서두르지 않으면 내 옷이 사라진다! \n\n";
    scriptEx(script2, cnt1);

    printf("1. 그래도 돌은 좀... 망성여진다...원숭이를 달래보자. \n");
    printf("2. 원숭이쯤이야 그냥 던져! 덤비면 싸워서 가져오지 뭐! \n\n");
    cnt1++;

    return list<char>{'1', '2'};
}



list<char> story1_1()
{
    string script1 = "주변을 둘러보니 생각보다 먹을 것을 많이 갖춘 섬이다. \n\n";
    scriptEx(script1, cnt1_1);
    string script2 = "탐스럽게 열린 열매와 과일들이 보인다. \n가까이 다가가니 바나나와 자몽이 보인다. \n\n";
    scriptEx(script2, cnt1_1);
    string script3 = "내가 가진 것들 중 하나를 활용해보자. \n";
    scriptEx(script3, cnt1_1);
    cnt1_1++;

    return list<char>{};
}

list<char> story1_1_1() // 인벤토리에서 바나나 사용
{
    string script1 = "원숭이에게 조심스럽게 바나나를 건넸다. \n\n";
    scriptEx(script1, cnt1_1_1);
    Sleep(1000);
    string script2 = "아니 이걸 거부한다고? 혼종인가 보다. \n\n";
    scriptEx(script2, cnt1_1_1);
    M.Hp -= 10; //Hp 하강
    string script3 = "옷을 얻지 못했고, 너무 춥다. \n\n";
    scriptEx(script3, cnt1_1_1);
    cnt1_1_1++;

    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char> story1_1_2() // 인벤토리에서 자몽 사용
{
    string script1 = "원숭이에게 조심스럽게 자몽을 건넸다. \n\n";
    scriptEx(script1, cnt1_1_2);
    Sleep(1000);
    string script2 = "원숭이가 옷을 돌려주었다!\n\n";
    scriptEx(script2, cnt1_1_2);
    string script3 = "다행히 옷은 멀쩡하다. 앞으로는 잘 간수하도록 하자. \n\n";
    cnt1_1_2++;

    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char>story1_2() //싸우는 경우
{
    M.Hp -= 10;
    string script1 = "막상 싸우려니 조금은 막막하다. \n\n"; 
    scriptEx(script1, cnt1_2);
    string script2 = "원숭이와 두 눈을 마주한지 몇 초 가량 흘렀다. \n\n";
    scriptEx(script2, cnt1_2);
    string script3 = "이게 뭐라고 식은땀이 흐를 일인가...나의 행동을 신중히해야겠다. \n\n\n";
    scriptEx(script3, cnt1_2);
    string script4 = "갑자기 원숭이가 도망간다! 이대로 도망가면 옷을 잃는다! \n\n";
    scriptEx(script4, cnt1_2);
    cnt1_2++;

    printf("1. 바닥에 굴러다니는 돌 아무거나 주워서 일단 던져보자. \n");
    printf("2. 아니다 이건 잡아야 한다! 원숭이를 쫓아간다! \n");

    return list<char>{'1', '2'};
}

list<char> story1_2_1() //돌 던지는 경우
{
    string script1 = "몇 번 던져보았는데 하나도 맞지 않다니... \n\n";
    scriptEx(script1, cnt1_2_1);
    string script2 = "마지막 시도... 조금 더 신중히 던져보자... \n\n";
    scriptEx(script2, cnt1_2_1);
    cnt1_2_1++;

    printf("1. 돌을 왼쪽으로 던진다. \n");
    printf("2. 돌을 오른쪽으로 던진다. \n");

    return list<char>{'1', '2'};
}

list<char> story1_2_1_1() //왼쪽으로 던진 경우
{
    string script1 = "오! 이걸 맞추다니! \n\n원숭이가 드디어 돌을 맞고 쓰러졌다! \n\n";
    scriptEx(script1, cnt1_2_1_1);
    Sleep(SLEEP_TIME);
    string script2 = "뭔가 이상하다...어디선가 무리지어 달려오는 소리가 들린다. \n\n";
    scriptEx(script2, cnt1_2_1_1);
    cnt1_2_1_1++;

    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n\n\n");
    Sleep(SLEEP_TIME);

    setColor(red, black); //빨간색 검정색
    printf("원숭이 군단에 의해 사망하였습니다.\n");
    setColor(white, black);
    Sleep(SLEEP_TIME); //흰색 검정색
    printf("리스폰 하려면 1을 누르시오. \n\n");

    /*
    int respawn;
    scanf("%d", &respawn);
    if (respawn == 1)
    {
        popStoryPath();
        return story1_2_1();
    }
    */
    //아닐 때는 어떻게 하지?

    totalscore -= 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }

    popStoryPath();
    popStoryPath();

    return callStoryFunc();
}

list <char> story1_2_1_2() //오른쪽으로 던진 경우
{
    string script1 = "또 맞추지 못하였다.\n\n";
    scriptEx(script1, cnt1_2_1_2);
    M.Hp -= 10;
    string script2 = "옷을 얻지 못했고, 너무 춥다...피곤하고 배고프다...\n\n";
    scriptEx(script2, cnt1_2_1_2);
    cnt1_2_1_2++;

    Sleep(SLEEP_TIME);
    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char> story1_2_2() //쫓아가는 경우
{
    string script1 = "헉..헉..헉... \n\n";
    scriptEx(script1, cnt1_2_2);
    M.Hp -= 10;
    string script2 = "원숭이를 잡지 못하였다. 체력 소모가 너무 컸나보다... 배가 고프다. \n\n";
    scriptEx(script2, cnt1_2_2);
    cnt1_2_2++;

    Sleep(SLEEP_TIME);
    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}

list<char> story2() //옷을 말리지 못하는 경우
{
    M.Hp -= 20;
    string script1 = "옷을 말리지 못해 너무 춥다. \n\n";
    scriptEx(script1, cnt2);
    string script2 = "어두워지면 체온도 더 떨어질 것 같다. \n체온 유지를 위해 어서 불이라도 피워야 할 것 같다. \n\n";
    scriptEx(script2, cnt2);
    string script3 = "내가 가진 것들 중 하나를 활용해보자. \n";
    scriptEx(script3, cnt2);
    cnt2++;

    return list<char>{};
}

list<char> story2_1() // 인벤토리에서 부싯돌 사용
{
    string script1 = "주변에 부싯돌로 쓸만한 돌이 조금 보인다. \n";
    scriptEx(script1, cnt2_1);
    string script2 = "생각보다 부싯돌로 불을 붙이는 건 쉬운 일이 아니다.\n\n";
    scriptEx(script2, cnt2_1);
    string script3 = "덜...덜...덜... 너무 춥다... 이대로...\n";
    scriptEx(script3, cnt2_1);
    cnt2_1++;

    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);
    printf(".\n\n\n");
    Sleep(500);

    setColor(11, 0); //민트색 검정색
    printf("추위에 의해 저체온증으로 사망하였습니다.\n");
    setColor(white, black); //흰색 검정색
    Sleep(SLEEP_TIME);
    printf("리스폰 하려면 1을 누르시오. \n\n");
    /*
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        story1_2_1();
    }
    */
    //아닐 때는 어떻게 하지?

    totalscore -= 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }

    popStoryPath();
    system("cls");
    return story2();
}

list<char> story2_2() // 인벤토리에서 안경 사용
{
    M.Hp += 10;
    string script1 = "불을 붙이는 데 성공하였다. \n\n";
    scriptEx(script1, cnt2_2);
    string script2 = "몸이 따뜻해지니 배가 고파지기 시작한다. \n\n";
    scriptEx(script2, cnt2_2);

    Sleep(SLEEP_TIME);
    rebuildStoryPath(list<char>{'3'});

    return callStoryFunc();
}


list<char> story3()
{
    string script1 = "체력이 더 떨어지기 전에 빨리 먹을 것을 구해야겠다. \n\n";
    scriptEx(script1, cnt3);
    string script2 = "이동할 수 있을만한 장소가 총 3개 정도 보인다. \n\n";
    scriptEx(script2, cnt3);
    cnt3++;

    printf("1. 물고기가 파닥파닥 바다로 이동해본다. \n");
    printf("2. 저 높이 보이는 폭포 아래 있을 법한 강으로 이동해본다. \n");
    printf("3. 짐승들이 숨어있을 법한 밀집한 숲으로 이동해본다. \n");

    return list<char>{'1', '2', '3'};
}

list<char> story3_1()
{
    int x;
    string script1 = "어느새 바다로 왔다. 드넓은 바다를 보니 과연 이 곳을 빠져나갈 수 있을지 막막하다. \n";
    scriptEx(script1, cnt3_1);
    string script2 = "바닷물 아래 물고기로 추정되는 그림자들이 지나가는 것이 보인다. \n\n";
    scriptEx(script2, cnt3_1);
    string script3 = "모래사장 근처 떨어진 낡은 낚시대가 보인다. \n\n";
    scriptEx(script3, cnt3_1);
    string script4 = "어서 물고기를 잡아보자!\n\n\n";
    scriptEx(script4, cnt3_1);
    cnt3_1++;

    setColor(yellow, black);
    printf("----------------물고기를 잡아라! minigame 튜토리얼----------------\n\n");
    printf("제시되는 다섯 개의 숫자 1, 2, 3, 4, 5 중 하나를 랜덤으로 선택한다. \n");
    Sleep(SLEEP_TIME);
    printf("    5개의 숫자 중 어떤 물고기, 혹은 어떤 결과가 나올지는 모른다. \n");
    Sleep(SLEEP_TIME);
    printf("                    그럼, 행운을 빈다. \n\n");
    printf("-------------------------------------------------------------------\n\n");

    Sleep(2000);
    printf("계속하려면 1을 누르시오. \n\n");
    setColor(white, black);
    /*
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        story1_2_1();
    }
    */
    //아닐 때는 어떻게 하지?

    totalscore -= 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }
 
    pushStoryPath('m');
    return callStoryFunc();
}

int cnt_jellyfish = 0; // 해파리를 낚는 횟수

list<char> story3_1_m() //물고기 미니게임
{
    string script1 = "1    2    3    4    5 \n\n";
    scriptEx(script1, cnt3_1_m);
    cnt3_1_m++;


    int key = pressedKey();
    if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5')
    {
        char random = NULL;
        srand((unsigned int)time(NULL));  // seed값으로 현재 시간 부여
        random = rand() % 4 + '0'; // 난수 범위 '0'~'3'으로 한정
        while (random == '0' && cnt_jellyfish != 0) // 해파리를 낚을 때 이미 이전에 한 번 이상 낚았다면 난수를 다시 생성한다
            random = rand() % 4 + '0';
        pushStoryPath(random);

    }
    return callStoryFunc();

}



int cnt_fish[4] = { 0, 2, 2, 2 }; // 스토리 반복 횟수-1

list<char> story3_1_m_0()
{
    string script1 = "해파리를 낚아버렸다! 으악! \n\n\n";
    scriptEx(script1);

    setColor(yellow, black);
    printf("해파리에 의해 감전당해 사망하였습니다. \n\n");

    totalscore -= 100;
    cnt_jellyfish++;

    popStoryPath();
    popStoryPath();
    popStoryPath();
    return callStoryFunc();
}

list<char> story3_1_m_1()
{
    string script1 = "응? 왜 낚시줄에 돌멩이가 이끌려 나오지..? 내 실력이 부끄럽다. \n";
    scriptEx(script1);
    M.Hp -= 10;

    while (cnt_fish[1]--) // 물고기를 잡은 횟수가 2번 이하이면
    {
        // 물고기 미니게임을 다시 한다
        popStoryPath(); 
        return callStoryFunc();

    }
    

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_m_2()
{
    string script1 = "넙치를 낚았다! 이걸로 끼니 해결은 가능하겠군! \n";
    scriptEx(script1);
    M.Hp += 5;

    while (cnt_fish[1]--) // 물고기를 잡은 횟수가 2번 이하이면
    {
        // 물고기 미니게임을 다시 한다
        popStoryPath();
        return callStoryFunc();

    }

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}



list<char> story3_1_m_3()
{
    string script1 = "송어를 낚았다! 이걸로 끼니 해결은 가능하겠군! \n\n\n";
    scriptEx(script1);
    M.Hp += 10;

    while (cnt_fish[1]--) // 물고기를 잡은 횟수가 2번 이하이면
    {
        // 물고기 미니게임을 다시 한다
        popStoryPath();
        return callStoryFunc();

    }

    rebuildStoryPath(list<char>{'3', '1', 'e'});
    return callStoryFunc();
}

list<char> story3_1_e()
{
    string script1 = "바다 주변을 조금씩 걸으며 내가 필요한 것들을 주웠다. \n\n";
    scriptEx(script1, cnt3_1_e_1);
    string script2 = "빈 캔, 녹슨 철제, 다 헤진 그물망... \n\n";
    scriptEx(script2, cnt3_1_e_1);
    string script3 = "잠깐...\n";
    scriptEx(script3, cnt3_1_e_1);
    string script4 = "잠깐...\n\n";
    scriptEx(script4, cnt3_1_e_1);
    string script5 = "저기 모래사장 근처 뗏목이 희미하게 보였다. \n\n";
    scriptEx(script5, cnt3_1_e_1);
    string script6 = "가까이 다가가니 뗏목이 확실했다. 상태가 많이 좋지는 않았지만 그래도 쓸만해 보였다. \n\n";
    scriptEx(script6, cnt3_1_e_1);
    string script7 = "이런 뗏목이 그냥 섬에 무작위하게 널려있을리가 없다. \n\n";
    scriptEx(script7, cnt3_1_e_1);

    printf("1. 이 섬에 나와 같은 다른 누군가가 만든 것일 수 있다. 함부로 가져가서는 안된다. \n");
    printf("2. 누구 것이고 아닌게 어딨어? 지금 가져가는 사람이 임자다. 이 섬에 더 있다가는 내가 죽는다. \n");

    return list<char>{'1', '2'};
}

list<char> story3_1_e_1() //배 훔치지 않은 경우
{
    string script1 = "아쉬움을 한 가득 남긴채 뗏목을 그냥 두었다. \n\n";
    scriptEx(script1, cnt3_1_e_1_1);
    string script2 = "주인이 올 때까지 기다려보는 것도 방법이다. \n\n";
    scriptEx(script2, cnt3_1_e_1_1);
    string script3 = "뗏목에 앉아 주인을 하염없이 계속 기다렸다. \n\n";
    scriptEx(script3, cnt3_1_e_1_1);

    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");

    setColor(10, 0);
    string script4 = "[??] : 저기...저기...\n\n";
    scriptEx(script4, cnt3_1_e_1_1);
    setColor(white, black);
    string script5 = "누군가 나를 흔들어깨웠다. 눈을 깜빡거리면서 일어났다. \n\n";
    scriptEx(script5, cnt3_1_e_1_1);
    setColor(white, black);
    string script6 = "[??] : 이거 제 뗏목인데... \n\n";
    scriptEx(script6, cnt3_1_e_1_1);
    cnt3_1_e_1_1++;

    printf("1. 네, 저도 압니다! 혹시 같이 탈출하실 수...있을까요?\n");
    printf("2. 아닌데요? 이거 제가 만들었는데요? \n");

    return list<char>{'1', '2'};
}

list<char>story3_1_e_1_1() //함께 타고 가야하는 엔딩
{
    setColor(10, 0);
    string script1 = "[??] : 그럼 같이 가시죠! 빨리 탈출합시다! \n\n";
    scriptEx(script1, cnt3_1_e_1_1_1);
    setColor(white, black);
    string script2 = "그렇게 나는 그와 함께 뗏목을 타고 바다를 건너기 시작하였다. \n\n";
    scriptEx(script2, cnt3_1_e_1_1_1);
    string script3 = "오랜 시간 이동하면서 그가 가진 식량을 나눠먹었다. \n\n";
    scriptEx(script3, cnt3_1_e_1_1_1);
    string script4 = "뗏목을 타고 끝이 보이지 않는 바다를 항해하며 그 이가 어쩌다 이 섬에 갇혔는지도 듣게 되었다. \n\n";
    scriptEx(script4, cnt3_1_e_1_1_1);
    string script5 = "확실한 건. 난 정말 운이 좋은 것이라는 거다. \n\n";
    scriptEx(script5, cnt3_1_e_1_1_1);
    string script6 = "그가 뗏목까지 만들어야 했던 시간에 비하면 정말 빨리 이 섬을 탈출하게 되었으니...\n\n";
    scriptEx(script6, cnt3_1_e_1_1_1);


    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");
    Sleep(SLEEP_TIME);
    printf(".\n");

    string script7 = "긴 시간이 지났고 우리는 운이 좋게 구조 헬기를 발견했다. \n\n";
    scriptEx(script7, cnt3_1_e_1_1_1);
    string script8 = "열심히 구조요청을 한 끝에 너무나 다행히 우리는 안전히 구조되었고 \n";
    scriptEx(script8, cnt3_1_e_1_1_1);
    string script9 = "우리의 이야기는 뉴스 기사로 실리기도 하였다. \n\n";
    scriptEx(script9, cnt3_1_e_1_1_1);
    string script10 = "만약 내가 그 날 뗏목을 발견하지 않았더라면 과연 어떤 일이 일어났을지...\n\n\n";
    scriptEx(script1, cnt3_1_e_1_1_1);

    Sleep(SLEEP_TIME);

    string script11 = "별로 상상하고 싶지는 않다. \n";
    scriptEx(script11, cnt3_1_e_1_1_1);
    cnt3_1_e_1_1_1++;

    setColor(yellow, black);
    printf("다른 엔딩이 궁금하지 않으신가요? \n\n");
    printf("게임을 다시 플레이하여 여러 엔딩을 경험해보세요. \n\n");

    return list<char>{};
}

list<char>story3_1_e_1_2() //시치미 떼는 경우
{
    string script1 = "그가 나를 어의 없다는듯이 뚫어져라 쳐다봤다. \n\n";
    scriptEx(script1, cnt3_1_e_1_1_2);
    string script2 = "어서 수습해야 탈출할 수 있겠다고 느낀 나는 빠르게 사과하고 도와달라고 부탁하였다. \n\n";
    scriptEx(script2, cnt3_1_e_1_1_2);
    cnt3_1_e_1_1_2++;

    //return <char>story3_1_e_1_1();
    return story3_1_e_1_1();
}

list<char> story3_1_e_2() //배 훔쳐간 경우
{
    string script1 = "빠르게 뗏목을 출발시키기 위해 준비했다. \n\n";
    scriptEx(script1, cnt3_1_e_1_2);
    string script2 = "옆에 있는 통나무의 가지를 뜯어 뗏목의 노로 사용해야겠다. \n\n";
    scriptEx(script2, cnt3_1_e_1_2);
    string script3 = "출발하려 하는데 저 멀리서 누군가 뛰어온다. 엄청 빠르다. \n\n";
    scriptEx(script3, cnt3_1_e_1_2);
    string script4 = "뗏목 주인인가 보다! 큰일이다 빨리 도망쳐야 한다. \n";
    scriptEx(script4, cnt3_1_e_1_2);
    string script5 = "노를 젓기 위해 가지를 물에 넣는 순간 무언가 뾰족한 것이 나의 목 뒤를 강타하였다. \n\n";
    scriptEx(script5, cnt3_1_e_1_2);
    string script6 = "서서히 시야가 흐려진다...\n";
    scriptEx(script6, cnt3_1_e_1_2);
    cnt3_1_e_1_2++;

    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);
    printf(".\n");
    Sleep(500);

    setColor(red, black); //빨간색 검정색
    printf("알 수 없는 이의 화살을 맞고 사망하였습니다. \n");
    setColor(white, black); //흰색 검정색
    Sleep(SLEEP_TIME);

    printf("리스폰 하려면 1을 누르시오. \n\n");

    totalscore -= 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }

    popStoryPath();

    return callStoryFunc();
}

list<char> story3_2() //강으로
{
    string script1 = "어느새 강에 도착했다. \n";
    scriptEx(script1, cnt3_2);
    string script2 = "사실 이곳에 와서 저 높은 곳에 폭포가 있다는 것을 알고 직감적으로 강이 있음을 인지했다. \n\n";
    scriptEx(script2, cnt3_2);
    string script3 = "강은 생각보다 길고 넓어서 강의 하류로 걸어 내려가고자 한다. \n\n\n\n";
    scriptEx(script3, cnt3_2);

    string script4 = "계속 걷다보니 마을로 추정되는 것이 보이기 시작한다! 드디어 머무를 곳이 생긴 것인가?\n\n";
    scriptEx(script4, cnt3_2);
    string script5 = "마을 정문으로 가니 문지기로 추정되는 사람이 말을 걸었다. \n\n";
    scriptEx(script5, cnt3_2);

    setColor(10, 0);
    string script6 = "[문지기] : 길을 잃었는가?\n\n";
    scriptEx(script6, cnt3_2);
    cnt3_2++;

    setColor(white, black);
    printf("1. 예. 혹시 제가 머무를 곳이라도 있나요?\n");
    printf("2. 아니오. 저도 이 섬 거주자입니다. ^^ \n\n");

    return list<char>{'1', '2'};
}

list<char> story3_2_1()
{
    setColor(10, 0);
    string script1 = "[문지기] : 저희가 꼭 그래야 하는 이유가 있나요? \n\n";
    scriptEx(script1, cnt3_2_1);
    cnt3_2_1++;

    setColor(white, black);
    printf("1. 제가 가진 것들을 그래도 좀 있어요! \n");
    printf("2. 글쎄요 있을까요? \n\n");

    return list<char>{'1', '2'};
}

list<char> story3_2_2()
{
    setColor(10, 0);
    string script1 = "[문지기] : 그렇다면 이만 돌아가시죠. \n\n";
    scriptEx(script1, cnt3_3_2);
    cnt3_3_2++;

    setColor(white, black);
    printf("1. 아닙니다! 그래도 제가 머무를 곳이 있을까요..? \n\n");

    popStoryPath();
    pushStoryPath('1');
    return callStoryFunc();
}

list<char> story3_2_1_1() //인벤토리 확인, 동전교환 과정 -> 동전 선택 아니면 다른 결과
{
    setColor(10, 0);
    string script1 = "";

    rebuildStoryPath(list<char>{'3', '2', 'e', '1'});
    return callStoryFunc();
}

list<char> story3_2_1_2()
{
    setColor(10, 0);
    string script1 = "[문지기] : (뭐지 이 싸가지는...?) 그럼 이만 돌아가시죠. \n\n";
    scriptEx(script1, cnt3_2_1_2);
    cnt3_2_1_2++;

    setColor(white, black);
    printf("1. 아닙니다! 제가 가진 것들이 있어요! (빠른 수습)\n\n");

    popStoryPath();
    pushStoryPath('1');
    return callStoryFunc();
}

list<char> story3_2_e_1() //story3_2_1_1 이후에 바로
{
    string script1 = "그렇게 나는 그들과 함께 구성원의 일부로서 살아갔다. \n\n";
    scriptEx(script1, cnt3_2_e_1);
    string script2 = "솔직히 말해서 초반에는 힘들었다. 내가 그동안 살아온 방식과는 많이 달랐기에. \n\n";
    scriptEx(script2, cnt3_2_e_1);
    string script3 = "그들이 말하는대로, 그들이 먹는대로, 그들이 입는대로 생활했다. \n\n";
    scriptEx(script3, cnt3_2_e_1);
    string script4 = "어느새 나는 내가 원래부터 그들과 하나였다고 생각하고 살아가고 있었다. \n\n";
    scriptEx(script4, cnt3_2_e_1);
    string script5 = "어느새 이 섬에 산 지......\n\n\n";
    scriptEx(script5, cnt3_2_e_1);
    string script6 = "453일이 지났다. \n";
    scriptEx(script6, cnt3_2_e_1);
    cnt3_2_e_1++;

    Sleep(SLEEP_TIME);
    printf("\n\n");

    setColor(yellow, black);
    printf("다른 엔딩이 궁금하지 않으신가요? \n\n");
    printf("게임을 다시 플레이하여 여러 엔딩을 경험해보세요. \n\n");

    return list<char>{};
}

list<char> story3_3() //숲으로
{
    string script1 = "푸르른 풀 냄새로 가득한 녹음으로 이루어진 울창한 숲 앞에 도착하였다. \n";
    scriptEx(script1, cnt3_3);
    string script2 = "굳이 짐승이 아니더라도 숲이다 보니 뭐라도 먹을게 있지 않을까..? \n\n";
    scriptEx(script2, cnt3_3);
    string script3 = "앗! 저기 토끼가 지나간다! 더 멀어지기 전에 빨리 잡아야 한다! \n\n";
    scriptEx(script3, cnt3_3);
    string script4 = "어서 토끼를 잡아보자! \n\n\n";
    scriptEx(script4, cnt3_3);
    cnt3_3++;

    setColor(yellow, black);
    printf("------------------토끼를 잡아라! minigame 튜토리얼------------------\n\n");
    printf("         현재 토끼가 보이지 않는 상황에서 갈림길에 도착하면\n");
    Sleep(SLEEP_TIME);
    printf("         빠르게 왼쪽 (LEFT) 또는 오른쪽 (RIGHT) 을 선택한다. \n");
    Sleep(SLEEP_TIME);
    printf("    한 번의 선택을 할 때 마다 토끼를 만날 수도, 못 만날 수도 있다.  \n");
    Sleep(SLEEP_TIME);
    printf(" 갈림길을 총 5번 만나게 되며 3번 이상 만났다면 토끼를 잡는데 성공한다! \n\n");
    printf("-----------------------------------------------------------------------\n\n");
    Sleep(2000);

    printf("계속하려면 1을 누르시오. \n\n");
    setColor(white, black);
    /*
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        story1_2_1();
    }
    */
    //아닐 때는 어떻게 하지?

    totalscore -= 100;

    while (keyCheckerIgnoreCase('1') == false)
    {
        Sleep(100);
    }

    pushStoryPath('m');
    return callStoryFunc();
}

list<char> story3_3_m()
{
    string script1 = "저기 지나간 흔적이 보인다! 갈림길이 있군! \n\n";
    scriptEx(script1, cnt3_3_m);
    cnt3_3_m++;

    int cnt = 5;
    int answer[5] = {'1','2','1','2','2'};
    while (cnt--)
    {
        printf("1. 왼쪽\n\n");
        printf("2. 오른쪽");

        int key = pressedKey();
        if (answer[5 - cnt] == key)
        {
            system("cls");
            printf("잡았다");
            bunnycatch++;
        }
        else
        {
            system("cls");
            printf("놓쳤다");
        }

        Sleep(SLEEP_TIME);
        system("cls");
    }

    if (bunnycatch >= 3)
    {
        M.Hp += 10;
        string script1 = "토끼를 잡았다! 이걸로 끼니 해결은 가능하겠군! \n";
        scriptEx(script1, cnt3_3);
        cnt3_3++;
    }

    else if (bunnycatch < 3)
    {
        M.Hp -= 10;
        string script2 = "토끼를 놓쳤다...열심히 사냥했더니 너무 배고프다...\n";
        scriptEx(script2, cnt3_3);
        cnt3_3++;
    }

    popStoryPath();
    pushStoryPath('e');
    pushStoryPath('1');

    return callStoryFunc();
}



list<char> story3_3_e_1()
{
    string script1 = "어두워지면 알 수 없는 짐승들과 추위 때문에 위험하다. \n";
    scriptEx(script1, cnt3_3_1);
    string script2 = "어서 나를 보호할 수 있는 집을 지어야 한다. \n\n";
    scriptEx(script2, cnt3_3_1);
    cnt3_3_1++;

    //이렇게 하면 안될거 같은데

    string script3 = "인벤토리 속에 사용할만한 나무가 있는지 확인해보자. \n"; //인벤토리 확인
    scriptEx(script3, cnt3_3_1);

    //return list<char>story3_3_1();
    return story3_3_e_2();
}

list<char> story3_3_e_2()
{
    string script1 = "이 정도면 집을 짓기에 충분하다. 어서 나무 집을 지어보자. \n\n";
    scriptEx(script1, cnt3_3_2);

    printf(".\n\n");
    Sleep(SLEEP_TIME);
    printf(".\n\n");
    Sleep(SLEEP_TIME);
    printf(".\n\n\n");

    string script2 = "그렇게 나는 무사히 나무 집을 지었고 조금씩 식량을 모으며 어느 정도 정착하였다. \n\n";
    scriptEx(script2, cnt3_3_2);
    string script3 = "집도 서서히 넓혀갔고 섬의 구조도 누구보다 잘 알게 되었다. \n\n";
    scriptEx(script3, cnt3_2_2);
    string script4 = "탈출에 대한 희망은 버린지 오래...\n\n";
    scriptEx(script4, cnt3_2_2);
    string script5 = "어느새 이 섬에 산 지......\n\n\n";
    scriptEx(script5, cnt3_2_2);
    string script6 = "453일이 지났다. \n";
    scriptEx(script6, cnt3_2_2);
    cnt3_2_2++;

    Sleep(SLEEP_TIME);
    printf("\n\n");

    setColor(yellow, black);
    printf("다른 엔딩이 궁금하지 않으신가요? \n\n");
    printf("게임을 다시 플레이하여 여러 엔딩을 경험해보세요. \n\n");

    return list<char>{};
}
