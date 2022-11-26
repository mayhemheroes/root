FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake libx11-dev libxpm-dev libxft-dev libxext-dev python-is-python3 libssl-dev binutils git clang

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/install
RUN make -j8
RUN make install
RUN clang++ /repo/mayhem/fuzz_Log2.cpp -fsanitize=fuzzer,address -L /install/lib/ -lMathCore -o /fuzz

FROM ubuntu:22.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential
COPY --from=builder /install /install
COPY --from=builder /fuzz /fuzz_Log2
ENV LD_LIBRARY_PATH=/install/lib
