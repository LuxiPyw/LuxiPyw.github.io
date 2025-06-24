#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main ()
{

	ifstream file("tableOfGames");
	ofstream outputFile("output");

	if(!file.is_open()) {
		cout << "Error:file.is_open - false" << "\n";
		return 1;
	}
	if(!outputFile.is_open()) {
		cout << "Error:outputFile.is_open - false" << "\n";
		return 1;
	}
	string line = "0";


	int i = 1;
	while(1){

		outputFile << "<tr>" << "\n";
		outputFile << "<th>" << i << "</th>" << "\n";
		while(1){

			getline(file,line);
			if(line == "#") break;
			if(file.eof()){
				goto end;
			}
			outputFile << "<th>" << line << "</th>" << "\n";

		}
		outputFile << "</tr>" << "\n";

		i++;
	}
	end:
	return 0;

}
