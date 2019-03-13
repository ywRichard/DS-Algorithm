#include <string.h>
#include <stdio.h>

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//01.选择法
void SelectionSort(int* arr, int len) {//O{n2}
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] > arr[j]) {
				swap(arr, i, j);
			}
		}
	}
}

//02.插入法
void InsertionSort(int* arr, int len) {//O{n2}
	int i = 0, j = 0;
	int k = 0, temp = 0;

	for (int i = 1; i < len; i++) {
		k = i;
		temp = arr[k];

		for (j = i - 1; (j >= 0) && (temp < arr[j]); j--) {
			arr[j + 1] = arr[j];//元素后移
			arr[j] = temp;
		}
	}
}

//03.冒泡法
//21,25,49,25,16,8
void BubbleSort(int* arr, int len) {
	int exchange = 0;
	exchange = -1;//0:finished; 1: not yet

	for (int i = 0; (i < len - 1) && exchange; i++)
	{
		exchange = 0;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				exchange = 1;
			}
		}
	}
}

void BubbleSort1(int* arr, int len) {
	for (int i = 1; i < len; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
			}
		}
	}
}

void BubbleSort_Reverse(int* arr, int len) {
	int exchange = 0;
	exchange = 1;//0:finished; 1: not yet

	for (int i = 0; (i < len) && exchange; i++)
	{
		exchange = 0;
		for (int j = len - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(arr, j - 1, j);
				exchange = 1;
			}
		}
	}
}
//04.希尔
//49,38,65,97,76,13,27,48,55,4
//13 ,27 ,4 ,49 ,48 ,55 ,38 ,65 ,76 ,97
void ShellSort(int arr[], int len) {
	int i = 0, j = 0, k = 0;
	int temp = 0;
	int gap = len;

	do {
		//Knuth's formula
		gap = gap / 3 + 1;

		for (i = gap; i < len; i += gap) {
			k = i;
			temp = arr[k];

			for (j = i - gap; j >= 0 && (arr[j] > temp); j -= gap)
			{
				arr[j + gap] = arr[j];
				k = j;
			}
			arr[k] = temp;
		}
	} while (gap > 1);
}

void ShellSort1(int arr[], int len) {
	int i = 0, j = 0, k = 0;
	int temp = 0;
	int gap = len;

	do {
		gap = gap / 3 + 1;

		for (i = gap; i < len; i += gap)
		{
			temp = arr[i];//buffer element
			for (j = i - gap; j >= 0 && (temp < arr[j]); j -= gap) {
				arr[j + gap] = arr[j];//move forward
				arr[j] = temp;
			}
		}
	} while (gap > 1);
}
//05.快速排序
//1.左 -> 右 移动, left < pivot
//2.左 <- 右 移动, right > pivot
//3.交换 left 和 right 的值
//4.left>=right, 交换 left 和 pivot
//5.return left
//在左右排序过程中, pivot 只作为排序的判断条件, 而不参与位置交换。直到排序结束才交换到枢轴位置
int partition(int arr[], int left, int right) {
	int leftP = left - 1;//-1是因为从 ++leftP 开始
	int rightP = right;
	int pivot = arr[right];

	while (1) {
		while (arr[++leftP] < pivot);//left sort

		while (rightP > 0 && arr[--rightP] > pivot);//right sort

		if (leftP >= rightP) {
			break;
		}
		else {
			swap(arr, leftP, rightP);
		}
	}

	swap(arr, leftP, right);//swap pivot

	return leftP;
}

//1.依次 交替的比较pivot与high或low指向的值的大小, 
//2.当 low>pivot 或 high<pivot 时交换两者的值
//3.从low 和 high 两边交替逼近, low >= high
//4.return left
//其实是不断交换pivot 和 low 或者 high 的值
int partition_1(int* arr, int low, int high) {
	int pivot = arr[low];

	while (low < high) {
		while ((low < high) && (arr[high] > pivot)) {
			high--;//move forward high point until arr[high]<pivot
		}
		swap(arr, low, high);//swap pivot with high

		while ((low < high) && (arr[low] < pivot)) {
			low++;//move forward high point until arr[high]<pivot
		}
		swap(arr, low, high);//swap pivot with low
	}

	return low;
}


void QuickSort(int arr[], int left, int right) {
	if (right - left <= 0) {
		return;
	}
	else {
		int pvPosition = partition(arr, left, right);
		//int pvPosition = partition_1(arr, left, right);
		QuickSort(arr, left, pvPosition - 1);
		QuickSort(arr, pvPosition + 1, right);
	}
}

//06.归并
void Merge(int* src, int* des, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i <= mid) && (j <= high)) {
		if (src[i] < src[j]) {
			des[k++] = src[i++];
		}
		else {
			des[k++] = src[j++];
		}
	}

	while (i <= mid) {
		des[k++] = src[i++];
	}

	while (j <= high) {
		des[k++] = src[j++];
	}
}

void MSort(int* src, int* des, int low, int high, int len) {
	if (low == high) {
		des[low] = src[low];
	}
	else
	{
		int mid = (low + high) / 2;
		int *space = (int*)malloc(sizeof(int)*len);

		if (space != NULL) {
			MSort(src, space, low, mid, len);
			MSort(src, space, mid + 1, high, len);
			Merge(space, des, low, mid, high);
		}

		free(space);
	}
}

void MergeSort(int* arr, int len) {
	MSort(arr, arr, 0, len - 1, len);
}

void printfArr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ,", arr[i]);
	}
	printf("\n");
}


int main() {
	int arr[] = { 21,25,49,25,16,8 };
	int len = sizeof(arr) / sizeof(*arr);

	//SelectionSort(arr, len);
	//InsertionSort(arr, len);

	//BubbleSort(arr, len);
	//BubbleSort_Reverse(arr, len);
	//BubbleSort1(arr, len);

	int shell_arr[] = { 4,49,97,38,65,76,13,27,48,55 };
	len = sizeof(shell_arr) / sizeof(*shell_arr);
	QuickSort(shell_arr, 0, len - 1);
	printfArr(shell_arr, len);

	/*ShellSort1(shell_arr, len);
	printfArr(shell_arr, len);*/

	printf("\n");
	printf("hello...\n");
	system("pause");
	return 0;
}