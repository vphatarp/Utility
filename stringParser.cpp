
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

//The entire logic for parsing is in the method below
void stringParser::parseString(std::vector<std::string> &vec, std::string line){
	size_t pos;
        //Stores the position of the delimiter
	int i=0;
        //npos is the last possible position
        //Here the position of the delimiter is checked
	while((pos = line.find(delimiter)) != std::string::npos){
               //the statement below parses the string till pos but excluding it
               //So what we get in vec is the first string
		vec[i] = line.substr(0, pos);
               //The above command does not modify the string
               //The line below takes out the already processes part of the string
		line.erase(0, pos+delimiter.length());
		i++;
	}
        //Since for the last string the delimiter would not exist
        //It would be saved outside the loop
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
