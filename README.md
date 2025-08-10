# 📡 Minitalk

Minitalk is a small client-server communication program written in C, using only UNIX signals (`SIGUSR1` and `SIGUSR2`).  
The client sends messages **bit by bit**, and the server reconstructs them in real time.

---

## 📜 Description

The purpose of this project is to explore **low-level inter-process communication (IPC)** and **signal handling** in C.  
It implements a basic protocol to transmit strings from a client process to a server process without using sockets or pipes.

---

## 🛠 Features

- Client and server applications in pure C
- Communication entirely via UNIX signals
- Bitwise operations for character encoding and decoding
- Handles message termination and multiple consecutive messages
- Uses `sigaction` for robust and asynchronous signal handling

---

## 🚀 Usage

### 1️⃣ Compile
make

2️⃣ Start the server
./server

3️⃣ Send a message from the client
./client <SERVER_PID> "Your message here"

📂 Project Structure

├── client.c      # Client program
├── server.c      # Server program
├── minitalk.h    # Header file
├── Makefile      # Build rules
└── README.md     # Project documentation

🧠 Skills Developed

Signal handling with sigaction

Inter-process communication (IPC)` in C

Bit manipulation for data transmission

Event-driven programming without blocking loops

Strong debugging skills for asynchronous processes



