
#include <Rcpp/Lightest>
#include "nanoarrow/nanoarrow.hpp"
#include "linesplitter/linesplitter.h"

#include "extptr.h"

//' Plain Interface
//' @noRd
// [[Rcpp::export]]
bool linesplit_from_R_plain(const std::string str, SEXP sxparr) {
    // We get an R-created 'nanoarrow_array', an S3 class around an external pointer
    if (!Rf_inherits(sxparr, "nanoarrow_array"))
        Rcpp::stop("Expected class 'nanoarrow_array' not found");

    // It is an external pointer so we can use R_ExternalPtrAddr()
    struct ArrowArray* arr = (struct ArrowArray*)R_ExternalPtrAddr(sxparr);

    auto res = linesplitter_read(str, arr);
    return true;
}

// //' Alternate nice C++ Interface
// //'
// //' NB This requires a file inst/include/linesplitter_types.h to define ArrowArray
// //' for use in the RcppExport wrappers.
// //' @noRd
// // [[Rcpp::export]]
// bool linesplit_from_R(const std::string str, Rcpp::XPtr<ArrowArray> sxparr) {
//     // We get an R-created 'nanoarrow_array', an S3 class around an external pointer
//     // Rf_inherits gets the S3 class string, and the helper function use that.
//     assert_xptr_inherits(sxparr, "nanoarrow_array");
//     // It is a straight up external pointer so we can use R_ExternalPtrAddr() or .get()
//     // struct ArrowArray* arr = (struct ArrowArray*)R_ExternalPtrAddr(sxparr);
//     auto res = linesplitter_read(str, sxparr.get());

//     return true;
// }
