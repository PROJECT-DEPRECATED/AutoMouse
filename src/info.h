#include <iostream>
#include <string>
using namespace std;

string programName = "AutoMouse";
string version = "1.0v";
string author = "Project_TL";

void onProgramInfo() {
    system("title AutoMouse-1.0v");
    std::cout << programName << "-" << version << " Made by " << author << "\n"; 
}

void onProgramVersion() {
    std::cout << "[AutoMouse Shell] This program version is " << version << "\n";
}