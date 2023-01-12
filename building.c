
#include "defs.h"


void initBuilding(BuildingType * p_buildingType)
{
  //initRoomList(&)


  //initGhostList(&p_buildingType->ghosts);
  //initRoomArray(&p_buildingType->rooms);
}

void cleanupBuilding(BuildingType * p_buildingType)
{
  //nothing 256 bytes in 6 blocks

  //cleanupGhostData(&p_buildingType->ghosts);
  //cleanupGhostList(&p_buildingType->ghosts);
  //cleanupRoomArray(&p_buildingType->rooms);
}



void printBuilding(BuildingType *p_buildingType){

    if(p_buildingType->rooms.p_headNode == NULL && p_buildingType->rooms.p_tailNode == NULL){

      printf("building is null\n");

    }else{

      RoomNodeType *p_current;
      p_current = p_buildingType->rooms.p_headNode;

      while (p_current->p_nextNode != NULL) {

        printRoom(p_current->room);
        p_current = p_current->p_nextNode;

      }

      printRoom(p_current->room);
    }

}

void fancyPrintBuilding(BuildingType *p_buildingType){

  printf("xxxxxxxxxxx\nx         x\nxxxxxxxxxxx");

  printf("xxxxxxxxxxx\nx         x\nxxxxxxxxxxx");

}


/*
    map:
    https://steamcommunity.com/sharedfiles/filedetails/?id=2251267947

*/
void populateRooms(BuildingType* building) {
    // First, create each room. Perhaps you want to include more data
    // in the init parameters?
    building->p_ghost = NULL;
    RoomType* van = calloc(1, sizeof(RoomType));
    initRoom(van, "Van");
    RoomType* hallway = calloc(1, sizeof(RoomType));
    initRoom(hallway, "Hallway");
    RoomType* master_bedroom = calloc(1, sizeof(RoomType));
    initRoom(master_bedroom, "Master Bedroom");
    RoomType* boys_bedroom = calloc(1, sizeof(RoomType));
    initRoom(boys_bedroom, "Boy's Bedroom");
    RoomType* bathroom = calloc(1, sizeof(RoomType));
    initRoom(bathroom, "Bathroom");
    RoomType* basement = calloc(1, sizeof(RoomType));
    initRoom(basement, "Basement");
    RoomType* basement_hallway = calloc(1, sizeof(RoomType));
    initRoom(basement_hallway, "Basement Hallway");
    RoomType* right_storage_room = calloc(1, sizeof(RoomType));
    initRoom(right_storage_room, "Right Storage Room");
    RoomType* left_storage_room = calloc(1, sizeof(RoomType));
    initRoom(left_storage_room, "Left Storage Room");
    RoomType* kitchen = calloc(1, sizeof(RoomType));
    initRoom(kitchen, "Kitchen");
    RoomType* living_room = calloc(1, sizeof(RoomType));
    initRoom(living_room, "Living Room");
    RoomType* garage = calloc(1, sizeof(RoomType));
    initRoom(garage, "Garage");
    RoomType* utility_room = calloc(1, sizeof(RoomType));
    initRoom(utility_room, "Utility Room");

    /////////////////////////////////////////////////////////////////

    // Now create a linked list of rooms using RoomNodeType in the Building
    RoomNodeType* van_node = calloc(1, sizeof(RoomNodeType));
    van_node->room = van;
    van_node->p_nextNode = NULL;//;(

    RoomNodeType* hallway_node = calloc(1, sizeof(RoomNodeType));
    hallway_node->room = hallway;
    hallway_node->p_nextNode = NULL;//;(

    RoomNodeType* master_bedroom_node = calloc(1, sizeof(RoomNodeType));
    master_bedroom_node->room = master_bedroom;
    master_bedroom_node->p_nextNode = NULL;//;(

    RoomNodeType* boys_bedroom_node = calloc(1, sizeof(RoomNodeType));
    boys_bedroom_node->room = boys_bedroom;
    boys_bedroom_node->p_nextNode = NULL;//;(

    RoomNodeType* bathroom_node = calloc(1, sizeof(RoomNodeType));
    bathroom_node->room = bathroom;
    bathroom_node->p_nextNode = NULL;//;(

    RoomNodeType* basement_node = calloc(1, sizeof(RoomNodeType));
    basement_node->room = basement;
    basement_node->p_nextNode = NULL;//;(

    RoomNodeType* basement_hallway_node = calloc(1, sizeof(RoomNodeType));
    basement_hallway_node->room = basement_hallway;
    basement_hallway_node->p_nextNode = NULL;//;(

    RoomNodeType* right_storage_room_node = calloc(1, sizeof(RoomNodeType));
    right_storage_room_node->room = right_storage_room;
    right_storage_room_node->p_nextNode = NULL;//;(

    RoomNodeType* left_storage_room_node = calloc(1, sizeof(RoomNodeType));
    left_storage_room_node->room = left_storage_room;
    left_storage_room_node->p_nextNode = NULL;//;(

    RoomNodeType* kitchen_node = calloc(1, sizeof(RoomNodeType));
    kitchen_node->room = kitchen;
    kitchen_node->p_nextNode = NULL;//;(

    RoomNodeType* living_room_node = calloc(1, sizeof(RoomNodeType));
    living_room_node->room = living_room;
    living_room_node->p_nextNode = NULL;//;(

    RoomNodeType* garage_node = calloc(1, sizeof(RoomNodeType));
    garage_node->room = garage;
    garage_node->p_nextNode = NULL;//;(

    RoomNodeType* utility_room_node = calloc(1, sizeof(RoomNodeType));
    utility_room_node->room = utility_room;
    utility_room_node->p_nextNode = NULL;//;(

    /////////////////////////////////////////////////////////////////

    // Building->rooms might be a linked list structre, or maybe just a node.
    initRoomList(&building->rooms);
    //printBuilding(building);

    appendRoom(&building->rooms, van_node);
    appendRoom(&building->rooms, hallway_node);
    appendRoom(&building->rooms, master_bedroom_node);
    appendRoom(&building->rooms, boys_bedroom_node);
    appendRoom(&building->rooms, bathroom_node);
    appendRoom(&building->rooms, basement_node);
    appendRoom(&building->rooms, basement_hallway_node);
    appendRoom(&building->rooms, right_storage_room_node);
    appendRoom(&building->rooms, left_storage_room_node);
    appendRoom(&building->rooms, kitchen_node);
    appendRoom(&building->rooms, living_room_node);
    appendRoom(&building->rooms, garage_node);
    appendRoom(&building->rooms, utility_room_node);

    //printRoom(building->rooms.p_headNode->room);
    //printBuilding(building);



    // Now connect the rooms. It is possible you do not need a separate
    // function for this, but it is provided to give you a starting point.
    connectRooms(van, hallway);

    connectRooms(hallway, master_bedroom);
    connectRooms(hallway, boys_bedroom);
    connectRooms(hallway, bathroom);
    connectRooms(hallway, kitchen);
    connectRooms(hallway, basement);
    connectRooms(basement, basement_hallway);
    connectRooms(basement_hallway, right_storage_room);
    connectRooms(basement_hallway, left_storage_room);
    connectRooms(kitchen, living_room);
    connectRooms(kitchen, garage);
    connectRooms(garage, utility_room);


    //printBuilding(building);
}
