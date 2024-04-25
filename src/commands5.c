/*
** EPITECH PROJECT, 2024
** commands5.c
** File description:
** commmands5
*/
#include "../include/server.h"
#include "../include/my.h"

void command_handling6(server_t *serv, int index, char **cmd, int socket)
{
    char *msg = "500 Unknown command.\n";

    (void)index;
    if (strcmp(cmd[0], "CDUP") == 0) {
        cdup_command(serv, socket, cmd);
    } else {
        write(socket, msg, my_strlen(msg));
    }
}

void delete_file(server_t *serv, int socket, char *filename)
{
    char *msg2 = "250 Requested file action okay, completed.\n";
    char *msg3 = "550 Requested action not taken. File unavailable.\n";
    char file_path[1024];

    snprintf(file_path, sizeof(file_path), "%s/%s", serv->path, filename);
    if (remove(file_path) == 0) {
        write(socket, msg2, strlen(msg2));
    } else {
        write(socket, msg3, strlen(msg3));
    }
}

void dele_command(server_t *serv, int socket, char **cmd)
{
    char *msg1 = "501 Syntax error in parameters or arguments.\n";
    char *msg4 = "530 Error: Not logged in.\n";

    if (serv->password[socket] == NULL) {
        write(socket, msg4, my_strlen(msg4));
    } else {
        if (cmd[1] == NULL) {
            write(socket, msg1, strlen(msg1));
            return;
        }
        delete_file(serv, socket, cmd[1]);
    }
}

void cdup_command(server_t *serv, int socket, char **cmd)
{
    char *msg3 = "530 Error: Not logged in.\n";
    char new_path[1024];

    (void)cmd;
    if (serv->password[socket] == NULL) {
        write(socket, msg3, strlen(msg3));
    } else {
        snprintf(new_path, sizeof(new_path), "%s/..", serv->cwd[socket]);
        change_directory(serv, socket, new_path);
    }
}

int check_port_and_path(int port, char *path)
{
    if (port <= 0 || port > 65535) {
        printf("Error: Invalid port.\n");
        return 84;
    }
    if (access(path, F_OK) == -1) {
        printf("Error: Invalid path. Path does not exist.\n");
        return 84;
    }
    return 0;
}
