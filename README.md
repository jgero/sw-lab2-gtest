# Lab 2 book examples

## usage

1. run `make` to build docker image
2. run `make run` to start docker container
3. examples are mounted to `/app` in the container (run `cd /app` in the console of the container)
  - because the examples are mounted into the container, changes you make to the files on your system will also appear in the container
4. change dir into any of the example directories and run `make` to build the tests
5. run the executeable generated by the `make` command (ex: `./dertest`)

## notes

The examples are from [this website by the author of the book Lean Testin für C++ Programmierer](http://leantesting.de/).
In the book gtest version 1.7.0 is used, which is also used in this docker container.

A very small modification had to be made in the `include.mf` file because of an error when compiling the test. The solution and 
modification are as described in [this question on StackOverflow](https://stackoverflow.com/questions/10315016/error-during-making-gtest).

On Mac the `make run` my fail, then it has to be run manually with the volume mount in quotations (... `-v "$(pwd)/beispiele:/app" ...`).

Not tested with docker for Windows.
