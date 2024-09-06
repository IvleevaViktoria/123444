#include <stdio.h>
struct Client {
    int client_id;
    const char *name;
    const char *city;
    int rating;
    int manager_id;
};

int mainn() {
    Client cl = {1, "Vasya", "Moskva", 1, 3};
    printf("id=%d, name=%s, city=%s, rating=%d, manager_id=%d\n", cl.client_id, cl.name, cl.city, cl.rating, cl.manager_id);
    
    return 0;
}