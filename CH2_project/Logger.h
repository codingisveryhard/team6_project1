#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Logger
{
public:
    // 로그를 저장할 static 벡터
    static vector<string> logMessages;

    // 로그 추가
    static void log(const string& message);

    // 모든 로그 출력
    static void printLogs();
};

