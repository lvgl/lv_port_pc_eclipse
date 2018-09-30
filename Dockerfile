# To see how to do GUI forwarding in macOS:
#     https://cntnr.io/running-guis-with-docker-on-mac-os-x-a14df6a76efc

FROM ubuntu:16.04

RUN apt update && apt install -y \
    build-essential \
    cmake \
    gcc \
    git \
    libsdl2-dev \
    mesa-utils \
    libgl1-mesa-glx

RUN git clone --recursive https://github.com/littlevgl/pc_simulator.git \
    && cd pc_simulator \
    && make

CMD ["./pc_simulator/demo"]
