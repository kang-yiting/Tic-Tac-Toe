#include<iostream>
using namespace std;
/*�ӧQ�P�_*/
bool winner(char map[3][3]) {
	for (int i = 0; i < 3; i++) if (map[i][0] != ' '&&map[i][0] == map[i][1] && map[i][1] == map[i][2]) return true;//�C�ӧQ�P�_
	for (int i = 0; i < 3; i++) if (map[0][i] != ' '&&map[0][i] == map[1][i] && map[1][i] == map[2][i]) return true;//��ӧQ�P�_
	if (map[0][0] != ' '&&map[0][0] == map[1][1] && map[1][1] == map[2][2]) return true;//���W�k�U�׳ӧQ�P�_
	if (map[0][2] != ' '&&map[0][2] == map[1][1] && map[1][1] == map[2][0]) return true;//�k�W���U�׳ӧQ�P�_
	return false;//�p�G�S���ӧQ�X�{
}
/*�P�_�O�_��b�o�Ӧ�m��m�Ѥl*/
bool TFset(char Player, int Switch, char map[3][3]) {
	/*�Ĥ@�C �P�_*/
	if (Switch == 7 && map[0][0] == ' ') { map[0][0] = Player; return true; }
	else if (Switch == 8 && map[0][1] == ' ') { map[0][1] = Player; return true; }
	else if (Switch == 9 && map[0][2] == ' ') { map[0][2] = Player; return true; }
	/*�ĤG�C �P�_*/
	else if (Switch == 4 && map[1][0] == ' ') { map[1][0] = Player; return true; }
	else if (Switch == 5 && map[1][1] == ' ') { map[1][1] = Player; return true; }
	else if (Switch == 6 && map[1][2] == ' ') { map[1][2] = Player; return true; }
	/*�ĤT�C �P�_*/
	else if (Switch == 1 && map[2][0] == ' ') { map[2][0] = Player; return true; }
	else if (Switch == 2 && map[2][1] == ' ') { map[2][1] = Player; return true; }
	else if (Switch == 3 && map[2][2] == ' ') { map[2][2] = Player; return true; }
	/*���~����*/
	else { cout << "�����F��" << endl; return false; }
}
/*��ܹh*/
void show(char map[3][3]) {
	for (int i = 0; i < 3; i++) {
		cout << " �СССССССС�" << endl;
		for (int j = 0; j < 3; j++) { cout << "|  " << map[i][j] << "  "; } cout << "|" << endl;
	}cout << " �СССССССС�" << endl;
}

int main() {
	char map[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };//�Ŧa��
	char Player = 'O';//�Ĥ@���Ѥl��O  
	int Switch;//���U���Ʀr�䱱�

	show(map);//�a�����
	while (1) {//�C���L���j��
		cout << "�]�����h�X�A�Ʀr���ӤE�c��^" << endl;
		cin >> Switch;
		if (Switch == 0) break;//�p�G��J0�A�����j��

		system("CLS");//�M���e�����t�Φr
		bool TFSet = TFset(Player, Switch, map);//�P�_�O�_�����m�Ѥl�A�é�i�Ѥl
		show(map);//��s�a�����
	/*�P�_�O�_�����a���*/
		if (winner(map) == true) {//�p�G��ӡA��X�a�ϻP��Ӵ��ܫᵲ���j��
			cout << Player << " Ĺ�F�C\n";
			break;
		}
		/*�P�_�O�_����*/
		bool mapover = true;
		for (int i = 0; i < 3; i++)//�j�M���a��
			for (int j = 0; j < 3; j++)
				if (map[i][j] == ' ') mapover = false;//�u�n���@�ӬO�Ū��A�a�ϴN������  

		if (mapover == true) {//�p�G���ϡA��X���ϴ��ܫᵲ���j��
			cout << "���ϡA�����ӭt�C";
			break;
		}
		/*�j���~��A����Ѥl*/
		if (TFSet == true) {//�p�G��~��J�Ѥl���ﶵ�����`����
			if (Player == 'O') Player = 'X';//����Ѥl
			else Player = 'O';
		}
	}
	system("pause");
}