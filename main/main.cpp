#include <iostream>
#include "List.h"

int main()
{
	TList<int> t, t1;
	t.InsFirst(1);
	t.InsLast(2);
	t.InsLast(3);
	t1.InsLast(2);
	t1.InsLast(3);
	t.DelFirst();
	std::cout << (t == t1);
}
