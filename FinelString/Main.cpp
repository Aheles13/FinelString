#include <iostream>
#include <string>

	std::string spaces_str(std::string str); //Задание 1.
	
	bool is_spam(std::string str);


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Задание 1. Вставка пробелов.

	/*std::cout << "Задача 1\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";*/

	//Задание 2. Проверка на спам.

	/*std::cout << "Задание 2.\nВведите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаружен спам!\n\n";
	else
		std::cout << "Спам не обнауржен.\n\n";*/

	//Задание 3. Разбивка URL
	std::cout << "Задание 3.\nАдрес: ";
	std::string URL = "http://goodl.com/search/results";
	std::cout << URL << std::endl;

	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", domen_index) + 1;
	

	std::string protocol = URL.substr(0, domen_index - 3 );
	std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
	std::string path = URL.substr(path_index);
	
	std::cout << "Протокол: " << protocol << std::endl;
	std::cout << "Домен: " << domen << std::endl;
	std::cout << "Путь: " << path << std::endl;

	return 0;
}
// Задание 1.
std::string spaces_str(std::string str) {
	std::string result;
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		if(i != str.length() - 1)
			result += ' ';
	}
	return result;

} 
// Задание 2.
bool is_spam(std::string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	static const int spams_number = 4;
	static std::string spams[spams_number]{ //Спамовые словочетания 
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};

	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true; // Спам найден 
	return false; // Спама нету 
}
