#include <tuple>
#include <Eigen/Core>
#include "numpyeigen_utils.h"

// This defines a function named 'test_binding' which will be exposed to python
npe_function("test_binding")

// This says test binding takes as input a dense Eigen matrix, 'a', which can have scalar
// type dense_f32 (float) or dense_f64 (double).
// The variable 'a' has type Eigen::Map with scalar matching one of the input types. This means
// the corresponding Python function takes a numpy array whose dtype is float32 or float64
npe_arg("a", "dense_f32", "dense_f64")

// This is another input variable, 'b'. It's type is a matches() statement. In this case, the matches() says that the
// type of 'b' must match the type of 'a'. matches() statements can only match to numpy overloaded variables.
npe_arg("b", "matches(a)")

// Here is another variable 'c' and two variables whose types have to match it.
npe_arg("c", "dense_i32", "dense_i64")
npe_arg("d", "matches(c)")
npe_arg("e", "matches(d)")

// This is a non-numpy overloaded input parameter of type int.
npe_arg("f", "int")

// After this directive is the actual source code of the bound function
npe_begin_code()


// We compute some return values using the types specified in the input. So, for example,
// if you pass in matrices of doubles, you get the result as a matrix of doubles
Matrix_a ret1 = a + b;
Matrix_c ret2 = c + d + e * f;

// MOVE_TO_NP returns a pybind11::array which takes ownership of the Eigen::Matrix passed as a second argument.
// The first argument is the type of the Eigen::Matrix
// return std::make_tuple(NPE_MOVE(npe::Matrix_a, ret1), NPE_MOVE(npe::Matrix_c, ret2));
return std::make_tuple(NPE_MOVE_DENSE(ret1), NPE_MOVE_DENSE(ret2));
npe_end_code()


