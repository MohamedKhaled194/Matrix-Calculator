#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<sstream>
#include<vector>
using namespace std;
void sum(float arr1[3][3], float arr2[3][3]);
void sub(float arr1[3][3], float arr2[3][3]);
void mul(float arr1[3][3], float arr2[3][3]);
void transpose(float arr1[3][3]);
void division(float arr1[3][3], float arr[3][3]);
void print_string(float arr[3][3]);

int main() {
	string matrix1 ;
	cout << "please enter matrix1: " << endl;
	getline(cin, matrix1);
	string matrix2[9];
	float matrix3[9];
	float matrix4[3][3];
	int found, i = 0;
	replace(matrix1.begin(), matrix1.end(), ']', ' ');
	remove(matrix1.begin(), matrix1.end(), '[');
	remove(matrix1.begin(), matrix1.end(), ';');

	while (matrix1 != "\0") {
		found = matrix1.find(' ');
		for (int f = 0; f < found; f++) {

			matrix2[i] += matrix1[f];
		}

		matrix1.erase(0, found + 1);
		i++;

	}
	
	for (int d = 0; d < 9; d++) {

		matrix3[d] = atof(matrix2[d].c_str());
	}
	int index = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			matrix4[row][col] = matrix3[index];
			index++;
		}
	}
	string matrix5 ;
	cout << "please enter matrix2: " << endl;
	getline(cin, matrix5);
	string matrix6[9];
	float matrix7[9];
	float matrix8[3][3];
	int bound, j = 0;
	replace(matrix5.begin(), matrix5.end(), ']', ' ');
	remove(matrix5.begin(), matrix5.end(), '[');
	remove(matrix5.begin(), matrix5.end(), ';');

	while (matrix5 != "\0") {
		bound = matrix5.find(' ');
		for (int f = 0; f < bound; f++) {

			matrix6[j] += matrix5[f];
		}

		matrix5.erase(0, bound + 1);
		j++;

	}

	for (int d = 0; d < 9; d++) {

		matrix7[d] = atof(matrix6[d].c_str());
	}
	int vertex = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			matrix8[row][col] = matrix7[vertex];
			vertex++;
		}
	}
	
	cout << "please enter (A) to print (matrix A) or (B) to print (matrix B) or enter the operator you want (A+B) or(B+A) to add  " << endl;
	cout << "(A-B) or (B-A)to subtract (A')or(B') to transpose (A*B) or (B*A) to muliply (A/B)or(B/A)to divide" << endl;
	cout << "write exit to quite " << endl;
	bool x = true;
	while (x) {
		string s;
		getline(cin, s);
		if (s=="A+B"||s=="B+A") {
			cout << "the sum of the 2 matrices is :" << endl;
			sum(matrix8, matrix4);
		}
		else if (s == "A-B") {
			cout << "the sub of the 2 matrices is :" << endl;
			sub(matrix4, matrix8);
		}
		else if (s == "B-A") {
			cout << "the sub of the 2 matrices is :" << endl;
			sub(matrix8, matrix4);
		}
		else if (s == "A'") {
			cout << "the transpose of matrix A is :" << endl;
			transpose(matrix4);
		}
		else if (s == "B'") {
			cout << "the transpose of matrix B is :" << endl;
			transpose(matrix8);
		}
		else if (s == "A*B") {
			cout << "the multipication of the 2 matrices is :" << endl;
			mul(matrix4, matrix8);
		}
		else if (s == "B*A") {
			cout << "the multipication of the 2 matrices is :" << endl;
			mul(matrix8, matrix4);
		}
		else if (s == "A/B") {
			cout << "the division of the 2 matrices is :" << endl;
			division(matrix4, matrix8);
		}
		else if (s == "B/A") {
			cout << "the division of the 2 matrices is :" << endl;
			division(matrix8, matrix4);
		}
		else if (s == "exit") {
			x = false;
		}
		else if (s == "A") {
			cout << "the first matrix is :" << endl;
			print_string(matrix4);
		}
		else if (s == "B") {
			cout << "the second matrix is :" << endl;
			print_string(matrix8);
		}
	     
	}
	
}



void sum(float arr1[3][3], float arr2[3][3]) {
	float arr3[3][3];
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			arr3[row][col] = arr1[row][col] + arr2[row][col];
		}
	}
	print_string(arr3);

}


void sub(float arr1[3][3], float arr2[3][3]) {
	float arr3[3][3];
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			arr3[row][col] = arr1[row][col] - arr2[row][col];
		}
	}
	print_string(arr3);

}


void mul(float arr1[3][3], float arr2[3][3]) {
	float arr3[3][3];
	for (int row = 0; row < 3; row++)
	{
		for (int col2 = 0; col2 < 3; col2++)
		{
			arr3[row][col2] = 0;
		}
	}
	for (int row = 0; row < 3; row++) {
		for (int col2 = 0; col2 < 3; col2++) {
			for (int col = 0; col < 3; col++) {
				arr3[row][col2] += arr1[row][col] * arr2[col][col2];

			}
		}			
	}

	print_string(arr3);

}

void transpose(float arr1[3][3]) {
	float arr2[3][3];
	for (int row = 0; row < 3; row++) {
		
			for (int col = 0; col < 3; col++) {
				arr2[col][row] = arr1[row][col];

			}
		
	}
	print_string(arr2);
}

void division(float arr1[3][3], float arr2[3][3]) {
	float inv[3][3];
	float determinant = 0;

	for (int i = 0; i < 3; i++)
		determinant = determinant + (arr2[0][i] * (arr2[1][(i + 1) % 3] * arr2[2][(i + 2) % 3] - arr2[1][(i + 2) % 3] * arr2[2][(i + 1) % 3]));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			inv[i][j] = ((arr2[(j + 1) % 3][(i + 1) % 3] * arr2[(j + 2) % 3][(i + 2) % 3]) - (arr2[(j + 1) % 3][(i + 2) % 3] * arr2[(j + 2) % 3][(i + 1) % 3])) / determinant;
	}

	mul(arr1, inv);
	

}


void print_string(float arr[3][3]) {
	int index = 0;
	float arr1[9];
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			arr1[index] = arr[row][col];
			index++;
		}
	}
	

	vector<string> s(0);
	ostringstream ss[9];
	for (int i = 0; i < 9; i++) {
		ss[i] << arr1[i];
		s.push_back(ss[i].str());


	}

	s[0] = '[' + s[0];
	int last = s.size();
	s[last - 1] = s[last - 1] + ']';
	for (int i = 1; i < 9; i++) {
		if ((i == 3) || (i == 6)) {
			s[i - 1] += ';';
		}

	}
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << "   ";


	}
	cout << endl;
	cout << "         ******************************************************           " << endl;
}


 







