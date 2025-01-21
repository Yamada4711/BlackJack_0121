#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p, int num)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	for (int i = 0; i < num - 1; i++)
	{
		p[i]->ShowName();
		p[i]->showHand();
		if (p[i]->getScore() > p[num - 1]->getScore()) {
			cout << "Win!" << endl;
		}
		else if (p[i]->getScore() < p[num - 1]->getScore()) {
			cout << "Lose" << endl;
		}
		else {
			cout << "Push" << endl;
		}
		cout << "============================" << endl;
	}
	cout << "dealer" << endl;
	p[num - 1]->showHand();
	cout << "============================" << endl;
}

static void showHand(Person* p)
{
	//手札の表示
	cout << "====================" << endl;
	p->ShowName();
	p->showHand();
	cout << "====================" << endl;

}

//メイン関数
int main() {

	// テスト

	srand((unsigned int)time(NULL));

	enum PERSON
	{
		PLAYER1, PLAYER2, PLAYER3, DEALER
	};

	//各オブジェクトの生成
	Shoe shoe;
	Person* persons[] = { new Player("yamada"), new Player("miwa"), new Player("sugiyama"), new Dealer("dealer") };
	const int num = sizeof(persons) / sizeof(Person*);

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}
	//プレイヤーに2枚目を配布
	for (int i = 0; i < num - 1; i++)
	{
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}

	//ディーラーに2枚目を配布
	persons[DEALER]->hit(shoe);


	// ----　勝負開始
	//プレイヤーの実行
	//バーストしているかどうか判別
	for (int i = 0; i < num - 1; i++)
	{
		showHand(persons[i]);
		if (!persons[i]->play(shoe)) {
			cout << "Burst You Lose" << endl;
		}
	}
	//バーストせずstandした

	//ディーラーの手札を表示
	showHand(persons[DEALER]);

	//ディーラーの自動実行
	persons[DEALER]->play(shoe);

	//結果の表示
	showResult(persons, num);

	cout << "====================" << endl;
	return 0;
}