
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <future>
#include <unordered_map>
#include <fstream>
#include <vector>

class stringParser{
	std::string delimiter;
public:
	stringParser(std::string del = " "):delimiter(del){}
	void parseString(std::vector<std::string>& vec, std::string line);
};

void stringParser::parseString(std::vector<std::string> &vec, std::string line){
	size_t pos;
	int i=0;
	while((pos = line.find(delimiter)) != std::string::npos){
		vec[i] = line.substr(0, pos);
		line.erase(0, pos+delimiter.length());
		i++;
	}
	vec[i] = line;
}
int main(){
	std::ifstream ifile;
	ifile.open("file.csv");
	std::string line;
	std::vector<std::string> vec = std::vector<std::string>(3);
	stringParser sParse(",");
	while(ifile >> line){
		sParse.parseString(vec, line);
		std::cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<"\n";
	}
}
