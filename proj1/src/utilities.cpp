#include "../includes/utilities.h"

#include <vector>
#include <string>

#include <cstring>

#include <cctype>
#include <locale>
#include <fstream>
#include <algorithm>
#include <iostream>


using namespace std;

vector<process_stats> myVec;
fstream myFile;



//allthe functions available for use

//clears vector holding process_stats structs
//attempt to open file 'filename' to read, parse its rows
//into process_stats structs and add these structs to a vector
//
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int loadData(const char* filename) {

	myVec.clear();

	ifstream infile;
	infile.open(filename);

	if (infile.is_open()) {

		while (infile.is_open()) {

			while (!infile.eof()) {
				std::string tmp;

				getline(infile, tmp, '\n');

				//call sortData which will modify tmp into "XXX" format,
				//each 'X' signifying one of the fields of each struct
				sortData
				//then this info is pushed into the struct
				//the struct is then pushed to the vector

				}
		}
		infile.close();
		return SUCCESS;
	}
	else {
		return COULD_NOT_OPEN_FILE;
	}

}

//attempt to open file 'filename' to write, and serialize a
//vector full of process_stats structs to it.  Should be in the same
//format as original file but not necessarily the same order or length
//if the file exists, overwrite its contents.
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int saveData(const char* filename) {

	ifstream infile;
		infile.open(filename);

		if (infile.is_open()) {

			while (infile.is_open()) {

				while (!infile.eof()) {
					std::string tmp;

					getline(infile, tmp, '\n');

					//1.trim all white space
					//2.grab 3 values b/t commas

					process_stats tmpstruct;

					std::string delim = ",";

					//std::string::iterator it1 = tmp.begin();

					//std::string *it1 = tmp.begin();

					std::string trimmedStr;

					//removes white space
					for (unsigned int i = 0; i < tmp.size(); i++) {

						if((tmp.at(i) >= 48 && tmp.at(i) <= 57) || tmp.at(i) == 44) {
							trimmedStr = trimmedStr + tmp.at(i);
						}
					}


					  char * cstr = new char [trimmedStr.length()+1];
					  std::strcpy (cstr, trimmedStr.c_str());


					char * p = std::strtok (cstr, ",");


					std::string toBeInt = tmp.substr(0, tmp.find(delim));


					//call sortData which will modify tmp into "XXX" format,
					//each 'X' signifying one of the fields of each struct
					//then this info is pushed into the struct
					//the struct is then pushed to the vector

					}
			}
			infile.close();
			return SUCCESS;
		}
		else {
			return COULD_NOT_OPEN_FILE;
		}
}

//sorts the vector, returns nothing (thats what void means)
//sorts low to high
void sortData(SORT_ORDER mySortOrder) {

}

//return the first struct in the vector
//then deletes it from the vector
process_stats getNext() {
	//process_stats tmp;
	process_stats tmp = myVec.front();
	myVec.begin();




}
