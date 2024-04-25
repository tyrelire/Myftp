/*
** EPITECH PROJECT, 2024
** commands5.c
** File description:
** commmands5
*/
#include "../include/server.h"
#include "../include/my.h"

void list_files(server_t *serv, int socket, char *path)
{
    DIR *dir;
    char *msg_start = "150 Here comes the directory listing.\n";
    char *msg_end_ok = "226 Directory send OK.\n";
    char *msg_end_error = "550 Requested action not taken. File unavailable\n";

    dir = opendir(path);
    if (dir != NULL) {
        write(socket, msg_start, strlen(msg_start));
        process_directory_entries(dir, serv, socket);
        closedir(dir);
        write(socket, msg_end_ok, strlen(msg_end_ok));
    } else {
        write(socket, msg_end_error, strlen(msg_end_error));
    }
}

int handle_help(void)
{
    my_ftp_help();
    return 0;
}

int handle_server_start(char **av, struct server *serv)
{
    int port = atoi(av[1]);
    char *path = av[2];

    if (check_port_and_path(port, path) == 84) {
        return 84;
    }
    initialisation_client_data(serv, path);
    server_connect(port, path, serv);
    return 0;
}

int handle_invalid_args(char **av)
{
    printf("Usage: %s <port> <path>\n", av[0]);
    return 84;
}

void change_directory(server_t *serv, int socket, char *new_path)
{
    char *msg1 = "250 Command okay.\n";
    char *msg2 = "550 Requested action not taken. File unavailable.\n";
    char *new_cwd;

    new_cwd = realpath(new_path, NULL);
    if (new_cwd) {
        free(serv->cwd[socket]);
        serv->cwd[socket] = strdup(new_cwd);
        write(socket, msg1, strlen(msg1));
    } else {
        write(socket, msg2, strlen(msg2));
    }
    free(new_cwd);
}
