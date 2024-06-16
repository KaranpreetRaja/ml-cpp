#include<vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::vector<std::string> splitCSV(const std::string &s) {
	std::vector<std::string> elements;
	std::string element;
	std::istringstream elemStream(s);
	while (std::getline(elemStream, element, ',')){
		elements.push_back(element);
	}
	return elements;

}

int main()
{
	
	std::string fileName = "Datasets/linear-regression.csv";

	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cerr << "Failed to open dataset file " << fileName << std::endl;

		return 1;
	}
	
	std::vector<std::pair<double, double>> data;
	std::string lineBuffer;

	while (std::getline(file, lineBuffer)) {
			std::vector<std::string> row = splitCSV(lineBuffer);

			if (row.size() == 2) {
				double first = std::stod(row[0]);
				double second = std::stod(row[1]);

				data.emplace_back(first, second);
			}
		}
	
	file.close();

	for (const auto &p : data){
		std::cout << p.first << ", " << p.second << std::endl;
	}
	
	return 0;

}
