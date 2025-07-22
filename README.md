# 📨 minitalk – 42 School's Signal-based Messaging

![42 Badge](https://img.shields.io/badge/42-Minitalk-blue)

*A minimalist client/server communication project using Unix signals, built as part of the 42 School curriculum.*

---

## 🚀 Overview

**minitalk** is a small C project that implements inter-process communication between two user programs:
- a **server** that receives messages, and
- a **client** that sends messages.

The client encodes each character of a string into bits and sends them bit by bit to the server via Unix signals (`SIGUSR1` and `SIGUSR2`).
The server decodes the bits and reconstructs the original message.

---
