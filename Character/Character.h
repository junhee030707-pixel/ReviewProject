// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.

//주석 제거 합시다.


using namespace std;

class ACharacter
{
public:
    ACharacter(); // 구현을 찾을 수 없습니다. 사용한 곳이 없어 에러는 나지 않았던 듯.
    ~ACharacter();

    // [과제 1] 값을 받는 생성자 선언하기
   // 이름, 체력, 공격력을 입력받아서 생성합니다.
    ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCritical);
    
protected:
    string Name;
    int Hp;
    int Atk;
    int Def;
    float Critical;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
    
    //간단한 게터는 헤더에 구현하는 것을 권장합니다.
    int GetHp();
    string GetName();
    bool IsDead();

};