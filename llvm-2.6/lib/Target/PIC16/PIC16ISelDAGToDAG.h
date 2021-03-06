//===-- PIC16ISelDAGToDAG.cpp - A dag to dag inst selector for PIC16 ------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the PIC16 target.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "pic16-isel"

#include "PIC16.h"
#include "PIC16ISelLowering.h"
#include "PIC16RegisterInfo.h"
#include "PIC16TargetMachine.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Intrinsics.h"
using namespace llvm;

namespace {

class VISIBILITY_HIDDEN PIC16DAGToDAGISel : public SelectionDAGISel {

  /// TM - Keep a reference to PIC16TargetMachine.
  PIC16TargetMachine &TM;

  /// PIC16Lowering - This object fully describes how to lower LLVM code to an
  /// PIC16-specific SelectionDAG.
  PIC16TargetLowering &PIC16Lowering;

public:
  explicit PIC16DAGToDAGISel(PIC16TargetMachine &tm) : 
        SelectionDAGISel(tm),
        TM(tm), PIC16Lowering(*TM.getTargetLowering()) {}
  
  // Pass Name
  virtual const char *getPassName() const {
    return "PIC16 DAG->DAG Pattern Instruction Selection";
  } 

  virtual void InstructionSelect();
  
private:
  // Include the pieces autogenerated from the target description.
#include "PIC16GenDAGISel.inc"

  SDNode *Select(SDValue N);

  // Match direct address complex pattern.
  bool SelectDirectAddr(SDValue Op, SDValue N, SDValue &Address);

};

}

