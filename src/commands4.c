/*
** EPITECH PROJECT, 2024
** commands4.c
** File description:
** commmands4
*/
#include "../include/server.h"
#include "../include/my.h"

void process_directory_entries(DIR *dir, server_t *serv, int socket)
{
    struct dirent *entry;
    struct stat fil_st;
    char buffer[1024];
    char t_str[14];
    char *permissions;

    (void)serv;
    while (1) {
        entry = readdir(dir);
        if (entry == NULL)
            break;
        stat(entry->d_name, &fil_st);
        strftime(t_str, 14, "%b %d %H:%M",
        localtime(&(fil_st.st_mtime)));
        permissions = (S_ISDIR(fil_st.st_mode)) ? "rwxr-xr-x" : "rw-r--r--";
        snprintf(buffer, sizeof(buffer), "%c%s  1 ftp  ftp  %5lld %s %s\n",
                (S_ISDIR(fil_st.st_mode)) ? 'd' : '-',
                permissions, (long long)fil_st.st_size, t_str, entry->d_name);
        write(socket, buffer, strlen(buffer));
    }
}

void list_command(server_t *serv, int socket, char **cmd)
{
    char *msg2 = "530 Error: Not logged in.\n";
    char *path;

    if (serv->password[socket] == NULL) {
        write(socket, msg2, my_strlen(msg2));
    } else {
        path = (cmd[1] != NULL) ? cmd[1] : serv->path;
        list_files(serv, socket, path);
    }
}

void send_file(server_t *serv, int socket, char *filename)
{
    char buffer[1024];
    int fd;
    ssize_t bytes;
    char *msg1 = "550 Requested action not taken. File unavailable.\n";
    char file_path[1024];

    snprintf(file_path, sizeof(file_path), "%s/%s", serv->path, filename);
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        write(socket, msg1, strlen(msg1));
        return;
    }
    bytes = read(fd, buffer, sizeof(buffer));
    while (bytes > 0) {
        write(socket, buffer, bytes);
        bytes = read(fd, buffer, sizeof(buffer));
    }
    close(fd);
}

char *create_new_path(server_t *serv, int socket, char *path)
{
    char *tmp = malloc(strlen(serv->cwd[socket]) + strlen(path) + 2);
    char *new_cwd;

    if (tmp == NULL) {
        return NULL;
    }
    strcpy(tmp, serv->cwd[socket]);
    strcat(tmp, "/");
    strcat(tmp, path);
    new_cwd = realpath(tmp, NULL);
    free(tmp);
    return new_cwd;
}

void cwd_command_extended(server_t *serv, int socket, char *path)
{
    char *msg1 = "250 Directory successfully changed.\n";
    char *msg2 = "550 Failed to change directory.\n";
    char *new_cwd = create_new_path(serv, socket, path);

    if (new_cwd == NULL || chdir(new_cwd) == -1) {
        write(socket, msg2, strlen(msg2));
    } else {
        free(serv->cwd[socket]);
        serv->cwd[socket] = strdup(new_cwd);
        write(socket, msg1, strlen(msg1));
    }
    free(new_cwd);
}
