#include <iostream>
#include <string>
using namespace std;

void printBoard(int (grid)[3][3]);
bool verifyWinner(int (grid)[3][3]);
void writeBoard(int (grid)[3][3], int turno);
void players();

int grid[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};
int turno = 1;
string playerOne, playerTwo;


int main(){
	players();
	
	for(int i = 0; i < 9; i++){
		writeBoard(grid, turno);
		
		if(verifyWinner(grid)){
			if(turno == 1){
				system("cls");
				printBoard(grid);
				cout << "El ganador es: " << playerOne;
				break;
			} else {
				system("cls");
				printBoard(grid);				
				cout << "El ganador es: " << playerTwo;
				break;	
			}
		} 
		turno = (turno == 1)? 2 : 1;
		system("cls");
	}
	if(!verifyWinner(grid)){
		system("cls");
		printBoard(grid);
		cout << "Es un empate!";
	}
	return 0;
}

void players(){
	cout << "Ingrese su nombre jugador 1: ";
	cin >> playerOne;
	
	cout << "Ingrese su nombre jugador 2: ";
	cin >> playerTwo;
	system("cls");
}

void writeBoard(int (grid)[3][3], int turno){
	int x, y;
	int value = (turno == 1)? 1 : -1;
	bool success;
	string player = (turno == 1)? playerOne : playerTwo;	
	
	while(!success){
		printBoard(grid);
		cout << "ingrese fila (" << player << "): ";
		cin >> x;
		cout << "ingrese columna (" << player << "): ";
		cin >> y;
		
		//Adaptamos las variables para trabajar con el array
		x -= 1;
		y -= 1;
		
		if(grid[x][y] == 0 && y < 3){
			grid[x][y] = value;
			success = true;	
		} else {
			system("cls");
			printBoard(grid);
			cout << "Error intente de nuevo: \n";
		}
	}
}

bool verifyWinner(int (grid)[3][3]){
	int sum;
	//primer caso orientacion vertical
	sum = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			sum += grid[i][j];
		}
		if(sum == -3 || sum == 3){
			return true;
		}
		sum = 0;
	}
	//segundo cazo orientacion horizontal
	sum = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			sum += grid[j][i];
		}
		if(sum == -3 || sum == 3){
			return true;
		}
		sum = 0;
	}
	//tercer caso cruazado (\)
	sum = 0;
	for(int i = 0; i <= 2; i++){
		sum += grid[i][i];
	}
	if(sum == -3 || sum == 3){
		return true;
	}
	//cuarto caso cruzado (/)
	sum = 0;
	for(int i = 2; i >= 0; i--){
		sum += grid[i][i];
	}
	if(sum == -3 || sum == 3){
		return true;
	}
	return false;				
}

void printBoard(int (grid)[3][3]) {
	for(int i = 0; i < 3; i++){
		cout << "|";
		for(int j = 0; j < 3; j++){
			if(grid[i][j] == -1){
				cout << "X";
			} else if(grid[i][j] == 1){
				cout << "O";
			} else {
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
	}
}
