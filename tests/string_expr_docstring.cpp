#include <iostream>
#include <string>

#include <Eigen/Core>
#include <npe.h>

const std::string docstr = "this is the docstr";

npe_function(string_expr_docstring)
npe_arg(a, dense_f64, dense_f32)

// This is a comment

// and another
npe_doc(docstr.c_str())

// and another comment
// and enen one more
npe_begin_code()

a(0, 0) = 2.0;

return NPE_MOVE_DENSE_MAP(a);

npe_end_code()
