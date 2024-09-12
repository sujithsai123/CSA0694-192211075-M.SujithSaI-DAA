#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

// Structure to represent an item
typedef struct {
    int id;
    float weight;
    float volume;
} Item;

// Structure to represent a container
typedef struct {
    int id;
    float max_weight;
    float max_volume;
    float current_weight;
    float current_volume;
} Container;

// Function to initialize containers
void initializeContainers(Container containers[], int num_containers) {
    for (int i = 0; i < num_containers; i++) {
        containers[i].id = i + 1;
        containers[i].max_weight = 1000.0; // Example: Max weight capacity of each container
        containers[i].max_volume = 10.0;   // Example: Max volume capacity of each container
        containers[i].current_weight = 0.0;
        containers[i].current_volume = 0.0;
    }
}

// Function to read items from input
int readItems(Item items[]) {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        items[i].id = i + 1;
        printf("Enter weight and volume of item %d: ", items[i].id);
        scanf("%f %f", &items[i].weight, &items[i].volume);
    }

    return num_items;
}

// Function to find the first-fit container for an item
int findFirstFitContainer(Container containers[], int num_containers, Item item) {
    for (int i = 0; i < num_containers; i++) {
        if (containers[i].current_weight + item.weight <= containers[i].max_weight &&
            containers[i].current_volume + item.volume <= containers[i].max_volume) {
            return i;
        }
    }
    return -1; // No suitable container found
}

// Function to perform container loading using a greedy heuristic
void loadContainers(Item items[], int num_items, Container containers[], int num_containers) {
    for (int i = 0; i < num_items; i++) {
        int container_index = findFirstFitContainer(containers, num_containers, items[i]);
        if (container_index != -1) {
            containers[container_index].current_weight += items[i].weight;
            containers[container_index].current_volume += items[i].volume;
            printf("Item %d (weight=%.2f, volume=%.2f) packed into Container %d\n",
                   items[i].id, items[i].weight, items[i].volume, containers[container_index].id);
        } else {
            printf("Item %d (weight=%.2f, volume=%.2f) could not be packed into any container\n",
                   items[i].id, items[i].weight, items[i].volume);
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    Container containers[MAX_CONTAINERS];

    int num_items = readItems(items);
    int num_containers = 5; // Example: Number of containers available

    initializeContainers(containers, num_containers);
    loadContainers(items, num_items, containers, num_containers);

    return 0;
}
