#pragma once

#include "Person.h"

//ディーラークラス
class Dealer : public Person 
{
public:
	Dealer(const char pName[]);
	void GetName();

protected:
	//ゲーム実行
	void playBase(Shoe& shoe);

private:
	char name[NAME];

};