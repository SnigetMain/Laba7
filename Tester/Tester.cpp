#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

long long Array[10000000];
long long Array_Elements = 10000000;// ������ �������
long double SrTimer = 0;
string OutputData = "HeapSortTime.txt"; // ������ ��� �����

void randomArray() {
	for (long long i = 0; i < Array_Elements;i++) {
		Array[i] = rand() % Array_Elements;
	}
}

void heapify(int N,int i)
{

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < N && Array[l] > Array[largest])
        largest = l;

    if (r < N && Array[r] > Array[largest])
        largest = r;

    if (largest != i) {
        swap(Array[i], Array[largest]);

        heapify(N, largest);
    }
}

void heapSort()
{

    for (int i = Array_Elements / 2 - 1; i >= 0; i--)
        heapify(Array_Elements, i);

    for (int i = Array_Elements - 1; i > 0; i--) {

        swap(Array[0], Array[i]);

        heapify(i, 0);
    }
}

void Tester(string NameSort,int i) {
	ofstream file(OutputData, ios_base::app);
	randomArray();
	auto start = high_resolution_clock::now();
	// ����� ��� ������� ����������
	heapSort();
	//............................
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	file << NameSort << ' ' << "test " << i+1 << " : " << duration.count() << " ms" << '\n';
	SrTimer += duration.count();
	file.close();
}


int main() {
	srand(time(0));
	int NumOfTest = 1000;// ���-�� ������
	for (int i = 0; i < NumOfTest; i++) {
		Tester("HeapSort",i);
	}
	ofstream file(OutputData, ios_base::app);
	file << "Average Time :" << SrTimer / NumOfTest;
	file.close();
}