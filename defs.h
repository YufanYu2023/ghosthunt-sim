#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_STR            64
#define FEAR_RATE           1
#define MAX_FEAR          100
#define MAX_HUNTERS         4
#define USLEEP_TIME     50000
#define BOREDOM_MAX        99
#define MAX_ARR            16


typedef enum { EMF, TEMPERATURE, FINGERPRINTS, SOUND } EvidenceClassType;
typedef enum { POLTERGEIST, BANSHEE, BULLIES, PHANTOM } GhostClassType;


typedef struct EvidenceType{
  EvidenceClassType evidenceClassType;
  float value;
  int isGhostly;
}EvidenceType;

typedef struct EvidenceNodeType{
  EvidenceType* p_data;
  struct EvidenceNodeType *p_nextNode;
}EvidenceNodeType;

typedef struct EdgeListType {
  struct RoomNodeType * p_headNode;
  int size;
} EdgeListType;

typedef struct EvidenceListType{
  EvidenceNodeType *p_headNode;
}EvidenceListType;

typedef struct HunterType{
  char name[MAX_STR];
  char nickName[MAX_STR];
  struct RoomType * p_currentRoom;
  EvidenceClassType evidenceClassType;
  EvidenceListType evidenceList;
  int fear;
  int boredom;
  int arrayIndex;
  int ghostlyEvidenceCount;
  unsigned int seed;
  struct GhostType* p_ghost;
} HunterType;

typedef struct RoomType{
  sem_t *mutex;
  char name[MAX_STR];
  //list of evidence
  EvidenceListType evidenceList;
  //list of connected rooms
  EdgeListType adjacentRooms;
  //int size;
  struct GhostType * p_ghost;
  struct HunterType* hunters[4];
} RoomType;


typedef struct GhostType{
  RoomType * p_currentRoom;
  GhostClassType class;
  int boredom;
  int busted;
  unsigned int seed;
}GhostType;

typedef struct RoomNodeType {
  RoomType * room;
  struct RoomNodeType * p_nextNode;
}RoomNodeType;



typedef struct  {
  RoomNodeType *p_headNode;
  RoomNodeType *p_tailNode;
}RoomListType;

typedef struct Building {
  RoomListType rooms;
  GhostType *p_ghost;
} BuildingType;



int randInt(int, int);          // Generates a pseudorandom integer between the parameters
float randFloat(float, float);  // Generates a pseudorandom float between the parameters
void getNames(char*, char*, char*, char*);
void trim(char*);

void initRoomList(RoomListType *);
void appendRoom(RoomListType  *, RoomNodeType *);
void populateRooms(BuildingType*);   // Populates the building with sample data for rooms
void initRoom(RoomType*, char*); //init room info(need add more later)
int doseRoomContainGhost(RoomType*);//returns a 1 or 0 depending if if a ghost is in the given room
void printRoom(RoomType *);
void connectRooms(RoomType *, RoomType *);//connect rooms that are connected
void getNewRoom(RoomType **);
void printRoomOccupants(RoomType *, char[]);
int getNumberOfHuntersInRoom(RoomType *);

void initBuilding(BuildingType*); //initizes the buildingType
void printBuilding(BuildingType*); //print info of the building
void fancyPrintBuilding(BuildingType*);

void initGhost(GhostType *, RoomType *, unsigned int);
RoomType * getRandomStartingRoom(unsigned int, BuildingType *);
void moveGhost(GhostType *);
void printGhost(GhostType *);
void ghostAction(GhostType *, unsigned int);
GhostClassType randomGhost();

void initHunter(HunterType *, char *, char *, RoomType *, EvidenceClassType, int, unsigned int, GhostType*);
void printHunter(HunterType *);
void moveHunter(HunterType *);
void collectEvidence(HunterType *);
void communicateEvidence(HunterType *);
void hunterAction(HunterType *);
void communicate(HunterType *);

void initEvidence(EvidenceType*, unsigned int);
void printEvidence(EvidenceType*);
void initEvidenceList(EvidenceListType *);
void appendEvidence(EvidenceListType*, EvidenceType*);
void deleteEvidence(EvidenceListType*, EvidenceType*);
void printEvidenceList(EvidenceListType*);
