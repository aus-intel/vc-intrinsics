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


#ifndef VCINTR_IR_ALIGNMENT_H
#define VCINTR_IR_ALIGNMENT_H

#include <llvm/IR/Instructions.h>

namespace VCINTR {

namespace Align {

#if VC_INTR_LLVM_VERSION_MAJOR <= 9
template <class TValue> unsigned getAlign(TValue *Val) {
  return Val->getAlignment();
}
#elif VC_INTR_LLVM_VERSION_MAJOR <= 10
template <class TValue> llvm::MaybeAlign getAlign(TValue *Val) {
  // LLVM 10 instructions accept MaybeAlign but do not provide
  // getMaybeAlignMethod
  return llvm::MaybeAlign(Val->getAlignment());
}
#else
template <class TValue> llvm::Align getAlign(TValue *Val) {
  return Val->getAlign();
}
#endif

} // namespace Align

} // namespace VCINTR

#endif // VCINTR_IR_ALIGNMENT_H
