
#define TableSize 10000

/* Defining data structures */

typedef struct Animal {
	int animalID;
	char name[20];
	char species[20];
	int age;
	struct Animal* next; //Chaining in the linked list
}Animal;

typedef struct Enclosure {
	int enclosureID;
	char enclosureName[20];
	Animal* animals; // the Linked list of all the animals within the enclosure
	struct Enclosure* next; //Chaining for the hash table
}Enclosure;

typedef struct HashTable {
	Enclosure* table[TableSize];
} HashTable;

/* Mapping an enclosureID to a hash table index*/
extern int hashFunction(int enclosureID);

void insertEnclosure(HashTable* zoo, int enclosureID, char* name);
void insertAnimal(HashTable* zoo, int enclosureID, int animalID, char* name, char* species, int age);
void printAnimalsInEnclosure(HashTable* zoo, int enclosureID);
void printAllEnclosures(HashTable* zoo);