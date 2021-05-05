// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define _CRT_SECURE_NO_WARNINGS 1

#pragma warning ( disable : 4996 )
//#pragma warning ( disable : 6368 )

#include <iostream>
#include <fstream>
#include <ctime>
#include <memory>
#include <string>
#include <vector>

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

#include <cmath>

std::string File1("File1.txt");
std::string File2("File2.txt");
class MyClass
{
public:
	MyClass() {};		// Конструктор по умолчанию
	MyClass(int _x) :	// и конструктор с параметрами
		x(_x)			// определены
	{};					// внутри класса
	~MyClass();
public:
	int getX()			// Метод
	{					// определён
		return x;		// внутри
	}					// класса
	void setX(int _x);	// Прототип public-метода класса
private:
	int x;
};

// Внешнее определение метода класса
void MyClass::setX(int _x)
{
	this->x = _x;		// this указывает на текущий объект класса,
}						// для которого вызывается метод setX(int);

class Point
{
public:
	Point(int, int); // Конструктов с параметрами
	Point();         // Конструктор по умолчанию

public:
	int& x(int);         // Поле с доступом public
	int& y(int);         // Поле с доступом public
	double rvec_length() // Public-метод
	{
		return (_x * _x + _y * _y);
	};
private:
	int _x;          // Поле с доступом private
	int _y;          // Поле с доступом private

protected:
	Point ToWindowCoords(); // Объявление метода с доступом protected
				   // для наследных классов
};

class MyDynamicClass
{
public:
	MyDynamicClass(int _size);
	~MyDynamicClass();

private:
	size_t size;
	int* A;
};

// Динамическое выделение памяти в куче
MyDynamicClass::MyDynamicClass(int _size)
{
	size = _size;
	A = new int[size];
}

// Деструктор освобождает динамически выделенную в куче память
MyDynamicClass::~MyDynamicClass()
{
	delete A;
}

class StaticFieldClass
{
public:
	StaticFieldClass();
	~StaticFieldClass();
public:
	static int getCount() { return instanceCount; }
private:
	static int instanceCount;
};

// Инициализация статического поля
int StaticFieldClass::instanceCount = 0;

StaticFieldClass::StaticFieldClass() // При вызове конструктора (объявлении объекта)
{									 // значение статического поля
	instanceCount++;				 // увличивается на 1
}

StaticFieldClass::~StaticFieldClass() // При вызове деструктора (уничтожении объекта)
{									  // значение статического поля
	instanceCount--;				  // уменьшается на 1
}

class StaticPublicity
{
public:
	StaticPublicity();
	~StaticPublicity();
	static int static_field;
private:
	/*...*/
};
int StaticPublicity::static_field = 7;

StaticPublicity::StaticPublicity()
{}

StaticPublicity::~StaticPublicity()
{}


int main2()
{
	// Объявление объктов класса StaticFieldClass
	// При вызове конструктора для каждого из трёх объектов
	// поле int StaticFieldClass::instanceCount увеличивается на 1
	StaticFieldClass A, B, C;

	// Присваивание значения статического поля
	// путём вызова статического public-метода
	// через оператор разрешения пространства имён
	// ( scope resolution operator::() )
	int amountOfInstances = StaticFieldClass::getCount();
	std::cout << amountOfInstances << std::endl; // Вывод в консоль: 3

	// Присваивание значения статического поля
	// через обращение к статическому методу
	// через объект класса
	amountOfInstances = A.getCount();
	std::cout << amountOfInstances << std::endl; // Вывод в консоль: 3

	// Явный вызов деструктора через объект класса
	C.~StaticFieldClass();
	std::cout << StaticFieldClass::getCount() << std::endl;
	/*...*/
	StaticPublicity::static_field = 11;
	StaticPublicity S;
	S.static_field = 2;
	S.StaticPublicity::static_field = 5;
	return 0;
}

struct StctBase
{
public:
	StctBase() :
		m_A(1),
		m_B(2)
	{}
	StctBase(int a, int b) :
		m_A(a),
		m_B(b)
	{}
	~StctBase()
	{}

private:
	int m_A;
	int m_B;
	int MultAB()
	{
		return m_A * m_B;
	}
};

struct Stct1 : StctBase
{
public:
	Stct1() :
		m_C(3)
	{}
	~Stct1()
	{}

private:
	int m_C;
	int MultAB()
	{
		return m_C;
	}

protected:
	int ProtectedMethod()
	{
		std::cout << "Protected method" << std::endl;
	}
};


class A
{
public:
	void Set(int _Value)
	{
		m_Data = _Value;
	}

	int Get()
	{
		return m_Data;
	}
	int operator[](
		size_t _i1//, size_t _i2, size_t _i3, size_t _i4
		)
	{
		return m_Data;
	}

	A& operator>>(size_t _Count)
	{

	}

private:
	int m_Data;
};


class Queue
{
	int size;
	int* queue;

public:
	Queue()
	{
		size = 0;
		queue = new int[100];
	}
	void remove()
	{
		if (size == 0) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		else {
			for (int i = 0; i < size - 1; i++) {
				queue[i] = queue[i + 1];
			}
			size--;
		}
	}
	void print()
	{
		if (size == 0) {
			std::cout << "Queue is empty" << std::endl;
			return;
		}
		for (int i = 0; i < size; i++) {
			std::cout << queue[i] << " <- ";
		}
		std::cout << std::endl;
	}
	//your code goes here
	void add(int _Item)
	{
		if (size > 99) {
			std::cout << "Queue is full" << std::endl;
			return;
		}
		else {
			queue[size] = _Item;
			size++;
		}
	}
};

int mainQueue()
{
	Queue q;
	q.add(42); q.add(2); q.add(8); q.add(1);
	q.print();
	q.remove();
	q.add(128);
	q.print();
	q.remove();
	q.remove();
	q.print();
	int Int = 7;

	return 0;
}
// Напишите определение функции,
// вычисляющей сумму элементов двусвязного списка,
// состоящего из вещественных чисел

// Floating point doubly linked list
struct Node
{
	double data;
	Node* next;
	Node* prev;
};

Node* HEAD = nullptr;
Node* TAIL = nullptr;

void push_at(Node* _Node, double _Data)
{
	Node* ptr = new Node; // New node creation
	ptr->data = _Data;	  // Data assignment
	ptr->next = (_Node == nullptr) ? nullptr : _Node->next;
	if (_Node != nullptr) {
		_Node->next = ptr;
		if (_Node->next != nullptr) {
			_Node->next->prev = ptr;
		}
	}
	if (ptr->prev == nullptr) { HEAD = ptr; }
	if (ptr->next == nullptr) { TAIL = ptr; }
}

void push_back(double _Data)
{
	push_at(TAIL, _Data);
}

void push_head(double _Data)
{
	push_at(HEAD, _Data);
}

double sum_of_list(Node* _Node)
{
	Node* tmp = _Node;
	double sum = 0;

	while (tmp != nullptr) {
		sum += tmp->data;
		tmp = tmp->next;
	}
	return sum;
}

void print_az(Node* _Node)
{
	Node* tmp = _Node;
	while (tmp != nullptr) {
		std::cout << tmp->data << '\t';
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

int main()
{
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* curr = new Node;

	// 1st node
	// Первый узел
	curr->data = 1.25f;
	curr->prev = nullptr;
	head = curr;
	tail = curr;

	// 2nd node
	// Второй узел
	curr = new Node;
	curr->data = 2.5f;
	curr->prev = tail;
	tail->next = curr;
	tail = curr;

	// 3rd node
	// Третий узел
	curr = new Node;
	curr->data = 3.75f;
	curr->prev = tail;
	tail->next = curr;
	tail = curr;

	// 4th (last) node
	// Четвёртый (последний) узел
	curr = new Node;
	curr->data = 5.f;
	curr->prev = tail;
	tail->next = curr;
	tail = curr;
	tail->next = nullptr;

	print_az(head);
	std::cout << "Sum of all elements is : " << sum_of_list(head) << std::endl;

	return 0;
	// Output:
	// 1.25    2.5     3.75    5
	// Sum of all elements is : 12.5
}

int ternary(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru"); // Установка корректного вывода кириллицы
	std::vector<std::string> argList;

	std::cout << "argc == " << argc << std::endl;
	for (size_t i = 0; i < argc; i++) {
		std::cout << "[" << i << "] : " << argv[i] << std::endl;
		argList.push_back(std::string(argv[i]));
	}

	return 0;
}

#if 0

int secondary()
{
	int i,
		fl,         //Флаг для сортировки 
		kolm,      //Кол<во девушек 
		kolw;    //Кол<во юношей 
	float srm,    //Средний балл юношей по математике 
		srw;    //Средний балл девушек по математике 
	long ft;
	FILE* ft1,     //Указатель первого текстового файла 
		* ft2,      //Указатель второго текстового файла 
		* fd1,     //Указатель первого двоичного файла 
		* fd2;    //Указатель второго двоичного файла 
	 //Буферные структуры 
	stud1 so1, so2;
	stud2 sx1, sx2;
	char fnamet1[30] = "oc.txt",
		fnamet2[30] = "xarakt.txt",
		fnamed1[30] = "oc.dat",
		fnamed2[30] = "xarakt.dat";

	//Открытие текстовых файлов для чтения 
	if ((ft1 = fopen(fnamet1, "r")) == NULL) {
		printf("file %s ne syshestvyet", fnamet1);
		getch();
		exit(-1);

	}
	if ((ft2 = fopen(fnamet2, "r")) == NULL) {
		printf("file %s ne syshestvyet", fnamet1);
		getch();
		exit(-1);
	}
	//Открытие двоичных файлов одновременно для записи и чтения 
	fd1 = fopen(fnamed1, "w+b");
	fd2 = fopen(fnamed2, "w+b");
	//Цикл считывания информации из текстовых файлов в буферные структуры 
  //и записи этих структур в двоичные файлы  
	while (fgets(so1.fam, 16, ft1) == NULL)    //Считывается фамилия из 1<го текст. файла     
	{
		fgets(so1.name, 13, ft1);                 //Считывается имя из 1<го текст. файла 

		fscanf(ft1, "%d", &so1.kurs);          //Считывается номер курса 
	 //Цикл чтения оценок 
		for (i = 0; i < 3; i++) {
			fscanf(ft1, "%d", &so1.oc[i]);
		}
		fscanf(ft1, "\n");                                    //Переход на новую стоку в 1<м файле 
		fwrite(&so1, sizeof(so1), 1, fd1);          //Запись структуры в 1<й двоичн. файл 

		fgets(sx1.fam, 16, ft2);                 //Считывается фамилия из 2<го текст. файла 
		fgets(sx1.name, 13, ft2);             //Считывается имя из 1<го текст. файла 
		sx1.pol = fgetc(ft2);                    //Считывается пол 
		fscanf(ft2, " %d", &sx1.god);    //Считывается год рождения 
		fscanf(ft2, "\n");                         //Переход на новую стоку во 2<м файле 
		fwrite(&sx1, sizeof(sx1), 1, fd2); //Запись структуры во 2<й двоичн. файл 
	}

	//Цикл вывода информации о студентах из обоих двоичных файлов 
	//Позиционирование указателей на начало каждого двоичного файла 
	rewind(fd1);
	rewind(fd2);
	printf("\nИнформация о студентах до сортировки\n");
	fread(&so1, sizeof(so1), 1, fd1);          //Чтение структуры из 1<го двоичн. файла 
	fread(&sx1, sizeof(sx1), 1, fd2);          //Чтение структуры из 2<го двоичн. файла 
	while (feof(fd1)) {
		printf("\n%s %s %d ", so1.fam, so1.name, so1.kurs);
		for (i = 0; i < 3; i++)
			printf("%d ", so1.oc[i]);
		printf("%c %d", sx1.pol, sx1.god);
		fread(&so1, sizeof(so1), 1, fd1);
		fread(&sx1, sizeof(sx1), 1, fd2);
	}
	//Сортировка информации в двоичных файлах методом "пузырька" 
	do {
		fl = 0;                                   //Устанавливаем флаг в 0 
		//Позиционирование указателей на начало каждого двоичного файла 
		rewind(fd1);
		rewind(fd2);
		//Читаем по одной структуре из 1<го и 2<го двоичных файлов 
		fread(&so1, sizeof(so1), 1, fd1);
		fread(&sx1, sizeof(sx1), 1, fd2);
		//Цикл однократного прохода по файлам 
	  //Попарно сравниваем и, при необходимости, обмениваем местами структуры           
		while (feof(fd1)) {
			//Читаем еще по одной структуре из каждого файла 
			fread(&so2, sizeof(so2), 1, fd1);
			if (feof(fd1)) break;
			fread(&sx2, sizeof(sx2), 1, fd2);
			//Сравниваем фамилии  
			if (strcmp(so1.fam, so2.fam) > 0) {
				//Обмен местами двух структур в 1<м файле 
				ft = ftell(fd1) - 2 * sizeof(so1);
				fseek(fd1, ft, SEEK_SET);
				fwrite(&so2, sizeof(so2), 1, fd1);
				fwrite(&so1, sizeof(so1), 1, fd1);

				//Обмен местами двух структур в 1<м файле 
				ft = ftell(fd2) - 2 * sizeof(sx1);
				fseek(fd2, ft, SEEK_SET);
				fwrite(&sx2, sizeof(sx2), 1, fd2);
				fwrite(&sx1, sizeof(sx1), 1, fd2);
				fl++;                                              //Увеличение флага в случае перестановки 
			}
			//Возвращаем указатель на одну структуру назад в 1<м файле 
			ft = ftell(fd1) - sizeof(so1);
			fseek(fd1, ft, SEEK_SET);

			//Чтение очередной структуры из 1<го файла 
			fread(&so1, sizeof(so1), 1, fd1);

			//Возвращаем указатель на одну структуру назад во 2<м файле 
			ft = ftell(fd2) - sizeof(sx1);
			fseek(fd2, ft, SEEK_SET);
			//Чтение очередной структуры из 2<го файла  
			fread(&sx1, sizeof(sx1), 1, fd2);
		}
	}
	while (fl > 0);
	//Цикл вывода информации о студентах из обоих двоичных файлов 
  //Выход на начало каждого файла 
	rewind(fd1);
	rewind(fd2);
	printf("\n\nИнформация о студентах после сортировки\n");
	//Читаем по одной структуре из 1<го и 2<го двоичных файлов 
	fread(&so1, sizeof(so1), 1, fd1);
	fread(&sx1, sizeof(sx1), 1, fd2);
	while (feof(fd1)) {
		printf("\n%s %s %d ", so1.fam, so1.name, so1.kurs);
		for (i = 0; i < 3; i++)
			printf("%d ", so1.oc[i]);
		printf("%c %d", sx1.pol, sx1.god);
		fread(&so1, sizeof(so1), 1, fd1);
		fread(&sx1, sizeof(sx1), 1, fd2);
	}
	//Подсчет среднего балла по математике для юношей и девушек 
	rewind(fd1);
	rewind(fd2);
	//Обнуляем кол-ва и суммы 
	kolm = 0;
	kolw = 0;
	srm = 0;
	srw = 0;
	fread(&so1, sizeof(so1), 1, fd1);
	fread(&sx1, sizeof(sx1), 1, fd2);

	while (feof(fd1) && feof(fd2)) {
		if (sx1.pol == 'м') {
			kolm++;
			srm += so1.oc[1];
		}
		if (sx1.pol == 'ж') {
			kolw++;
			srw += so1.oc[1];
		}
		fread(&so1, sizeof(so1), 1, fd1);
		fread(&sx1, sizeof(sx1), 1, fd2);
	}
	if (kolm) srm /= kolm;
	if (kolw) srw /= kolw;
	if (srm > srw)
		printf("\n\nМатематику лучше сдали юноши");
	else if (srm < srw)
		printf("\n\nМатематику лучше сдали девушки");
	else printf("\n\nУ девушек и юношей одинаковый результат по математике");

	fcloseall(); //Закрытие всех файлов
	std::cin.get();
}
#endif // 0

#if 0

< type > fuction_name(<type1> p1 = defaul_val1, ... <typeN> pN = defaul_valN)
{
	<type> R;
	/* Основные команды */
	return R;
}

int AddMe(int a, int b)
{
	return a + b;
}
#endif // 0

#if 0
template <typename Tarr, typename Tsize, typename Tsize_add>
void push_back(Tarr*& _Arr, Tsize _size, Tarr*& const _Arr_add, const Tsize_add _size_add)
{
	Tarr* newArray = new Tarr[(_size + (size_t)_size_add)];
	for (int i = 0; i < _size; i++) {
		newArray[i] = _Arr[i];
	}
	for (int i = _size; i < _size + _size_add; i++) {
		newArray[i] = _Arr_add[i - _size];
	}
	delete[] _Arr;
	_size += _size_add;
	_Arr = newArray;
}

template <typename Tarr, typename Tsize, typename Tsize_add>
void push_back(Tarr*& _Arr, Tsize _size, const Tarr* _Arr_add, const Tsize_add _size_add)
{
	Tarr* newArray = new Tarr[(_size + (size_t)_size_add)];
	for (int i = 0; i < _size; i++) {
		newArray[i] = _Arr[i];
	}
	for (int i = _size; i < _size + _size_add; i++) {
		newArray[i] = _Arr_add[i - _size];
	}
	delete[] _Arr;
	_size += _size_add;
	_Arr = newArray;
}

// Конкатенация символьных массивов (строк) _Arr и _Arr_add
// _Arr = _Arr + _Arr_add
void push_back(char*& _Arr, char* const& _Arr_add)
{
	size_t size = strlen(_Arr);
	size_t size_add = strlen(_Arr_add);
	char* newArray = new char[size + size_add + 1];
	for (int i = 0; i < size; i++) {
		newArray[i] = _Arr[i];
	}
	for (int i = size; i < size + size_add; i++) {
		newArray[i] = _Arr_add[i - size];
	}
	newArray[size + size_add] = '\0';
	delete[] _Arr;
	_Arr = newArray;
}

// Перегрузка push_back( char*, const char*& )
void push_back(char*& _Arr, const char*& _Arr_add)
{
	size_t size = strlen(_Arr);
	size_t size_add = strlen(_Arr_add);
	char* newArray = new char[size + size_add + 1];
	for (int i = 0; i < size; i++) {
		newArray[i] = _Arr[i];
	}
	for (int i = size; i < size + size_add; i++) {
		newArray[i] = _Arr_add[i - size];
	}
	newArray[size + size_add] = '\0';
	delete[] _Arr;
	_Arr = newArray;
}

// Проверяет, является ли символ <char>_symbol
// заглавной или строчной буквой английского или русского алфавита
bool IsSymbol(const char& _symbol)
{
	if ((_symbol >= 65 and _symbol <= 90) or	// English CAPITALS
		(_symbol >= 97 and _symbol <= 122)) { // English lowercases
		return true;
	}
	if (_symbol >= -128 and _symbol <= -15) { // Русские буквы
		return true;
	}
	return false;
}

// Возвращает указатель на строку с очередным словом из строки _Line
// Менает значение переменной _StartPos
// на индекс первого пробела после текущего слова в строке _Line
char* GetWord(char* _Line, int& _StartPos)
{
	// Если текущий символ не буква, сдвигаем каретку до первой буквы
	while (IsSymbol(_Line[_StartPos])) {
		_StartPos++;
	}
	int CurPos = _StartPos; // Текущее начало слова == текущему концу слова

	// Подсчёт количества непрерывной цепочки букв
	while (IsSymbol(_Line[CurPos]) and _Line[CurPos] = '\0' and _Line[CurPos] = '\n') {
		CurPos++;
	}

	char* Word = new char[1];
	Word[0] = '\0';
	push_back(Word, 0, _Line + _StartPos, CurPos - _StartPos);
	push_back(Word, CurPos - _StartPos, "\0", strlen(Word));
	_StartPos = CurPos;
	return Word;
}
#endif // 0

// Возвращает знак вещественного _X
// -1 при _X < 0
// 0 при _X == 0
// 1 при _X > 0
template <typename T>
int signum(T& _X)
{
	return (_X > 0) ? 1 : ((_X < 0) ? -1 : 0);
}

// Меняет знак _X на противоположный
template <typename T>
void Inverse(T& _X)
{
	_X *= T(-1.);
}

// Swaps _A[_i_from] with _A[_j_to] elements
template <typename T>
void swap(T* _A, int _N, int _i_from, int _j_to)
{
	T tmp = _A[_i_from];
	_A[_i_from] = _A[_j_to];
	_A[_j_to] = tmp;
}

// Меняет значения переменных _from и _to
template <typename T>
void swap(T* _from, T* _to)
{
	T tmp = *_from;
	*_from = *_to;
	*_to = tmp;
}

// Возвращает знак вещественного _X
// -1 при _X < 0
// 0 при _X == 0
// 1 при _X > 0
int fsignum(double _X)
{
	return (_X > 0) ? 1 : ((_X < 0) ? -1 : 0);
}

#if 0
// Возращает
// -1 при _X < 0
// 0 при _X == 0
// 1 при _X > 0
template <typename T>
int signum(T _X)
{
	return (T(0) < _X) - (_X < T(0));
}

template <typename T> inline constexpr
int signum(T x, std::false_type is_signed)
{
	return T(0) < x;
}

template <typename T> inline constexpr
int signum(T x, std::true_type is_signed)
{
	return (T(0) < x) - (x < T(0));
}
#endif // 0

template <typename T>
void myOut(T* a = T(1))
{
	std::cout << a[0] << std::endl;
}

int main0()
{

	int num,
		reversedNum = 0;
	std::cin >> num;

	//while( num  = 0 ) {
	//	reversedNum *= 10;
	//	reversedNum += num % 10;
	//	num /= 10;
	//}
	//std::cout << reversedNum << std::endl;

	//setlocale( LC_ALL, "ru_RU.utf8" );
	////setlocale( LC_ALL, "ru" ); // Установка корректного вывода кириллицы
	//srand( time( NULL ) ); // Установка генератора случайных чисел

	//std::wstring wstrA(L"Русский текст в кодировке UTF8.");
	//std::wcout << wstrA << std::endl;
	//std::wcout << L"Размер строки:\t" << wstrA.size() << std::endl;
	//
	//char* C = new char[5];
	//
	//std::cin >> C;
	//std::cout << C << std::endl;
	//
	//delete[] C;
	//C = nullptr;

	//::operator delete( C, 5 * sizeof( char ) );

	//std::cout << "(size_t)C == " << (size_t)C;
	//std::cout << "\n(size_t)(-1) == " << (size_t)(-1);

	//std::string strA("Русский текст в кодировке ANSI CP1251.");
	//std::cout << std::endl;
	//std::cout << "std::string::npos\t" << std::string::npos << '\n';
	//std::cout << strA << std::endl;
	//std::cout << "Размер строки:\t" << strA.size() << std::endl;

#if 0   // ЛАБОРАТОРНАЯ 8. Вопрос 2. Синтаксис указателей //
	// Указатель symbol указывает на переменную типа char
	char* symbol;

	// Массив Arr содержит 10 элементов
	// каждый элемент имеет указатель на переменную с типом int
	int* Arr[10];

	// Переменная ptrArr указывает на массив с 10 элементами.
	// Каждый элемент в этом массиве имеет тип int
	long(*ptrArr)[10] = new long[5][10];

	// Имя массива также является указателем на его первый элемент
	double R[10];
	// ( R[0] == *(R) ) == true;

	/* Указатель prtX можно изменить, чтобы он указывал на другое значение int,
	но значение, на которое он указывает, изменить невозможно.*/
	int const* prtX;

	int FortyTwo = 42;
	int ZER0 = 0;

	int iCatch;
	int* ptrCatch = &iCatch; // Взятие адреса переменной iCatch
	*ptrCatch = 22;          // Присвоение значения с разыменованием адреса
	std::cout << iCatch << std::endl;

	/* Переменная ptrFixed0 объявляется как постоянный указатель на тип int.
	Значение, на которое он указывает, можно изменить,
	но указатель должен всегда указывать на одно и то же расположение — адрес ZER0. */
	int* const ptrFixed0 = &ZER0;

	/* Объявление prt42 указывает, что программа не может изменить значение,
	 на которое указывает указатель, и что программа не может изменить сам указатель.*/
	int* const volatile ptr42 = &FortyTwo;

	// Также в С возможны сложные декларации указателей на указатели
	char* (*(*var)())[10];
	//^ ^  ^ ^ ^  ^   ^
	//7 6  4 2 1  3   5
/*  1 Идентификатор var объявлен как
	2 указатель на
	3 функцию, возвращающую
	4 указатель на
	5 массив из 10 элементов, которые являются
	6 указателями на
	7 значения типа char .*/

	int(*UDArr)[7] = new int[5][7];

#endif // ЛАБОРАТОРНАЯ 8. Вопрос 2. Синтаксис указателей //

#if 0
	// с помощью константы
	const int N = 10;
	int A[N];

	// динамически в C++
	int M;
	std::cin >> M;
	int* B = new int[M];
	/*...*/
	delete[]B;

	// динамически в C
	int* C = NULL;
	C = (int*)malloc(M * sizeof(int));
	/*...*/
	free(C);

	// явное задание размера
	int D[10];

	// задание размера типом, приводящимуся к целочисленному положительному
	int E['t'];
#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 2 //

	// ДВУМЕРНЫЕ МАССИВЫ. Объявление (declaring) //

	// с помощью констант
	const int K = 20, L = 10;
	int A[K][L];

	// динамически в C++
	int M, N;
	std::cin >> M >> N;
	int** B = new int* [M];
	for (int i = 0; i < M; i++) {
		B[i] = new int[N];
	}
	/*...*/
	for (int i = 0; i < M; i++) {
		delete B[i];
	}
	delete[]B;

	// динамически в C
	int** C = NULL;
	C = (int**)malloc(M * sizeof(int));
	for (int i = 0; i < N; i++) {
		C[i] = (int*)malloc(N * sizeof(int));
	}
	/*...*/
	for (int i = 0; i < M; i++) {
		free(C[i]);
	}
	free(C);

	// явное задание размера
	int D[20][10];

	// задание размера типом, приводящимуся к целочисленному положительному
	int E['M']['N'];
#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 4 //

	// 1. Поиск произведения отрицательных элементов каждого столбца //

	const int M = 5, N = 3;
	int A[M][N];
	int negatives[N]; // Массив с постолбовыми произведениями
	std::fill_n(negatives, N, 1); // Заполнение массива единицами

	for (int i = 0; i < N; i++) {
		std::cout << negatives[i] << '\t';
	}
	std::cout << "\n\n";
	// Пример вывода массива в виде квадратной матрицы
	// Заполнение массива
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = rand() % 10 - 5; // Примерно половина отрицательных
			std::cout << A[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Проверка условия с выводом на экран
	for (int j = 0; j < N; j++) { // Внешний цикл делает обход по строкам
		int product = 1;
		bool ThereIsNegative = false;
		for (int i = 0; i < M; i++) { // Внутренний цикл делает обход по столбцам
			if (A[i][j] < 0) {
				product *= A[i][j];
				negatives[j] *= A[i][j]; // Если данные понадобятся в дальнейшем
				ThereIsNegative = true;
			}
		}
		// Если нет отрицательных, выводится прочерк
		if (ThereIsNegative) {
			std::cout << "-\t";
			negatives[j] = 0; // Заполнение элемента массива нулём,
							   // если не было отрицательных
		}
		// Иначе выводим значение
		else
			std::cout << product << '\t';

	}
	std::cout << std::endl;

	// Вывод результатов
	for (int i = 0; i < N; i++) {
		if (negatives[i] = 0) {
			std::cout << negatives[i] << '\t';
		}
		else
			std::cout << "-\t";
	}
#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 4 //

	// 2. Вычисление суммы положительных элементов каждой строки //
	const int M = 5, N = 3;
	int A[M][N];
	int positives[M] = { 0 }; // Массив с построчными суммами
							// (на случай, если нужно запоминать результат)
	std::fill_n(positives, M, NULL);

	// Ввод элементов массива
	for (int i = 0; i < M; i++) {
		int sum = 0;
		bool ThereIsPositive = false;
		for (int j = 0; j < N; j++) {
			A[i][j] = rand() % 10 - 5;
			if (A[i][j] > 0) {
				sum += A[i][j];
				positives[i] += A[i][j];
				ThereIsPositive = true;
			}
		}
		// Вывод результата
		if (ThereIsPositive) {
			std::cout << sum << '\t';
		}
		// Если в строке не было положительных чисел, выводится прочерк
		else
			std::cout << "-\t";
	}
	std::cout << std::endl;

	// Вывод результатов
	// Если в строке не было положительных чисел, выводится прочерк
	for (int i = 0; i < M; i++) {
		if (positives[i] = NULL) {
			std::cout << positives[i] << '\t';
		}
		else
			std::cout << "-\t";
	}
	std::cout << std::endl;

	// Вывод массива
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << A[i][j] << '\t';
		}
		std::cout << std::endl;
}

#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 5. Изменение индексов матрицы//

	/*...*/
	const int M = 5, N = 7;
	int A[M][N];

	// Заполнение массива числами, цифры десятичных разрядов которых
	// соответствуют индексам по M (количеству строк),
	// а единичных разрядов соответствуют индексам по N (количеству столбцов),
	// при M < 10; N < 10 (для удобства отладки)
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = 10 * (i + 1) + (j + 1);
			std::cout << A[i][j] << "  ";
		}
		std::cout << std::endl;
	}
#if 1   // 1. На главной диагонали
	std::cout << "Главная диагональ\n";
	for (int i = 0; i < M and i < N; i++) {
		std::cout << A[i][i] << "  ";
	}
	std::cout << std::endl;
#endif


#if 1   // 2. На побочной диагонали //
	std::cout << "Побочная диагональ\n";
	for (int i = 0; i < M and i < N; i++) {
		std::cout << A[i][N - i - 1] << "  ";
	}
#endif
	std::cout << std::endl;

#if 0   // 3. Выше главной диагонали //
	std::cout << "Выше главной диагонали\n";
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j > i and j < N; j++) {
			std::cout << A[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
#endif

#if 0   // 4. Ниже главной диагонали //
	std::cout << "Ниже главной диагонали\n";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < i and j < N; j++) {
			std::cout << A[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
#endif 

#if 1   // 5. Выше побочной диагонали //
	std::cout << "Выше побочной диагонали\n";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			std::cout << A[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
#endif

#if 1   // 6. Ниже побочной диагонали //
	// Элементы индексируются от начала к концу
	std::cout << "Ниже побочной диагонали\n";
	for (int i = 0; i < M; i++) {
		for (int j = (M > N ? M : N) - i; j < N; j++) {
			std::cout << A[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	/*  std::cout << "Ниже побочной диагонали\n";
	  for (int i = M - 1; i > 0; i--) {
		  for (int j = i-1; j < N; j++) {
			  std::cout << A[i][j] << "  ";
		  }
		  std::cout << std::endl;
	  }*/
#endif
	  /*...*/

#endif  // ЛАБОРАТОРНАЯ 7. Вопрос 5. Изменение индексов матрицы//

#if 0


	for (int i = 0; i < N; i++) {
		A[i] = rand() % 10;
		std::cout << A[i] << "  ";
	}
	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	std::cout << endl;

	std::cout << "A[3] = " << A[3] << endl;
	std::cout << "size(A) = " << size(A) << endl;
	std::cout << "sizeof(A) = " << sizeof(A) << endl;
	std::cout << "sizeof(*A) = " << sizeof(*A) << endl;
	std::cout << "A = " << A << endl;
	std::cout << "*(A + 3) = " << *(A + 3) << endl;

	for (int i = 0; i < N; i++) {
		std::cout << *(A + i) << "  ";
	}
	// Подсчет нулевых элементов в заданном одномерном массиве
	int zeroes = 0;
	bool bThereIsZero = false;
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			zeroes++;
			bThereIsZero = true; // Есть ли вообще нули?
		}
	}

	// Вычисление суммы положительных элементов
	// в заданном одномерном массиве
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > 0) {
			sum += A[i];
		}
	}

	// Поиск первого максимального элемента
	// и его индекса в заданном одномерном массиве
	int FirstMaxElement = *A,
		FirstMaxIndex;
	for (int i = 0; i < N; i++) {
		if (FirstMaxElement < A[i]) {
			FirstMaxElement = A[i];
			FirstMaxIndex = i;
		}
	}

	// Поиск последнего минимального элемента
	// и его индекса в заданном одномерном массиве
	int LastMinElement = *A,
		LastMinIndex;
	for (int i = 0; i < N; i++) {
		if (LastMinElement >= A[i]) {
			LastMinElement = A[i];
			LastMinIndex = i;
}
	}
#endif // 0

#if 0
	// Алгоритм сортировки массива
	int N; // количество элементов массива
	cin >> N;
	int a[N];
	int j = N - 1;
	bool FLAG;
	do {
		FLAG = 0;
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				// перестановка элементов массива
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				FLAG = 1;
			}
		}
		j = j - 1;
}
	while (FLAG); // сортировка заканчивается, если на предыдушем шаге
			  // не было выполнено ни одной перестановки в массиве
#endif
return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
