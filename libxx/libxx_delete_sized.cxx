//***************************************************************************
// libxx/libxx_delete_sized.cxx
//
//   Copyright (C) 2007 Gregory Nutt. All rights reserved.
//   Author: Gregory Nutt <gnutt@nuttx.org>
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in
//    the documentation and/or other materials provided with the
//    distribution.
// 3. Neither the name NuttX nor the names of its contributors may be
//    used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
// OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
// AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//***************************************************************************

//***************************************************************************
// Included Files
//***************************************************************************

#include <nuttx/config.h>

#include "libxx.hxx"

//***************************************************************************
// Operators
//***************************************************************************

//***************************************************************************
// Name: delete
//
// NOTE:
//   This should take a type of size_t.  But size_t has an unknown underlying
//   type.  In the nuttx sys/types.h header file, size_t is typed as uint32_t
//   (which is determined by architecture-specific logic).  But the C++
//   compiler may believe that size_t is of a different type resulting in
//   compilation errors in the operator.  Using the underlying integer type
//   instead of size_t seems to resolve the compilation issues. Need to
//   REVISIT this.
//
//***************************************************************************

//void operator delete(FAR void *ptr, std::size_t size)
#ifdef CONFIG_CXX_NEWLONG
void operator delete(FAR void *ptr, unsigned long size)
#else
void operator delete(FAR void *ptr, unsigned int size)
#endif
{
  lib_free(ptr);
}