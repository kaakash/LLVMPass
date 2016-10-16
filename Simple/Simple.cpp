#define DEBUG_TYPE "simple"

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include <map>
#include <string>     // std::string, std::to_string
#include "Investigate.hpp"

using namespace llvm;

namespace {
struct CountOp : public FunctionPass {

    std::map <std::string, int> opCounter;

    static char ID;

    CountOp() : FunctionPass(ID) {}

    virtual bool runOnFunction (Function &F) {

      Investigator myInvestigator;

      errs() << "Function " << F.getName() << '\n';
      int count = 0;
      for (Function::iterator bb = F.begin(), e = F.end(); bb != e; ++bb)
      {
        for (BasicBlock::iterator i = bb->begin(), e = bb->end(); i != e; ++i) 
	{
		count ++;
		errs() << std::to_string(count) << "\t" << i->getOpcodeName() << "\n";

		if(opCounter.find(i->getOpcodeName()) == opCounter.end()) 
		{
			opCounter[i->getOpcodeName()] = 1;
          	} else {
			opCounter[i->getOpcodeName()] += 1;
          	}
        }
      }
      std::map <std::string, int>::iterator i = opCounter.begin();
      std::map <std::string, int>::iterator e = opCounter.end();
      while (i != e) {
        errs() << i->first << ": " << i->second << "\n";
	i++;
      }
      errs() << "\n";
      opCounter.clear();
      return false;
    }
  };
}
char CountOp::ID = 0;
static RegisterPass<CountOp> X("simple", "Counts opcodes per functions");
