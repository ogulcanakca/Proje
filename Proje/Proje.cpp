#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int square_root_convergents() // pay (numerator) ve payda (denominator) belirli bir örüntüye göre hareket ediyor.
{
	unsigned long numerator = 1;
	unsigned long denominator = 1;
	int count = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (to_string(numerator).size() > to_string(denominator).size())
		{
			//cout << "numerator : " << numerator<< "; digit size : "<< to_string(numerator).size()
				 //<< " denominator : " << denominator << "; digit size : " << to_string(denominator).size() << endl;
			count++;
		}
		numerator += 2 * denominator;
		denominator = numerator - denominator;

	}
	return count;
}

int balanced_numbers(int power)
{
	int remainder;
	int digits;
	long sum_of_balanced_numbers = 0;

	for (int i = 1; i < pow(10, power); i++)
	{
		int left_sum = 0;
		int right_sum = 0;
		string str_i = to_string(i);
		digits = to_string(i).size() + 1;
		int digit = (int)ceil(digits / 2);
		int count_n = 0;
		int count_r = 0;

		for (auto item = str_i.begin(); item != str_i.end(); item++)
		{
			count_n++;
			left_sum += *item - '0';
			if (count_n == digit)
			{
				if (digit > 1) {
					left_sum -= *item - '0';
				}
				//cout << "number : "<< i <<"; soldan balanced digit : " << *item <<"---";
				break;
			}
		}
		for (auto item = str_i.rbegin(); item != str_i.rend(); item++)
		{
			count_r++;
			right_sum += *item - '0';

			if (count_r == digit)
			{
				if (digit > 1) {
					right_sum -= *item - '0';
				}

				//cout << "number : "<< i <<" ; saðdan balanced digit : " << *item <<endl;
				break;
			}
		}

		if (right_sum == left_sum)
		{
			//cout << "balanced number : " << i << "; soldan balanced toplam : "
				//<< left_sum << " ; saðdan balanced toplam : " << right_sum << endl;
			sum_of_balanced_numbers = sum_of_balanced_numbers + i;

		}


	}

	remainder = sum_of_balanced_numbers % (unsigned long)pow(3, 15);
	return remainder;

}

int main()
{
	cout << square_root_convergents() << endl; //#57
	//cout << balanced_numbers(47); //#217
}
