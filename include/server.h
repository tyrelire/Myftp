/*
** EPITECH PROJECT, 2024
** server.h
** File description:
** server.h
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#ifndef SERVER_H_
    #define SERVER_H_

    #define WELCOME_MESSAGE "220 Service ready for new user.\n"
    #define MAX_CLIENTS 15

typedef struct server {
    int port;
    int socket;
    char *path;
    fd_set tmp_reads;
    fd_set reads;
    char *user[MAX_CLIENTS];
    char *password[MAX_CLIENTS];
    char *cwd[MAX_CLIENTS];
    char buffer[1024];
    int max_client;
    int cl_s[MAX_CLIENTS];
    char cl_b[MAX_CLIENTS][1024];
    int max_sd;
} server_t;

void my_ftp_help(void);
void server_connect(int port, char *path, server_t *serv);
void user_command(server_t *serv, int socket, char *user);
void password_command(server_t *serv, int socket, char *password);
void quit_command(server_t *serv, int socket, int index);
void interpret_client(server_t *serv, int socket);
void command_handling1(server_t *serv, int socket, int index);
void command_handling2(server_t *serv, int socket, char **cmd, int index);
void help_command(server_t *serv, int socket);
void password_command_check(server_t *serv, int socket, char *password);
void noop_command(server_t *serv, int socket);
void command_handling3(server_t *serv, int socket, char **cmd, int index);
void initialisation_client_data(server_t *serv, char *path);
int config_server_socket(int port);
void pwd_command(server_t *serv, int socket, char **cmd);
void cwd_command(server_t *serv, int socket, char **cmd);
void command_handling4(server_t *serv, int socket, char **cmd, int index);
void cwd_command_extended(server_t *serv, int socket, char *path);
void list_command(server_t *serv, int socket, char **cmd);
void list_files(server_t *serv, int socket, char *path);
void handle_connection(int s, server_t *serv);
void retr_command(server_t *serv, int socket, char **cmd);
void command_handling5(server_t *serv, int socket, char **cmd, int index);
void dele_command(server_t *serv, int socket, char **cmd);
void command_handling6(server_t *serv, int index, char **cmd, int socket);
void cdup_command(server_t *serv, int socket, char **cmd);
int check_port_and_path(int port, char *path);
bool all_spaces(char *str);
void process_directory_entries(DIR *dir, server_t *serv, int socket);
int handle_help(void);
int handle_server_start(char **av, struct server *serv);
int handle_invalid_args(char **av);
void change_directory(server_t *serv, int socket, char *new_path);
void send_file(server_t *serv, int socket, char *filename);

#endif
