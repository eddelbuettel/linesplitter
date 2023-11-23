
library(linesplitter)

txt <- "the\nquick\nbrown\nfox"
expect_silent(res <- linesplit(txt))
expect_inherits(res, "nanoarrow_array")

if (!requireNamespace("arrow", quietly=TRUE)) exit_file("need arrow")
expect_silent(res <- linesplit(txt, TRUE))
expect_inherits(res, "Array")
expect_silent(vec <- res$as_vector())
expect_equal(vec, strsplit(txt, "\n")[[1]])
