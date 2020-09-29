/*===================== begin_copyright_notice ==================================

 Copyright (c) 2020, Intel Corporation


 Permission is hereby granted, free of charge, to any person obtaining a
 copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
======================= end_copyright_notice ==================================*/


//===----------------------------------------------------------------------===//
//
// This file defines GenX kernel metadata operand numbers and other module
// metadata.
//
//===----------------------------------------------------------------------===//

#ifndef GENX_METADATA_H
#define GENX_METADATA_H

namespace llvm {
namespace genx {

namespace FunctionMD {
static constexpr const char GenXKernels[] = "genx.kernels";
static constexpr const char GenXByteOffset[] = "genx_byte_offset";
static constexpr const char GenXVolatile[] = "genx_volatile";
static constexpr const char CMGenXMain[] = "CMGenxMain";
static constexpr const char CMStackCall[] = "CMStackCall";
static constexpr const char CMFloatControl[] = "CMFloatControl";
static constexpr const char CMGenxSIMT[] = "CMGenxSIMT";
static constexpr const char OCLRuntime[] = "oclrt";
static constexpr const char ReferencedIndirectly[] = "referenced-indirectly";
} // namespace FunctionMD

namespace VCModuleMD {
static constexpr const char VCGlobalVariable[] = "VCGlobalVariable";
static constexpr const char VCVolatile[] = "VCVolatile";
static constexpr const char VCByteOffset[] = "VCByteOffset";
} // namespace VCModuleMD

namespace VCFunctionMD {
static constexpr const char VCFunction[] = "VCFunction";
static constexpr const char VCStackCall[] = "VCStackCall";
static constexpr const char VCArgumentIOKind[] = "VCArgumentIOKind";
static constexpr const char VCFloatControl[] = "VCFloatControl";
static constexpr const char VCSLMSize[] = "VCSLMSize";
static constexpr const char VCArgumentKind[] = "VCArgumentKind";
static constexpr const char VCArgumentDesc[] = "VCArgumentDesc";
static constexpr const char VCSIMTCall[] = "VCSIMTCall";
} // namespace VCFunctionMD

enum KernelMDOp {
  FunctionRef,  // Reference to Function
  Name,         // Kernel name
  ArgKinds,     // Reference to metadata node containing kernel arg kinds
  SLMSize,      // SLM-size in bytes
  ArgOffsets,   // Kernel argument offsets
  ArgIOKinds,   // Reference to metadata node containing kernel argument
                // input/output kinds
  ArgTypeDescs, // Kernel argument type descriptors
  Reserved_0,
  BarrierCnt    // Barrier count
};
} // namespace genx
} // namespace llvm

#endif
