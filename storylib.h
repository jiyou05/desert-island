#pragma once

#include <map>
#include <list>
#include <string>

using namespace std;

struct status //player 상태: 배고픔, 목마름, 체온
{
	int Hp;
	int totalscore;
};

struct inventory
{
	// 사용 가능한 스토리의 이름
	list<string> firestone = {"2"};
	list<string> glasses = {"2"};
	list<string> coin = {};
	list<string> banana = {"1_1"};
	list<string> grapefruit = {"1_1"};
};

// 스토리 함수 포인터
// 반환값 : 다음 스토리의 선택지 (옵션값의 List) 
typedef list<char>(*STORY_FUNC)();

void addStory(string storyKey, STORY_FUNC storyFunc);
void pushStoryPath(char option);
char popStoryPath();
void clearStoryPath();
void rebuildStoryPath(list<char> list);
string buildStoryKey();
list<char> callStoryFunc();

void SleepEx(DWORD dwMilliseconds, int* count);