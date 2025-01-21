#include <iostream>

#include "Dealer.h"
#include "Shoe.h"

using namespace std;

Dealer::Dealer(const char pName[])
{	
	copy(pName, pName + NAME, name);
}

//�Q�[�����s
void Dealer::playBase(Shoe& shoe) {
	//�X�R�A��16�ȉ��̏ꍇhit�𑱂���
	while (getScore() < 17 && getScore() > 0) {
		//�q�b�g����
		hit(shoe);
		cout << "hit" << endl;
		//��D�̕\��
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