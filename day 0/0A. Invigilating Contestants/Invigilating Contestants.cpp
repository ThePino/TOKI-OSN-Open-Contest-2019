#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
int R, C;
char rect[MAXN][MAXN];
//                 up     left   right   down
int moves[][2] = {{-1,0},{0,-1}, {0,1}, {1,0} };
// 
char to_place[] = {'v','>','<','^'};

bool inline can_move(int y,int x){
	if(y < 0 || y >= R)return false;
	if(x < 0 || x >= C)return false;
	return true;
}

string name = "mengawasi_";

int main(){
	for(int  t = 1; t <= 5; t++){
		ifstream fin(name + to_string(t) + ".in");
		ofstream fout(name + to_string(t) + ".out");
		#define cin fin
		#define cout fout
		cin >> R >> C;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin >> rect[i][j];
			}
		}
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(rect[i][j] == 'x'){
					for(int z = 0; z < 4; z++){
						int y = i + moves[z][0];
						int x = j + moves[z][1];
						if((y + x) % 2 == 0 && can_move(y,x) && rect[y][x] == '.'){
							rect[y][x] = to_place[z];
							break;
						}
					}
				}
			}
		}
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cout << rect[i][j];
			}
			cout << '\n';
		}
		fin.close();
		fout.close();
	}
	return 0;
}
