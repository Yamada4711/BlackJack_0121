#include <iostream>

#include "Dealer.h"
#include "Shoe.h"

using namespace std;

Dealer::Dealer(const char pName[])
{	
	copy(pName, pName + NAME, name);
}

//ゲーム実行
void Dealer::playBase(Shoe& shoe) {
	//スコアが16以下の場合hitを続ける
	while (getScore() < 17 && getScore() > 0) {
		//ヒットする
		hit(shoe);
		cout << "hit" << endl;
		//手札の表示
		cout << "====================" << endl;
		cout << "dealer" << endl;
		showHand();
		cout << "====================" << endl;
	}
}

void Dealer::GetName()
{
	for (int i = 0; name[i] != NULL; i++)
	{
		cout << name[i] << flush;
	}
	cout << endl;
}