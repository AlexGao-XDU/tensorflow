/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CORE_TRANSFORMS_GRAPH_TO_FUNC_PASS_H_
#define TENSORFLOW_CORE_TRANSFORMS_GRAPH_TO_FUNC_PASS_H_

#include <memory>
#include <string>

#include "mlir/Pass/Pass.h"  // from @llvm-project
#include "mlir/Support/LLVM.h"  // from @llvm-project

namespace mlir {
namespace tfg {

// Returns a pass that runs on a Module and expects to find a single GraphOp
// to transform into a function. The provided feeds and fetches are used to form
// the function arguments and returned values.
std::unique_ptr<Pass> CreateGraphToFuncPass(
    ArrayRef<std::string> feeds = {}, ArrayRef<std::string> fetches = {},
    ArrayRef<std::string> control_rets = {});

}  // namespace tfg
}  // namespace mlir

#endif  // TENSORFLOW_CORE_TRANSFORMS_GRAPH_TO_FUNC_PASS_H_
