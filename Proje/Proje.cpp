#include <iostream>
#include <list>
#include <string>
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
			//cout << "numerator : " << numerator << " denominator : " << denominator << endl;
			count++;
		}
		numerator += 2 * denominator;
		denominator += numerator;
	}
	return count;

}

int balanced_numbers(int power)
{
	int remainder;
	int digits;
	unsigned long sum_of_balanced_numbers = 0;
	for(int i =0;i<pow(10,power); i++)
	{
		int n_digit_i;
		int r_digit_i;
		string str_i = to_string(i);
		digits = to_string(i).size() + 1;
		int digit = (int)ceil(digits / 2);
		int count_n = 0;
		int count_r = 0;
		for (auto item = str_i.begin(); item != str_i.end(); item++)
		{
			count_n++;
			if (count_n == digit)
			{
				//cout << "number : "<< i <<" balanced digit : " << *item << "-- soldan --";
				n_digit_i = *item;
			}
		}
		for (auto item = str_i.rbegin(); item != str_i.rend(); item++)
		{
			count_r++;
			if (count_r == digit)
			{
				//cout << "number : "<< i <<" balanced digit : " << *item << "-- saðdan --" << endl;
				r_digit_i = *item;
			}
		}
		if(n_digit_i == r_digit_i)
		{
			//cout << "balanced number : "<< i << endl;
			sum_of_balanced_numbers = sum_of_balanced_numbers + i;
			
		}
		
		
	}
	remainder = sum_of_balanced_numbers % (unsigned long)pow(3,15 ); 
	return remainder;

}

int main()
{
	//cout << square_root_convergents() << endl; #57
	//cout<<balanced_numbers(47); #217
}



