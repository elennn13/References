﻿#include <iostream>  

template <typename T> 
void pswap(T* pointer1, T* pointer2) {
	T tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}


template <typename T>
void rswap(T& ref1, T& ref2) {
	T tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}


void foo(int& var1, int& var2);






int main() {
	setlocale(LC_ALL, "ru");
	int n, m;


	// Нейтральные указатели
	/*
	int* p1 = 0;
	if (p1 != 0)
		std::cout << p1 << std::endl;
	else
		std::cout << "Указатель не инициализирован!\n";

	

	int* p2 = NULL;
	if (p2 != NULL)
		std::cout << p2 << std::endl;
	else
		std::cout << "Указатель не инициализирован!\n";



	int* p3 = nullptr;// nullptr - значение типа адрес, в нейтральную область используется только этот способ.
	if (p3 != nullptr)
		std::cout << p3 << std::endl;
	else
		std::cout << "Указатель не инициализирован!\n";
*/

	// Модификации указателей
	
	n = 7; m = 15;

	// Указатель на константу. 
	// может быть объявлени без инициализации. 
	// И может менять свое значение в любой 
	// момент работы программы, но с его помощью 
	// не получится поменять значение памяти, на 
	// которую он направлен
	const int* pointer1;
	pointer1 = &n;
	// *pointer1 = 5;// ОШИБКА!
	std::cout << *pointer1 << std::endl;


	// Константный указатель или указатель - константа.
	// Не может быть объявлен без инициализации и не 
	// может менять значение. Но с его помощью можно
	// поменять значение памяти, на которую он направлен.
	int* const pointer2 = &n;
	// pointer2 = &m;// ОШИБКА!
	*pointer2 = 5;
	std::cout << *pointer2 << std::endl;


	// Константный указатель на константу.
	// Не может быть объявлен без инициализации, 
	// не может менять свое значение. С его помощью 
	// нельзя поменять значение памяти, на которую 
	// он направлен.
	const int* const pointer3 = &m;
	// pointer3 = &n;// ОШИБКА!
	//*pointer3 = 42;// ОШИБКА!
	std::cout << *pointer3 << std::endl;


	// Ссылки на переменные 
	// ссылка  олтичается от указателя 1. проще синтаксически 2. ссылка по своей сути некий альтернативный псевдоним 3. некий вариант константного
	
	
	n = 7;
	int& refn = n; // ref + имя_переменной// Ссылка, ассоциированная с переменной n
	std::cout << "n = " << n << std::endl;
	std::cout << "refn = " << refn << std::endl;

	n = 15;
	std::cout << "refn = " << refn << std::endl;// 


	// Ссылки и функции
	
	n = 7; m = 15;
	std::cout <<  n  << ' ' << m << std::endl;
	// pswap(&n, &m); // работает, не удобно
	rswap(n, m);
	std::cout <<  n  << ' ' << m << std::endl;


	//Задача 1. Создайте функцию,  которая принимает две переменные.
	//  Если первая переменная болше, то они обе возводятсяв квадрат.
	//  Иначе они обнуляются

	std::cout << "Задача 1.\nВведите два числа -> ";
	std::cin >> n >> m;
	foo(n, m);
	std::cout << "n = " << n << "; m = " << m << "\n\n";


// ОБЛАСТИ ПРИМЕНЕНИЯ ССЫЛОК 
// 1. Доступ к элементам за пределами их области видимости. 
// 2. Экономия памяти.

	return 0;
}
void foo(int& var1, int& var2) {
	if (var1 > var2) {
		var1 *= var1;// var1 = var1*var1 
		var2 *= var2;
		return;
    }
	var1 = 0;
	var2 = 0;
}