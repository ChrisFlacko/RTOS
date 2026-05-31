FROM ubuntu:24.04

# Avoid prompts during build
ENV DEBIAN_FRONTEND=noninteractive

# Install build tools and ARM development tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    gcc-arm-none-eabi \
    gdb-multiarch \
    git \
    python3 \
    python3-pip \
    openssh-client \
    ca-certificates \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user for development
RUN useradd -m -s /bin/bash developer

# Set working directory
WORKDIR /workspace

# Switch to non-root user
USER developer
