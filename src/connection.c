/*
** EPITECH PROJECT, 2024
** connection.c
** File description:
** connection
*/
#include "../include/server.h"
#include "../include/my.h"

void interpret_client(server_t *s, int cl_i)
{
    int vr;

    vr = read(s->cl_s[cl_i], s->cl_b[cl_i], sizeof(s->cl_b[cl_i]) - 1);
    if (vr == 0) {
        quit_command(s, s->cl_s[cl_i], cl_i);
    } else if (vr > 0) {
        s->cl_b[cl_i][vr] = '\0';
        printf("Client %d said: %s", s->cl_s[cl_i], s->cl_b[cl_i]);
        command_handling1(s, cl_i, s->cl_s[cl_i]);
    } else {
        perror("Error in read");
    }
}

void add_new_client_to_server(server_t *serv, int ns)
{
    int i;

    for (i = 0; i < serv->max_client; i++) {
        if (serv->cl_s[i] == 0) {
            serv->cl_s[i] = ns;
            write(ns, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));
            break;
        }
    }
}

void accept_new_connection(int s, server_t *serv, struct sockaddr_in *a,
    socklen_t *al)
{
    int ns;
    int i;

    ns = accept(s, (struct sockaddr *)a, al);
    if (ns < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    FD_SET(ns, &serv->reads);
    if (ns > serv->max_sd) {
        serv->max_sd = ns;
    }
    for (i = 0; i < serv->max_client; i++) {
        if (serv->cl_s[i] == 0) {
            serv->cl_s[i] = ns;
            write(ns, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));
            break;
        }
    }
}

void check_existing_connections(server_t *serv)
{
    int i;
    int sd;

    for (i = 0; i < serv->max_client; i++) {
        sd = serv->cl_s[i];
        if (sd > 0 && FD_ISSET(sd, &serv->tmp_reads)) {
            interpret_client(serv, i);
        }
    }
}

void handle_connection(int s, server_t *serv)
{
    struct sockaddr_in a;
    socklen_t al = sizeof(a);
    int acty;

    serv->max_sd = s;
    FD_ZERO(&serv->reads);
    FD_SET(s, &serv->reads);
    while (1) {
        serv->tmp_reads = serv->reads;
        acty = select(serv->max_sd + 1, &serv->tmp_reads, NULL, NULL, NULL);
        if ((acty < 0) && (errno != EINTR)) {
            perror("select error");
            break;
        }
        if (FD_ISSET(s, &serv->tmp_reads)) {
            accept_new_connection(s, serv, &a, &al);
        }
        check_existing_connections(serv);
    }
}
