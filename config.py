#!/usr/bin/python
"""
This python code will get the LLVM build for a simple pass ready for compilation
"""
import os

def read_src_location():
	"""
	This function reads the llvm src location
	"""
	srcLoc = raw_input("Enter the location where the LLVM source resides:");
	return srcLoc;

def read_build_location():
	"""
	This function reads the build location
	"""
	buildLoc = raw_input("Enter the location where the LLVM source resides:");
	return buildLoc;

def processInputsAndAct():
	"""
	This function will make the correct location for placing the pass 
	place the pass in the location and try an honest make.
	"""
	copyDestination = read_src_location() + "/lib/Transforms/."
	command = "\cp -rf ./Simple " + copyDestination 
	retval = os.system(command)
	return retval;

# Call the main routine
processInputsAndAct()		


