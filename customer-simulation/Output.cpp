#include "Output.h"
#include <string>
void Output::printVector(std::vector<int> output)
{
	std::string outputString = "";
	for (int s : output) {
		outputString += std::to_string(s) + ", ";
	}
	if (!outputString.empty()) {
		outputString = outputString.substr(0, outputString.size() - 2);
	}
	std::cout << "You entered: " << outputString << std::endl;
}
