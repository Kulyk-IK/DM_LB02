#include <iostream>
#include <vector>

class SetUtils {
public:
	//Об'єднання
	static std::vector<int> association(std::vector<int> &v1, std::vector<int> &v2) {
		std::vector<int> result = v1;

		size_t v1_size = v1.size();
		size_t v2_size = v2.size();
		size_t result_size = v1_size;

		for (int i = 0; i < v2_size; i++) {
			bool isBelong = 0;

			for (int j = 0; j < result_size; j++) {
				if (result[j] == v2[i]) {
					isBelong = 1;
					break;
				}
				else {
					isBelong = 0;
				}
			}

			if (!isBelong)
				result.push_back(v2[i]);
		}
		return result;
	}

	//Перетин
	static std::vector<int> intersection(std::vector<int> &v1, std::vector<int> &v2) {
		std::vector<int> result;

		size_t v1_size = v1.size();
		size_t v2_size = v2.size();

		for (int i = 0; i < v1_size; i++) {
			for (int j = 0; j < v2_size; j++) {
				if (v1[i] == v2[j]) {
					result.push_back(v1[i]);
				}
				else {
					continue;
				}
			}
		}
		return result;
	}

	//Різниця
	static std::vector<int> difference(std::vector<int> &v1, std::vector<int> &v2) {
		std::vector<int> result;

		size_t v1_size = v1.size();
		size_t v2_size = v2.size();

		for (int i = 0; i < v1_size; i++) {
			bool isBelongToB = 0;

			for (int j = 0; j < v2_size; j++) {
				int temp_number = v1[i];

				if (v2[j] == temp_number) {
					isBelongToB = 1;
					break;
				}
			}

			if (!isBelongToB)
				result.push_back(v1[i]);
		}
		return result;
	}

	//Симетрична різниця
	static std::vector<int> symmetrical_difference(std::vector<int>& v1, std::vector<int>& v2) {
		std::vector<int> assoc = association(v1, v2);
		std::vector<int> inter = intersection(v1, v2);
		return difference(assoc, inter);
	}

	//Доповнення
	static std::vector<int> addition(std::vector<int>& u, std::vector<int>& v) {
		return difference(u, v);
	}
};
     
void set_output(std::vector<int>& v) {
	size_t v_size = v.size();

	std::cout << "{";
	for (int i = 0; i < v_size; i++) {
		std::cout << v[i];

		if (i < v_size - 1)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

int main() {
	setlocale(LC_CTYPE, "ukr");
	
	std::vector<int> A = { 1,2,3,4,5,6,7 };
	std::vector<int> B = { 4,5,6,7,8,9,10 };
	std::vector<int> C = { 2,4,6,8 };
	std::vector<int> U = { 1,2,3,4,5,6,7,8,10 };

	std::vector<int> assoc_A_C = SetUtils::association(A, C);
	std::vector<int> addit_C_U = SetUtils::addition(U, C);
	std::vector<int> diff_B_additC = SetUtils::difference(B, addit_C_U);
	std::vector<int> diff_assocAC_C = SetUtils::difference(assoc_A_C, C);
	std::vector<int> symmetrical_left_part_right_part = SetUtils::symmetrical_difference(diff_assocAC_C, diff_B_additC);
	
	std::cout << "A U C = ";
	set_output(assoc_A_C);

	std::cout << "\n";

	std::cout << "~C = ";
	set_output(addit_C_U);

	std::cout << "\n";

	std::cout << "B \\ ~C = ";
	set_output(diff_B_additC);

	std::cout << "\n";

	std::cout << "(A U C) \\ C = ";
	set_output(diff_assocAC_C);

	std::cout << "\n";

	std::cout << "(A U C) \\ C ^ (B \\~C) = ";
	set_output(symmetrical_left_part_right_part);
	
	return 0;
}