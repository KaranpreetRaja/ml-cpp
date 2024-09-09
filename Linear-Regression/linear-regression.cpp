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

double MeanSquaredError(std::vector<double> actual_y, std::vector<double> predicted_y) {
	if (actual_y.size() != predicted_y.size()){
		std::cerr << "Sizes of actual and predicted vectors did not match" << std::endl;
		return 1;
	}
	double sum = 0;
	for (size_t i = 0; i < actual_y.size(); ++i){
		sum += (actual_y[i] - predicted_y[i];
	}

	return (1/ actual_y.size()) * sum;
}

int main()
{
	
	std::string fileName = "Datasets/linear-regression-data.csv";

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
