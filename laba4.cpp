#include <iostream> 

using namespace std;
int matrix(int* mas, int height) {
	if (height == 2) {
		return mas[0] * mas[3] - mas[2] * mas[1];
	}
	else
	{
		int sum = 0;
		for (int i = 0;i < height;i++)
		{
			int* matrixmas = new int[(height - 1) * (height - 1)];
			int count = 0;
			for (int j = 1;j < height;j++) {
				for (int k = 0;k < height;k++) {
					if (k != i) {
						matrixmas[count] = mas[j * height + k];
						count++;
					}
				}
			}
			sum += pow(-1, i) * mas[i] * matrix(matrixmas, height - 1);
			delete matrixmas;
		}
		return sum;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите длинну матрицы" << endl;
	int len;
	cin >> len;
	int* mas = new int[len * len];
	for (int i = 0;i < (len * len);i++)
		cin >> mas[i];
	cout << "Определитель равен";
	cout << matrix(mas, len);
}
