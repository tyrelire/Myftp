/*
** EPITECH PROJECT, 2024
** commands.c
** File description:
** commmands
*/
#include "../include/server.h"
#include "../include/my.h"

void retr_command(server_t *serv, int socket, char **cmd)
{
    char *msg1 = "501 Syntax error in parameters or arguments.\n";
    char *msg3 = "530 Error: Not logged in.\n";

    if (serv->password[socket] == NULL) {
        write(socket, msg3, my_strlen(msg3));
    } else {
        if (cmd[1] == NULL) {
            write(socket, msg1, strlen(msg1));
            return;
        }
        send_file(serv, socket, cmd[1]);
    }
}
