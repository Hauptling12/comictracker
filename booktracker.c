#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

int main(int argc, char **argv)
{
    int c;
    char *user = getenv("USER");
    char filename[100] = "/home/";
    char extq[100] = "/.local/share/comictracker/book.json";
    strncat(filename, user, 100);
    strncat(filename, extq, 100);
    char pub[100];
    char name[100];
    char date[100];
    char wat[100];
    while ((c = getopt(argc, argv, "halv")) != -1) {
        switch (c) {
        case 'v':
            printf("0.0.3");
            break;
        case 'h':
            printf("-a      add books\n"
                   "-l      list books\n"
                   "-h      display this help\n"
                   "-v      Show version information");
            break;
        case 'l':
            system("cat ~/.local/share/comictracker/book.json | jtbl");
            break;
        case 'a':
            printf("title: ");
            scanf("%[^\n]%*c",name);
            printf("publisher: ");
            scanf("%[^\n]%*c",pub);
            printf("date published: ");
            scanf("%s",date);
            printf("read y/n: ");
            scanf("%s",wat);
            json_object *root = json_object_from_file(filename);
            if (!root)
                return 1;
            json_object *paige = json_object_new_object();
            json_object_object_add(paige, "title", json_object_new_string(name));
            json_object_object_add(paige, "publisher", json_object_new_string(pub));
            json_object_object_add(paige, "date", json_object_new_string(date));
            json_object_object_add(paige, "read",json_object_new_string(wat));
            json_object_array_add(root,paige);
            if (json_object_to_file(filename, root))
                printf("Error: failed to save %s!!\n", filename);
            else
                printf("%s saved.\n", filename);

            json_object_put(root);

        }
    }
    return 0;
}

