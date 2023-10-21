#!/usr/bin/python3

''' 
	This is a script to create a class with a header and a .cc file.
	To use it, type in the terminal: python3 classa2.py <class name>.
	<class name> is the name of the class you want to create 
	in all lowercase letters.

	For example: 
	
		python3 classa2.py person
	
	creates a class named Person with a Person.h file and a Person.cc file.
	Feel free to modify the code to your liking.
	
	Because boilerplate code is boring.
'''
import sys

if len(sys.argv)<2:
	print("no class name detected")
	exit()
	
cl = sys.argv[1]

caps = cl.upper()
title = cl[0].upper()+cl[1:]
ch = cl[0]
print(title)

result = '''#ifndef {caps}_H
#define {caps}_H

#include <iostream>
#include <string>

using namespace std;

class {title} {{
		
	public:
		//constructors
		{title}();
		{title}(const {title}&);

		//destructor
		~{title}();

		
		void print() const;
	
	private:
	
}};
#endif'''.format(caps = caps,title = title)

f = open(title+".h",'w')
f.write(result)
f.close()

result = '''
#include "{title}.h"

{title}::{title}(){{

}}

{title}::{title}(const {title}& {ch}){{

}}

{title}::~{title}(){{

}}


void {title}::print() const{{

}}'''.format(title = title, cl = cl, ch = ch)

f = open(title+".cc",'w')
f.write(result)
f.close()
