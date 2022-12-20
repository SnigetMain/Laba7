#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

long long Array[10000000];
long long Array_Elements = 10000000;// размер массива
long double SrTimer = 0;
string OutputData = "output.txt"; // Задать имя файла

void randomArray() {
	for (long long i = 0; i < Array_Elements;i++) {
		Array[i] = rand() % Array_Elements;
	}
}

void Merge(int* A, int first, int last)
{
    int middle, start, final, j;
    int* mas = new int[10000000];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (A[start] < A[final])))
        {
            mas[j] = A[start];
            start++;
        }
        else
        {
            mas[j] = A[final];
            final++;
        }
    for (j = first; j <= last; j++) A[j] = mas[j];
    delete[]mas;
}
void MergeSort(int* A, int first, int last)
{
    if (first < last)
    {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
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
	file << "Average Time :" << SrTimer / NumOfTest;
	file.close();
}