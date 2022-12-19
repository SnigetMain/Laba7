#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

long long Array[10000000];
long long Array_Elements = 10000000;// размер массива
long double SrTimer = 0;
string OutputData = "QuickSortTime.txt"; // Задать имя файла

void randomArray() {
	for (long long i = 0; i < Array_Elements;i++) {
		Array[i] = rand() % Array_Elements;
	}
}
void qsortRecursive(long long* Array, long long size) {
    int i = 0;
    int j = size - 1;
    int mid = Array[size / 2];
    do {
        while (Array[i] < mid) {
            i++;
        }
        while (Array[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = Array[i];
            Array[i] = Array[j];
            Array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        qsortRecursive(Array, j + 1);
    }
    if (i < size) {
        qsortRecursive(&Array[i], size - i);
    }
}

void Tester(string NameSort,int i) {
	ofstream file(OutputData, ios_base::app);
	randomArray();
	auto start = high_resolution_clock::now();
	// место для функции сортировки
    
    qsortRecursive(Array, Array_Elements);
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
		Tester("qsort",i);// изменить только имя сортировки 
	}
	ofstream file(OutputData, ios_base::app);
	file << "Среднее время :" << SrTimer / NumOfTest;
	file.close();
}