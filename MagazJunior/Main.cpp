#include <iostream> //для консоли походу
#include <windows.h> //для ру языка пока что


int main() {
	SetConsoleOutputCP(CP_UTF8); //принт на ру
	SetConsoleCP(CP_UTF8); //инпут ру

	std::string asort_type[3]{ "фруктовые", "овощные", "чаи" };

	std::string tea[2]{ "петрушевый", "чесночный" };
	int tea_price[2]{ 100, 150 };


	std::string fruts[4]{ "яблочный", "апельсиновый", "абрикосовый", "Грушевый" };
	int fruts_price[4]{ 90, 200, 150, 120 };


	std::string vigetabl[3]{ "Томатный", "луковый", "огуречный" };
	int vigetabl_price[3]{ 110, 90, 100 };



	std::string shop_list[9]{ "петрушевый", "чесночный" ,"яблочный", "апельсиновый", "абрикосовый", "Грушевый" , "Томатный", "луковый", "огуречный" };
	int shop_litr[9]{};
	int shop_price[9]{ 100, 150 , 90, 200, 150, 120,110, 90, 100 };



	bool on_off = true;


	int choice = 0;
	int asort_item_num = 0;

	while (true) {
		std::cout << "\n\n\n\tВыберите категорию:\n";
		for (int i = 0; i < 3; i++) {
			std::cout << "\t[" << i + 1 << "]" << asort_type[i] << "\n";
		}

		std::cout << "[4] перейти в корзину\n[5]Купить настойку\nВведите номер типа соков: ";
		std::cin >> choice;
		choice -= 1;

		if (choice == 0) {
			if (on_off) {
				for (int i = 0; i < 4; i++) {
					std::cout << "\t[" << i + 1 << "]" << fruts[i] << " " << fruts_price[i] << " рублей\n";
				}
				std::cout << "\nВведите номер товара который хотите купить: ";
				std::cin >> asort_item_num;
				asort_item_num -= 1;
				if (asort_item_num < 4) {
					for (int i = 0; i < 9; i++) {
						if (fruts[asort_item_num] == shop_list[i]) {
							int x = 0;
							std::cout << "\nВведите сколько вы хотите взять " << shop_list[i] << " в литрах : \n";
							std::cin >> x;
							shop_litr[i] = x;
							std::cout << x << " литров успешно добавлены";
							break;
						}
					}
				}
				else {
					std::cout << "\n\n\nневерный ввод";
				}
			}
			else {
				std::cout << "\n\nВы выбрали настойку вас нельзя сейчас выбрать фруктовый сок\n\n\n";
			}



		}
		else if (choice == 1) {
			for (int i = 0; i < 3; i++) {
				std::cout << "\t[" << i + 1 << "]" << vigetabl[i] << " " << vigetabl_price[i] << " рублей\n";
			}
			std::cout << "Введите номер товара который хотите купить: ";
			std::cin >> asort_item_num;
			asort_item_num -= 1;

			if (asort_item_num < 4) {
				for (int i = 0; i < 9; i++) {
					if (vigetabl[asort_item_num] == shop_list[i]) {
						int x = 0;
						std::cout << "\nВведите сколько вы хотите взять " << shop_list[i] << " в литрах : \n";
						std::cin >> x;
						shop_litr[i] = x;
						std::cout << x << " литров успешно добавлены";
						break;
					}
				}
			}
			else {
				std::cout << "\n\n\nневерный ввод";
			}



		}
		else if (choice == 2) {
			for (int i = 0; i < 2; i++) {
				std::cout << "\t[" << i + 1 << "]" << tea[i] << " " << tea_price[i] << " рублей\n";
			}
			std::cout << "Введите номер товара который хотите купить: ";
			std::cin >> asort_item_num;
			asort_item_num -= 1;



			if (asort_item_num < 4) {
				for (int i = 0; i < 9; i++) {
					if (tea[asort_item_num] == shop_list[i]) {
						int x = 0;
						std::cout << "\nВведите сколько вы хотите взять " << shop_list[i] << " в литрах : \n";
						std::cin >> x;
						shop_litr[i] = x;
						std::cout << x << " литров успешно добавлены";
						break;
					}
				}
			}
			else {
				std::cout << "\n\n\nневерный ввод";
			}
		}
		else if (choice == 3) {
			int sum = 0;

			int skidka_sum = 0;

			for (int i = 0; i < 9; i++) {


				std::cout << shop_list[i] << " Вы взяли его - " << shop_litr[i] << " Литров\n";

				sum += shop_litr[i] * shop_price[i];

			}
			std::cout << "\n\n\nСумрано к оплате у вас: " << sum << " рублей [БЕЗ СКИДОК]";

			for (int i = 0; i < 9; i++) {
				if (shop_list[i] == "петрушевый") {
					if (shop_litr[i] >= 3) {
						std::cout << "\n\n скидка на петрушевый чай применилась!";
						skidka_sum += (shop_litr[i] * shop_price[i]) * 0.95;
						continue;
					}
				}
				if (shop_list[i] == "луковый") {
					if (shop_litr[i] >= 4) {
						skidka_sum += ((shop_litr[i] * shop_price[i])) - (shop_price[i] * (shop_litr[i] / 4));
						std::cout << "\n\n скидка на луковый сок применилась!";
						continue;
					}
				}
				skidka_sum += shop_litr[i] * shop_price[i];
			}

			if (skidka_sum >= 2000) {
				skidka_sum = skidka_sum * 0.87;
			}

			std::cout << "\n\nОплата вместе со скидкой" << skidka_sum << " рублей";
		}
		else if (choice == 4) {
			if (not on_off) {
				while (true) {
					int nastyka = 0;
					std::cout << "Выберите номер насйтоки\n[1] боярышник - 300 рублей\n[INFO] если вы выбрите ее то не сможете выбрать фруктовый сок\nВведите номер настойки: ";
					std::cin >> nastyka;
					if (nastyka == 1) {
						on_off = true;

						int nast_litr = 0;
						std::cout << "Вы успешно выбрали настойку (боярышник) введите сколько хотите литров: ";
						std::cin >> nast_litr;


						std::cout << nast_litr << " литров успешно добавлено";
						break;
					}
					else {
						std::cout << "Нетут такого ответа";
					}
				}
			}
			else {
				std::cout << "Вы выбрали фруктовый сок теперь нельзя выбрать настойку)";
			}

		}
		else {
			std::cout << "\n\n\tТакого варинта нету!!\n\n\n";
		}
	}

	return 0;
}