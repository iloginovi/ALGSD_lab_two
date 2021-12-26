#include <chrono>
#include <iostream>

using namespace std;

class Timer {
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now()){

    }
	void reset(){
		m_beg = clock_t::now();
	}

	double elapsed() const{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

int BinarySearch(int *arr, int left, int right, int key) {
	int midd = 0;
	while (1) {
		midd = (left + right) / 2;
		if (key < arr[midd]) {
			right = midd - 1;
		}else if(key > arr[midd]) {
			left = midd + 1;
		}
		else {
			return midd;
		}
		if (left > right) {
			return -1;
		}	
	}
}
void QuickSort(int* array, int low, int high) 
{
	int left = low;
	int right = high;
	int middle = array[(left + right) / 2];


	while (left <= right)
	{
		while (array[left] < middle)
			left++;
		while (array[right] > middle)
			right--;
		if (left <= right)
		{
			swap(array[left], array[right]);
			left++;
			right--;
		}
	}
	if (right > low)
		QuickSort(array, low, right);
	if (left < high)
		QuickSort(array, left, high);
}
void BubbleSort(int *arr,int size) {
	int temp; 
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
bool Check(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}
void BogoSort(int* arr, int size) {
	bool check = Check(arr, size);
	while (!check) {
		for (int i = 0; i < size; i++) {
			std::swap(arr[i], arr[rand() % size]);
		}
		check = Check(arr, size);
	}
}
void IN_Arr_Output(int* arr, int size) {
	for (int i = 0; i < size-1; i++) {
		cout << arr[i] << ", ";
	}
	cout <<  arr[size-1]<<  "\n";
}
void IN_Arr_Fill(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand()%100;
	}
}
void CountingSort(char* arr, int size){
	int high_number = 0; int tmp;
	for (int i = 0; i < size; i++) { 
		if (arr[i] > high_number) { 
			high_number = arr[i]; 
		} 
	}
	high_number++;
	int* count_arr = new int[high_number];
	for (int i = 0; i < high_number; i++) {
		count_arr[i] = 0;
	}
	for (int i = 0; i < size; i++)  {
		tmp = arr[i];
		count_arr[tmp]++;
	}
	int i = 0;
	for (int j = 0; j < high_number; j++) {
		while (count_arr[j] != 0) {
			arr[i] = j;
			count_arr[j]--;
			i++;
		}
	}
	delete  count_arr;
}
void IN_Arr_EQ(int* arr,int* arr2, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = arr2[i];
	}
}
int main()
{
	int N1,N2,N3,N4,N5;
	N1 = 10;
	N2 = 100;
	N3 = 1000;
	N4 = 10000;
	N5 = 100000;
	int* arrN1 = new int[N1];
	int* arrN2 = new int[N2];
	int* arrN3 = new int[N3];
	int* arrN4 = new int[N4];
	int* arrN5 = new int[N5];
	int* arrN1_copy = new int[N1];
	int* arrN2_copy = new int[N2];
	int* arrN3_copy = new int[N3];
	int* arrN4_copy = new int[N4];
	int* arrN5_copy = new int[N5];
	IN_Arr_Fill(arrN1, N1);
	IN_Arr_Fill(arrN2, N2);
	IN_Arr_Fill(arrN3, N3);
	IN_Arr_Fill(arrN4, N4);
	IN_Arr_Fill(arrN5, N5);
	IN_Arr_EQ(arrN1_copy, arrN1, N1);
	IN_Arr_EQ(arrN2_copy, arrN2, N2);
	IN_Arr_EQ(arrN3_copy, arrN2, N3);
	IN_Arr_EQ(arrN4_copy, arrN1, N4);
	IN_Arr_EQ(arrN5_copy, arrN1, N5);
	Timer t;
	t.reset();
	QuickSort(arrN1, 0, N1-1);
	cout << "Quick sort for 10 elements: " << t.elapsed() <<" seconds" << "\n";
	t.reset();
	BubbleSort(arrN1_copy, N1);
	cout << "Bubble sort for 10 elements: " << t.elapsed() << " seconds" << "\n";
	t.reset();
	QuickSort(arrN2, 0, N2 - 1);
	cout << "Quick sort for 100 elements: " << t.elapsed() << " seconds" << "\n";
	t.reset();
	BubbleSort(arrN2_copy, N2);
	cout << "Bubble sort for 100 elements: " << t.elapsed() << " seconds" << "\n";
	t.reset();
	QuickSort(arrN3, 0, N3 - 1);
	cout << "Quick sort for 1000 elements: " << t.elapsed() << " seconds" << "\n";
	t.reset();
	BubbleSort(arrN3_copy, N3);
	cout << "Bubble sort for 1000 elements: " << t.elapsed() << " seconds" << "\n";
	t.reset();
	QuickSort(arrN4, 0, N4 - 1);
	cout << "Quick sort for 10000 elements: " << t.elapsed() << " seconds" << "\n";
	t.reset();
	BubbleSort(arrN4_copy, N4);
	cout << "Bubble sort for 10000 elements: " << t.elapsed() << " seconds" << "\n";
	QuickSort(arrN5, 0, N5 - 1);
	cout << "Quick sort for 100000 elements: " << t.elapsed() << " seconds" << "\n";
	t.reset();
	BubbleSort(arrN5_copy, N5);
	cout << "Bubble sort for 100000 elements: " << t.elapsed() << " seconds" << "\n";
	delete arrN1;
	delete arrN2;
	delete arrN3;
	delete arrN4;
	delete arrN5;
	delete arrN1_copy;
	delete arrN2_copy;
	delete arrN3_copy;
	delete arrN4_copy;
	delete arrN5_copy;
	
}

