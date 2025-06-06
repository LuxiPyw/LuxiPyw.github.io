#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void make_html (string htm_name) 
{
	cout << htm_name << "\n";
	string path_htm = string("htm/")+htm_name+string(".htm");
	string path_html = string("../site/")+htm_name+string(".html");
	cout << path_htm << "\n";
	ifstream Input (path_htm);
	ofstream Output (path_html);
	string line;
	if(!Input.is_open()){
		cout << "1error could not open file" << "\n";
		cout << "path:" << path_htm << "\n";
		return;
		
	}
	if(!Output.is_open()){
		cout << "2error could not open file" << "\n";
		cout << "path:" << path_html << "\n";
		Input.close();
		return;
	}
	Output << R"(<!DOCTYPE html> <html>
		<head>
		<meta charset="utf-8">
		<title>htm_name</title>
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<link href="../links/main.css" type="text/css" rel="stylesheet"/>
		</head>
		<body>
		<header>
		<nav class="navigation">
		<a href="index.html">home</a>
		<a href="gamereviews.html">game reviews</a>
		<a href="programming.html">programming</a>
		<a href="stuff.html">stuff</a>
		</nav>
		</header>
		<main>)";

	
	while(1){

		getline(Input,line);
		if(Input.eof())break;
		Output << line;

	}



	Output << R"(
	</main>
	<footer>
	<div>Footer block<div>
	</footer>
	</body>

	</html>)";
}

void load_lexicon ()
{

	ifstream File ("lolicon/lexicon");
	string htm_name;
	if(!File.is_open()){

		cout << "lolicon error could not open file" << "\n";
		return;
	}
	//strig cpp + char[] + string cpp

	while(1){
	getline(File,htm_name);
	if(File.eof())break;
	cout << htm_name << "\n";
	make_html(htm_name);
	}

}

void make_site ()
{

	load_lexicon();

}
int main ()
{

	make_site();

}
