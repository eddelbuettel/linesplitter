
## linesplitter: R Example Package for nanoarrow Example

A simple wrapper for the example from the `nanoarrow` documentation

### Example

```r
> library(linesplitter)
> example(linesplit)

lnsplt> txt <- "the\nquick\nbrown\nfox"

lnsplt> linesplit(txt)
<nanoarrow_array string[4]>
 $ length    : int 4
 $ null_count: int 0
 $ offset    : int 0
 $ buffers   :List of 3
  ..$ :<nanoarrow_buffer validity<bool>[0][0 b]> ``
  ..$ :<nanoarrow_buffer data_offset<int32>[5][20 b]> `0 3 8 13 16`
  ..$ :<nanoarrow_buffer data<string>[16 b]> `thequickbrownfox`
 $ dictionary: NULL
 $ children  : list()

lnsplt> linesplit(txt, TRUE)
Array
<string>
[
  "the",
  "quick",
  "brown",
  "fox"
]
>
```

### Author

For the sample package, Dirk Eddelbuettel.

The underlying `nanoarrow` example is by Dewey Dunnington.
