/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../include/server.h"
#include "../include/my.h"

void server_connect(int port, char *path, server_t *serv)
{
    int server_fd = config_server_socket(port);

    serv->port = port;
    serv->path = path;
    handle_connection(server_fd, serv);
    close(server_fd);
}

int config_server_socket(int port)
{
    struct sockaddr_in address;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    return server_fd;
}

void initialisation_client_data(server_t *serv, char *path)
{
    char *real_path = realpath(path, NULL);

    serv->max_client = MAX_CLIENTS;
    for (int i = 0; i < serv->max_client; i++) {
        serv->cl_s[i] = 0;
        serv->user[i] = NULL;
        serv->password[i] = NULL;
        if (real_path) {
            serv->cwd[i] = strdup(real_path);
        } else {
            serv->cwd[i] = strdup("");
        }
    }
    free(real_path);
}

void help_command(server_t *serv, int socket)
{
    char *msg1 = "530 Error: Not logged in.\n";
    char *msg2 = "214 Help message.\n";

    if (serv->password[socket] == NULL) {
        write(socket, msg1, my_strlen(msg1));
    } else {
        write(socket, msg2, my_strlen(msg2));
    }
}

int main(int ac, char **av)
{
    struct server serv;
    int result;

    if (ac != 3) {
        return handle_invalid_args(av);
    }
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        return handle_help();
    }
    if (ac == 3) {
        result = handle_server_start(av, &serv);
        return result;
    }
    return 0;
}
