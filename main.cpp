// Напишите программу, в которой создается и заполняется натуральными числами
// двумерный массив. Заполнение начинается с левого верхнего элемента слева направо, сверху
// вниз (то есть заполняется сначала первая строка, затем вторая, и так далее)
#include <iostream>

using namespace std;

asm(".intel_syntax noprefix\n\t");

int main(int argc, char const *argv[])
{
	int size;
	cout << "Input array size: ";
	cin >> size;

	int** array = new int*[size];
	for (int i = 0; i < size; ++i){
		array[i] = new int[size];
	}

	asm(
		"mov rcx, 0\n"
		"rows:\n"
			"mov rdx, 0\n"
			"cols:\n"
			"mov rsi, rcx\n"
			"imul rsi, rbx\n"
			"add rsi, rdx\n"
			"add rsi, 1\n"
			"mov rdi, [rax + 8 * rcx]\n"
			"mov [rdi + 4 * rdx], esi\n"
			"add rdx, 1\n"
			"cmp rdx, rbx\n"
			"jl cols\n"
		"add rcx, 1\n"
		"cmp rcx, rbx\n"
		"jl rows\n"
		:
		: "a" (array), "b" (size)
		:
	);


	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j)
			cout << array[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	return 0;
}