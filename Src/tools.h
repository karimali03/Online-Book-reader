#include <iostream>
using namespace std;
#include <vector>
#include<fstream>

#ifndef TOOLS_H
#define TOOLS_H

 string current_date(){
     // current date/time based on current system
    time_t now = time(0);
   // convert now to string form
   char* dt = ctime(&now);
   return dt;
}

int ReadInt(int low, int high, bool cancel_choice_allowed = false) {
	
	while(1){
     if(!cancel_choice_allowed)
		cout << "\nEnter number in range " << low << " - " << high << ": ";
	else
		cout << "\nEnter -1 to cancel or number in range " << low << " - " << high << ": ";
        int ch; cin>>ch;
        if(ch==-1 && cancel_choice_allowed ) return -1;
        if(ch >=low && ch<=high ) return ch;
        cout<<"Please Enter a valid number\n\n";
    }
}

int ShowReadMenu(const vector<string> &choices, string header="",string ending="") {	// Added parameter. Respect backward compatibility
	if(!header.empty()) cout << "\n"<<header<<":\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
    if(!ending.empty()) cout<<"\n"<<ending<<":\n";
	return ReadInt(1, choices.size());
}

vector<string> ReadFileLines(const string &path) {
	vector<string> lines;

	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return lines;
	}
	string line;

	while (getline(file_handler, line)) {
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
	return lines;
}

void WriteFileLines(const string &path, const vector<string> &lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// overwrite

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (const auto &line : lines)
		file_handler << line << "\n";

	file_handler.close();
}

vector<string> SplitString(const string &str, const string &delimiter = ",") {
	string s = str;
	vector<string> strs;

	int pos = 0;
	string substr;
	while ((pos = (int) s.find(delimiter)) != -1) {
		substr = s.substr(0, pos);
		strs.push_back(substr);
		s.erase(0, pos + delimiter.length());
	}
	strs.push_back(s);
	return strs;
}


#endif 
