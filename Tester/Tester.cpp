#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

long long A[10000000];
long double SrTimer = 0;
string OutputData = "output.txt"; // Задать имя файла

void randomArray() {
	for (long long i = 0; i < 10000000;i++) {
		A[i] = rand() % 10000000;
	}
}


void Tester(string NameSort,int i) {
	ofstream file(OutputData, ios_base::app);
	randomArray();
	auto start = high_resolution_clock::now();
	// место для функции сортировки

	//............................
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	file << NameSort << ' ' << "test " << i+1 << " : " << duration.count() << " ms" << '\n';
	SrTimer += duration.count();
	file.close();
}


int main() {
	srand(time(0));
	int NumOfTest = 10;// кол-во тестов
	for (int i = 0; i < NumOfTest; i++) {
		Tester("QuickSort",i);
	}
	ofstream file(OutputData, ios_base::app);
	file << "Среднее время :" << SrTimer / NumOfTest;
	file.close();
}