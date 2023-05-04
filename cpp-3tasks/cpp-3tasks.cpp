#include "BufferList.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	BufferList* example = new BufferList();
	BufferList::ListIterator itr0(example);
	try {
		itr0.getElement();
	}
	catch (BufferException) {
		std::cout << "Список пуст. Невозможно получить очередной элемент!" << std::endl;
	}
	try {
		example->deleteElem(itr0);
	}
	catch (BufferException) {
		std::cout << "Список пуст. Невозможно удалить очередной элемент!" << std::endl;
	}

	example->addElem(1, itr0);
	itr0.next();
	try {
		example->findElem(5);
	}
	catch (NoElemException) {
		std::cout << "Элемент с данным значением отсутсвует в списке!" << std::endl;
	}
	system("pause");
	system("cls");

	BufferList* firstBL = new BufferList();
	BufferList::ListIterator itr(firstBL);
	firstBL->addElem(1, itr);
	itr.next();
	firstBL->addElem(3, itr);
	itr.next();
	firstBL->addElem(2, itr);
	itr.next();
	firstBL->addElem(4, itr);

	itr.start();
	cout << "Вывод списка:" << endl;
	while (!itr.finish())
	{
		itr.next();
		cout << itr.getElement() << endl;
	}
	cout << "--------------------------------" << endl;

	cout << "Удаляем элемент со значением 3" << endl;
	Iterator* itr2 = firstBL->findElem(3);
	firstBL->deleteElem(*itr2);
	cout << " Добавляем элементы 5, 6" << endl;
	firstBL->addElem(5, itr);
	itr.next();
	firstBL->addElem(6, itr);
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		cout << itr.getElement() << endl;
	}
	cout << "--------------------------------" << endl;

	cout << firstBL->findElem(5)->getElement() << endl;
	cout << "Размер: " << firstBL->getSize() << endl;
	cout << "Проверка на пустоту: " << firstBL->isEmpty() << endl;
	cout << "Обнуляем буферный список." << endl;
	firstBL->makeEmpty();
	cout << "Проверка на пустоту: " << firstBL->isEmpty() << endl;
	itr.start();
	cout << "--------------------------------" << endl;
	while (!itr.finish())
	{
		itr.next();
		cout << itr.getElement() << endl;
	}
	system("pause");
	return 0;
}