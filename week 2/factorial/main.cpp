//#include <iostream>

int Factorial(int n)
{
	if (n <= 0)
	{
		return 1;
	}
	return n * Factorial(n - 1);
}
//int main()
//{
//	std::cout << Factorial(1) << std::endl;
//	std::cout << Factorial(-2) << std::endl;
//	std::cout << Factorial(4) << std::endl;
//	return 0;
//}
