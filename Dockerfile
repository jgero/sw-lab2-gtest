FROM ubuntu:focal

ARG DEBIAN_FRONTEND=noninteractive

# timezone stuff
ENV TZ=Europe/Berlin
RUN apt-get update -y && \
    apt-get install -y tzdata

# install packages for c++ development
RUN apt-get install -y --no-install-recommends\
                    git \
                    curl \
                    gcc-9 \
                    g++ \
                    clang-10 \
                    build-essential \
                    cmake \
                    unzip \
                    tar \
                    ca-certificates && \
    apt-get autoclean && \
    apt-get autoremove && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# install GoogleTest like shown in https://github.com/google/googletest/blob/master/googletest/README.md
RUN mkdir -p /home/me/programme && \
    cd /home/me/programme && \
    git clone https://github.com/google/googletest.git -b release-1.7.0 gtest && \
    cd gtest && \
    mkdir lib && \
    cd lib && \
    cmake .. && \
    make
