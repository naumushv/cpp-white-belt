//#include <iostream>

//void UpdateIfGreater(int first, int & second);

//int main()
//{
//	int a = 4;
//	int b = 2;
//
//	UpdateIfGreater(a, b);
//
//	std::cout << a << ' ' << b;
//
//   return 0; 
//}

void UpdateIfGreater(int first, int & second)
{
	if (first > second)
	{
		second = first;
	}
}
