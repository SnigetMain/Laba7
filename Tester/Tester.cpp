#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

long long Array[10000000];
long long Array_Elements = 10000000;// размер массива
long double SrTimer = 0;
string OutputData = "insertionSortеTime.txt"; // Задать имя файла

void randomArray() {
	for (long long i = 0; i < Array_Elements;i++) {
		Array[i] = rand() % Array_Elements;
	}
}

void insertionSort()
{
	int key = 0;
	int i = 0;
	for (int j = 1;j < Array_Elements;j++) {
		key = Array[j];
		i = j - 1;
		while (i >= 0 && Array[i] > key) {
			Array[i + 1] = Array[i];
			i = i - 1;
			Array[i + 1] = key;
		}
	}
}

void Tester(string NameSort,int i) {
	ofstream file(OutputData, ios_base::app);
	randomArray();
	auto start = high_resolution_clock::now();
	// место для функции сортировки
	insertionSort();
	//............................
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	file << NameSort << ' ' << "test " << i+1 << " : " << duration.count() << " ms" << '\n';
	SrTimer += duration.count();
	file.close();
}


int main() {
	srand(time(0));
	int NumOfTest = 1000;// кол-во тестов
	for (int i = 0; i < NumOfTest; i++) {
		Tester("insertionSort",i);
	}
	ofstream file(OutputData, ios_base::app);
	file << "Average Time :" << SrTimer / NumOfTest;
	file.close();
}