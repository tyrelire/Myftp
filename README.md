# Epitech Project, first Year -> Myftp

## Description
This project involves the implementation of an FTP (File Transfer Protocol) server in C programming language. The server is designed to handle multiple clients concurrently using TCP sockets. It supports basic FTP functionalities and adheres to the RFC959 protocol standards. The server provides authentication for an Anonymous account with an empty password and supports both active and passive mode data transfers.

## Usage
To run the FTP server, use the following command:

./myftp port path

- `port`: The port number on which the server socket listens.
- `path`: The path to the home directory for the Anonymous user.

## Compilation
The server is compiled via Makefile, which includes rules for `re`, `clean`, and `fclean`. The source files, excluding unnecessary files (such as binaries, temporary files, and object files), must be included in the delivery. Bonus files, including a potential specific Makefile, should be placed in a directory named `bonus`.

## Features
1. **Concurrency**: The server handles multiple clients simultaneously using `select` for command management and `fork` for data transfer. Proper usage of `select` is essential for both reading and writing on sockets.
2. **Authentication**: Supports authentication with an Anonymous account and an empty password.
3. **Data Transfer Modes**: Supports active or passive mode data transfers as per RFC959 specifications.
4. **Error Handling**: Error messages are written to the error output, and the program exits with the 84 error code (0 if no error).
5. **Standard Library**: Utilizes standard C library except for `recv`, `send`, and system calls that make a socket non-blocking.

## Testing
A testing program is provided to verify the connection sequence, though it does not assess buffer management implementation. Installing FTP servers like proftpd or vsftpd on the machine can aid in understanding FTP functionality.

## Notes
Ensure compliance with RFC959 standards and thorough testing to guarantee the reliability and functionality of the FTP server.
