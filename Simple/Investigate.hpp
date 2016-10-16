#pragma once
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

class Investigator {
	
	public:

	Investigator() {
		errs() << "This is the investigator class !!";
	}

}; // end of class  
