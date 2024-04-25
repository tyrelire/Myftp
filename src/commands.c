/*
** EPITECH PROJECT, 2024
** commands.c
** File description:
** commmands
*/
#include "../include/server.h"
#include "../include/my.h"

void command_handling1(server_t *serv, int index, int socket)
{
    char *str = serv->cl_b[index];
    char **cmd;
    char *msg1 = "500 Syntax error, command unrecognized.\n";

    str[my_strlen(str) - 2] = '\0';
    cmd = my_str_to_word_array_space(str);
    if (cmd[0] == NULL || strlen(cmd[0]) == 0 || all_spaces(cmd[0])) {
        write(socket, msg1, strlen(msg1));
        return;
    }
    if (cmd == NULL || cmd[0] == NULL)
        return;
    if (strcmp(cmd[0], "USER") == 0) {
        user_command(serv, socket, cmd[1]);
    } else if (strcmp(cmd[0], "PASS") == 0) {
        password_command(serv, socket, cmd[1]);
    } else {
        command_handling2(serv, socket, cmd, index);
    }
}

void command_handling2(server_t *serv, int socket, char **cmd, int index)
{
    if (strcmp(cmd[0], "QUIT") == 0) {
        quit_command(serv, socket, index);
    } else if (strcmp(cmd[0], "HELP") == 0) {
        help_command(serv, socket);
    } else {
        command_handling3(serv, socket, cmd, index);
    }
}

void command_handling3(server_t *serv, int socket, char **cmd, int index)
{
    if (strcmp(cmd[0], "NOOP") == 0) {
        noop_command(serv, socket);
    } else if (strcmp(cmd[0], "PWD") == 0) {
        pwd_command(serv, socket, cmd);
    } else {
        command_handling4(serv, socket, cmd, index);
    }
}

void command_handling4(server_t *serv, int socket, char **cmd, int index)
{
    if (strcmp(cmd[0], "CWD") == 0) {
        cwd_command(serv, socket, cmd);
    } else if (strcmp(cmd[0], "LIST") == 0) {
        list_command(serv, socket, cmd);
    } else {
        command_handling5(serv, socket, cmd, index);
    }
}

void command_handling5(server_t *serv, int socket, char **cmd, int index)
{
    if (strcmp(cmd[0], "RETR") == 0) {
        retr_command(serv, socket, cmd);
    } else if (strcmp(cmd[0], "DELE") == 0) {
        dele_command(serv, socket, cmd);
    } else {
        command_handling6(serv, index, cmd, socket);
    }
}
