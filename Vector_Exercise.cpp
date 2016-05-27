#include<iostream>
#include<vector>
#include<string>
#include<limits>

char initial;
char final;
int reason;

std::vector<int> vec;
std::string str;

const char initial_min = 'A';
const char final_max = 'Z';

bool repeat = true;
bool valid_values = true;

int main()
{
	std::cout << "Progression with characters";
	
	bool repeat = true;
	while (repeat)
	{
		std::cout << "Please insert the values of the Initial, Final and Reason " << "\n"
			      << "Limits: A <= Initial Z <= Final" << "\n"
			      << "Reason: Greater than 0 and Less than or Equal to (Final - Initial + 1)" << "\n";

		std::cout << "Initial = ";
		std::cin >> initial;

		std::cout << "Final = ";
		std::cin >> final;

		std::cout << "Reason = ";
		std::cin >> reason;

		if (std::cin.fail())
		{
			std::cout << "Invalid Values\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		if (valid_values)
		{
			initial = char(toupper(initial));
			final = char(toupper(final));
		}

		if (initial < initial_min)
		{
			std::cout << "Error! Try again \n";
			std::cout << "Initial need to be greater than or equal " << initial_min << "\n";
			valid_values = false;
		}
		if (final > final_max)
		{

			std::cout << "The final value need to be less than or equal to " << final_max << "\n";
			valid_values = false;

		}
		if (initial > final)
		{
		     std::cout << "Initial need to be less than or equal to " << final << "\n" ;
			 valid_values = false;
		}

		if (reason <= 0)
		{
			std::cout << "Reason need to be greater than 0 " << "\n" ;
			valid_values = false;
		}
		if (reason > (final - initial + 1))
		{
			std::cout << "Reason can't be greater than" << (final - initial + 1) << "\n" ;
			valid_values = false;

		}
		if (valid_values)
		{
			unsigned int quant_num = (final - initial + reason) / reason;
			vec.resize(quant_num);
			str.resize(quant_num);
			std::cout << "Total de numeros no intervalo: " << quant_num << "\n";
		}
		unsigned int index;
		char r = char(reason);
		for (index = 0; initial <= final; initial = initial + r)
		{
				vec[index] = initial;
				str[index] = initial;
				index = index + 1;
		}
		
		int sum = 0;
		for (index = 0; index < vec.size(); index = index + 1)
		{
			    sum = sum + vec[index];
			    vec[index];
				std::cout << vec[index]<< "\n" ;
		}
		
		std::cout << " Result of the sum: " << sum << "\n";
		std::cout << " String " << str << "\n" ;
		std::cout << " Do you want to start a new calculation? " << "\n";
		std::cout << "(0 to close, 1 to continue) \n \n";
		std::cin >> repeat; 
		
		if (std::cin.fail())
		{
			std::cout << "Wrong Inserting - The application will be closed" << "\n";
			repeat = false;
			std::cout << "\n";
		}
		else
			std::cout << "Trying Again" << "\n";
		    std::cout << "end of the aplication" << "\n";
	}
 	return 0;
}
