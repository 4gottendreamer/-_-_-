#pragma once

namespace alg
{
float Q_rsqrt(float _Number);
double dQ_rsqrt(double _Number);
template <typename T> void sort_bubble_up(T* _Arr, const size_t _N);
template <typename T> void sort_bubble2_up(T** _Arr, const size_t _Row, const size_t _Col);
template <typename T> void sort_insert(T* const _A, const size_t _Col);
template <typename T> void swap(T& _from, T& _to);
template <typename T> void swap_columns(T** const _Arr, const int _Row, const int _Col_from, const int _Col_to);
bool isPalindrome(int _val);
bool isPalindrome(std::string _Str);
}

// Сортировка линейного массива пузырьком по возрастанию
template <typename T>
void alg::sort_bubble_up(T* const _Arr, const size_t _N)
{
	bool isSwapped;
	do {
		isSwapped = false;
		for (size_t i = 0; i < _N - 1; i++) {
			if (_Arr[i] > _Arr[i + 1]) {
				alg::swap(_Arr[i], _Arr[i + 1]);
				isSwapped = true;
			}
		}
	}
	while (isSwapped);
}

// Сортировка столбцов двумерного массива пузырьком
// по возрастанию значений элементов первой строки
template<typename T>
void alg::sort_bubble2_up(T** const _Arr, const size_t _Row, const size_t _Col)
{
	bool isSwapped = false;
	do {
		isSwapped = false;
		for (size_t j = 0; j < _Col - 1; j++) {
			if (_Arr[0][j] > _Arr[0][j + 1]) {
				alg::swap_columns(_Arr, _Row, j, j + 1);
				isSwapped = true;
			}
		}
	}
	while (isSwapped);
}

// Сортировка вставками
template <typename T>
void alg::sort_insert(T* const _A, const size_t _N)
{
	for (int i = 1; i < _N; i++) {
		int j = i;
		while (j > 0 and _A[j] < _A[j - 1]) {
			alg::swap(_A[j], _A[j - 1]);
			j--;
		}
	}
};

// Смена значений двух переменных
template <typename T>
void alg::swap(T& _from, T& _to)
{
	T tmp = _from;
	_from = _to;
	_to = tmp;
};

// Меняет местами столбцы с индексами _i_from и _j_to в матрице _A[_M][*]
template <typename T>
void alg::swap_columns(T** const _Arr, const int _Row, const int _Col_from, const int _Col_to)
{
	for (int i = 0; i < _Row; i++) {
		alg::swap(_Arr[i][_Col_from], _Arr[i][_Col_to]);
	}
}
