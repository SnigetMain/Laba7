#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;


long long Array[10000000];
long long Array_Elements = 10000000;// размер массива
long double SrTimer = 0;
string OutputData = "shellSort.txt"; // Задать имя файла

void randomArray() {
	for (long long i = 0; i < Array_Elements;i++) {
		Array[i] = rand() % Array_Elements;
	}
}

int shellSort()
{
	for (int gap = Array_Elements / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < Array_Elements; i += 1)
		{
			int temp = Array[i];
			int j;
			for (j = i; j >= gap && Array[j - gap] > temp; j -= gap)
				Array[j] = Array[j - gap];

			Array[j] = temp;
		}
	}
	return 0;
}

void Tester(string NameSort,int i) {
	ofstream file(OutputData, ios_base::app);
	randomArray();
	auto start = high_resolution_clock::now();
	// место для функции сортировки
	shellSort();
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
		Tester("shellSortTime",i);
	}
	ofstream file(OutputData, ios_base::app);
	file << "Average Time :" << SrTimer / NumOfTest;
	file.close();
}