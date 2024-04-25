/*
** EPITECH PROJECT, 2024
** commands2.c
** File description:
** commmands2
*/
#include "../include/server.h"
#include "../include/my.h"

void my_ftp_help(void)
{
    char *msg1 = "USAGE: ./myftp port path\n";
    char *msg2 = "      port  is the port number on which";
    char *msg3 = "the server socket listens\n";
    char *msg4 = "      path  is the path to the home";
    char *msg5 = "directory for the Anonymous user\n";

    write(1, msg1, my_strlen(msg1));
    write(1, msg2, my_strlen(msg2));
    write(1, msg3, my_strlen(msg3));
    write(1, msg4, my_strlen(msg4));
    write(1, msg5, my_strlen(msg5));
}

void handle_anonymous_user(server_t *serv, int socket, char *user)
{
    char *msg = "331 User name okay, need password.\n";

    if (serv->user[socket] != NULL) {
        free(serv->user[socket]);
    }
    serv->user[socket] = strdup(user);
    write(socket, msg, strlen(msg));
}

void user_command(server_t *serv, int socket, char *user)
{
    char *msg1 = "331 Error: invalid user.\n";
    char *msg2 = "530 Error: waiting login.\n";

    if (user != NULL) {
        if (strcmp(user, "Anonymous") == 0) {
            handle_anonymous_user(serv, socket, user);
        } else {
            write(socket, msg1, strlen(msg1));
        }
    } else {
        write(socket, msg2, strlen(msg2));
    }
}

void password_command(server_t *serv, int socket, char *password)
{
    char *msg1 = "530 Error: need login.\n";
    char *msg2 = "230 User logged in, proceed.\n";

    if (serv->user[socket] == NULL) {
        write(socket, msg1, my_strlen(msg1));
        return;
    }
    if (strcmp(serv->user[socket], "Anonymous") == 0) {
        if (serv->password[socket] != NULL) {
            free(serv->password[socket]);
        }
        serv->password[socket] = strdup("");
        write(socket, msg2, my_strlen(msg2));
    } else {
        password_command_check(serv, socket, password);
    }
}

void quit_command(server_t *serv, int socket, int index)
{
    char *msg1 = "221 Logged out.\n";
    char *msg2 = "221 Service closing control connection.\n";

    if (serv->password[socket] != NULL && serv->user[socket] != NULL) {
        write(socket, msg1, my_strlen(msg1));
    } else {
        write(socket, msg2, my_strlen(msg2));
    }
    FD_CLR(socket, &serv->reads);
    close(serv->cl_s[index]);
    serv->cl_s[index] = 0;
    serv->user[index] = NULL;
    serv->password[index] = NULL;
}
