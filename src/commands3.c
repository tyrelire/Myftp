/*
** EPITECH PROJECT, 2024
** commands3.c
** File description:
** commmands3
*/
#include "../include/server.h"
#include "../include/my.h"

void password_command_check(server_t *serv, int socket, char *password)
{
    char *msg3 = "230 User logged in, proceed.\n";
    char *msg4 = "530 Error: waiting password.\n";

    if (password != NULL) {
        if (serv->password[socket] != NULL) {
            free(serv->password[socket]);
        }
        serv->password[socket] = strdup(password);
        write(socket, msg3, my_strlen(msg3));
    } else {
        write(socket, msg4, my_strlen(msg4));
        return;
    }
}

void noop_command(server_t *serv, int socket)
{
    char *msg1 = "200 Command okay\n";
    char *msg2 = "530 Error: Not logged in.\n";

    if (serv->password[socket] == NULL) {
        write(socket, msg2, my_strlen(msg2));
    } else {
        write(socket, msg1, my_strlen(msg1));
    }
}

void pwd_command(server_t *serv, int socket, char **cmd)
{
    char *msg1 = "257 \"%s\" is the current directory.\n";
    char *msg2 = "530 Error: Not logged in.\n";
    char response[2048];

    (void)cmd;
    if (serv->password[socket] == NULL) {
        write(socket, msg2, strlen(msg2));
    } else {
        snprintf(response, sizeof(response), msg1, serv->cwd[socket]);
        write(socket, response, strlen(response));
    }
}

void cwd_command(server_t *serv, int socket, char **cmd)
{
    char *msg1 = "530 Error: Not logged in.\n";
    char *msg2 = "550 Error: no path.\n";

    if (serv->password[socket] != NULL) {
        if (cmd[1] == NULL) {
            write(socket, msg2, strlen(msg2));
        } else {
            cwd_command_extended(serv, socket, cmd[1]);
        }
    } else {
        write(socket, msg1, strlen(msg1));
    }
}

bool all_spaces(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            return false;
        }
    }
    return true;
}
