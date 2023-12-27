#' Example Wrapper for 'linesplit' Example
#'
#' @param str A single character value containing several lines separated by newline
#' characters
#' @param return_as_arrow A boolean flag to enable Arrow object return
#' @return The incoming line split and returned as either a 'nanoarrow' array or an
#' 'Arrow' array
#' @examples
#' txt <- "the\nquick\nbrown\nfox"
#' linesplit(txt)
#' linesplit(txt, TRUE)
linesplit <- function(str, return_as_arrow=FALSE) {
    stopifnot("str must be character" = is.character(str),
              "return_as_arrow must be logical" = is.logical(return_as_arrow))

    arr <- nanoarrow_allocate_array()
    stopifnot("arr does not already hold a value" = !nanoarrow_pointer_is_valid(arr),
              "arr is nanoarrow_array" = inherits(arr, "nanoarrow_array"))

    ##linesplit_impl(str, arr)
    linesplit_from_R_plain(str, arr)
    stopifnot("arr valid after linesplit" = nanoarrow_pointer_is_valid(arr))

    nanoarrow_array_set_schema(arr, na_string())

    if (return_as_arrow) {
        stopifnot("return_as_arrow requires 'arrrow'" = requireNamespace("arrow", quietly=TRUE))
        arrow::Array$create(arr)
    } else {
        arr
    }
}
