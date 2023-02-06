install.packages(".", type = "source", repos = NULL)
library(RPointer)

b <- bools$new(10)
b$print()
b$delete()

i <- integer$new(5)
i[[1]] <- 2
i$print()
i$resize(4)
i$print()
i$delete()


d <- numeric$new(6)
d[[1]] <- 4
d[[2]] <- d[[1]]*5
d$print()
d$delete()
