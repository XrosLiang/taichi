#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "taichi/inc/constants.h"
#include "taichi/lang_util.h"
#include "taichi/backends/metal/data_types.h"
#include "taichi/backends/metal/kernel_util.h"
#include "taichi/backends/metal/runtime.h"
#include "taichi/program/program.h"
#include "taichi/struct/struct_metal.h"

TLANG_NAMESPACE_BEGIN
namespace metal {

class MetalCodeGen {
 public:
  MetalCodeGen(const std::string &kernel_name,
               const StructCompiledResult *struct_compiled);

  FunctionType compile(Program &, Kernel &kernel, MetalRuntime *runtime);

 private:
  void lower();
  FunctionType gen(const SNode &root_snode, MetalRuntime *runtime);

  const int id_;
  const std::string taichi_kernel_name_;
  const StructCompiledResult *const struct_compiled_;

  Program *prog_;
  Kernel *kernel_;
  size_t global_tmps_buffer_size_{0};
};

}  // namespace metal

TLANG_NAMESPACE_END
