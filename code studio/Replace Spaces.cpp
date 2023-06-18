// Replace Spaces
// Sample Input 1:
// 2
// Coding Ninjas Is A Coding Platform
// Hello World
// Sample Output 1:
// Coding@40Ninjas@40Is@40A@40Coding@40Platform
// Hello@40World
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	int n = str.length();
	string s="";
	for(int i=0;i<n;i++)
	{
		if(str.at(i) == ' '){
			s.push_back('@');
			s.push_back('4');
			s.push_back('0');
		}
		else{
			s.push_back(str.at(i));
		}
	}
	return s;
}

//python
from os import *
from sys import *
from collections import *
from math import *

def replaceSpaces(str):
    return str.replace(" ","@40")