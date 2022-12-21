#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

long long Array[10000000];
long long Array_Elements = 10000000;// размер массива
long double SrTimer = 0;
string OutputData = "HeapSortTime.txt"; // Задать имя файла

int* mas = new int[10000000];

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

void Merge(int first, int last)
{
    int middle, start, final, j;
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (Array[start] < Array[final])))
        {
            mas[j] = Array[start];
            start++;
        }
        else
        {
            mas[j] = Array[final];
            final++;
        }
    for (j = first; j <= last; j++) Array[j] = mas[j];
    //delete[]mas;
}
void MergeSort(int first, int last)
{
	if (first < last)
	{
		MergeSort(first, (first + last) / 2);
		MergeSort((first + last) / 2 + 1, last);
		Merge(first, last);
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

	}
	ofstream file(OutputData, ios_base::app);
	file << "Average Time :" << SrTimer / NumOfTest;
	file.close();
}