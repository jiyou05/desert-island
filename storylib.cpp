#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <map>
#include <list>
#include <string>

#include "storylib.h"

using namespace std;

const string DELIMETER = "_";			// 스토리 함수 저장/로드 할 때 사용하는 키의 연결 문자

/////////////////////////////////////////////////
// 전역변수 start

status M;								// 상태
inventory I;							// 인벤토리
map<string, list<char>(*)()> storyMap;	// 스토리 정의 맵
list<char> storyPathList;				// 스토리 진행 선택 리스트

// 전역변수 end
/////////////////////////////////////////////////


void addStory(string storyKey, STORY_FUNC storyFunc)
{
	storyMap.insert(make_pair(storyKey, storyFunc));
}

/*
	스토리 진행 선택 리스트(storyPathList)를 이용하여
	스토리 함수의 키를 생성
	storyPathList에 "1, 2, 1" 로 선택하여 진행하여 왔다면 키는 "1_2_1" 로 생성
*/
string buildStoryKey()
{
	string pathStr;
	// iterator(반복자) 생성
	for (list<char>::iterator iter = storyPathList.begin(); iter != storyPathList.end(); iter++)
	{
		// 처음이면 delimeter 없이
		if (pathStr.empty())
		{
			pathStr += string(1, *iter);
		}
		// 그 다음부터는 delimeter 포함하여 연결
		else
		{
			pathStr += DELIMETER + string(1, *iter);
		}
	}

	return pathStr;
}

/*
	선택한 옵션을 스토리 진행 선택 리스트에 넣는다.
*/
void pushStoryPath(char option)
{
	storyPathList.push_back(option);
}

/*
	스토리 진행 선택 리스트의 마지막 옵션을 리스트에 반환한 후 삭제한다.
*/
char popStoryPath()
{
	if (storyPathList.size() > 0) 
	{
		char option = storyPathList.back();
		storyPathList.pop_back();
		return option;
	}
	else
	{
		return -1;
	}
}

void clearStoryPath()
{
	storyPathList.clear();
} 

void rebuildStoryPath(list<char> list)
{
	storyPathList = list;
}

/*
	스토리 함수를 호출
	buildStoryKey를 이용하여 다음 진행 스토리 키를 생성하고
	storyMap에서 해당하는 함수를 호출
*/
list<char> callStoryFunc()
{

	auto iter = storyMap.find(storyPathList.size() == 0 ? "begin" : buildStoryKey());
	if (iter == storyMap.end())
	{
		printf("해당 스토리가 없습니다.");
		return list<char>{};
	}

	system("cls");
	return (*iter->second)();
}

void SleepEx(DWORD dwMilliseconds, int* count)
{
	if (*count == 0)
	{
		Sleep(dwMilliseconds);
	}
}