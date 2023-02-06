# RPointer

A small and **very dangerous** R package. You can create a vector on the heap from R. Therefore, three classes exist: *bool*, *integer* and *numeric* which create the memory during the construction. The memory is not automatically freed. You have to use the method *delete* in order to three the memory. Furthermore, the following methods are implemented:

* size --> returns the size of the vector
* print --> prints vector elements on console
* [[ --> for indexing; Index starts at 0 not 1!
* resize --> for resizing the vector

```
# Installation:
remotes::install_github("konrad1991/RPointer")
# bool values
b <- bools$new(10)
b$print()
b$delete()
# integer vector
i <- integer$new(5)
i[[1]] <- 2
i$print()
i$resize(4)
i$print()
i$delete()
# double vector
d <- numeric$new(6)
d[[1]] <- 4
d[[2]] <- d[[1]]*5
d$print()
d$delete()
```