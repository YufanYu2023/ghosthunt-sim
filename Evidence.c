#include "defs.h"

/*Function: initEvidence()
  Purpose:  initEvidence
       in:  EvidenceType *p_evidenceType, unsigned int seed
*/
void initEvidence(EvidenceType *p_evidenceType, unsigned int seed){

    int random = rand() % (3 - 0) + 0;

    //randomly generate evidenceType
    switch (random)
    {
      case 0://EMF
          p_evidenceType->evidenceClassType = 0;
          p_evidenceType->value = randFloat(0,5);
          if((4.70 < p_evidenceType->value) && (p_evidenceType->value < 5))
          {  p_evidenceType->isGhostly = 1; }
          else
          { p_evidenceType->isGhostly = 0;}
       break;
      case 1://TEMPERATURE
          p_evidenceType->evidenceClassType = 1;
          p_evidenceType->value = randFloat(-10,27);
          if((-10 < p_evidenceType->value) && (p_evidenceType->value < 1))
          {  p_evidenceType->isGhostly = 1; }
          else
          { p_evidenceType->isGhostly = 0;}
        break;
      case 2://FINGERPRINTS
          p_evidenceType->evidenceClassType = 2;
          if(0.5 < randFloat(0,1))
          {
             p_evidenceType->isGhostly = 1;
             p_evidenceType->value = 1;
           }
          else
          {
            p_evidenceType->isGhostly = 0;
            p_evidenceType->value = 0;
          }
        break;
      case 3://SOUND
          p_evidenceType->evidenceClassType = 3;
          p_evidenceType->value = randFloat(40,75);
          if((65 < p_evidenceType->value) && (p_evidenceType->value < 75))
          { p_evidenceType->isGhostly = 1; }
          else
          { p_evidenceType->isGhostly = 0;}
        break;
    }
}

/*Function: printEvidence()
  Purpose:  print single Evidence
       in:  pointer to an evidence
*/
void printEvidence(EvidenceType *p_evidenceType){

  switch (p_evidenceType->evidenceClassType)
  {
      case 0:
          printf("evidence type %s, ", "EMF");
       break;
      case 1:
          printf("evidence type %s, ", "TEMPERATURE");
        break;
      case 2:
          printf("evidence type %s, ", "FINGERPRINTS");
        break;
      case 3:
          printf("evidence type %s, ", "SOUND");
        break;
  }

    printf("value %f", p_evidenceType->value);

    if(p_evidenceType->isGhostly == 1){
      printf(" [ghostly]");
    }

    printf("\n");
}

/*Function: initEvidenceList()
  Purpose:  init EvidenceList
       in:  EvidenceList pointer
*/
void initEvidenceList(EvidenceListType *p_evidenceList){
    p_evidenceList->p_headNode = NULL;
}

/*Function: appendEvidence()
  Purpose:  append evidence to the EvidenceList
       in:  EvidenceListType* p_evidenveList, EvidenceType* p_evidence
*/
void appendEvidence(EvidenceListType* p_evidenveList, EvidenceType* p_evidence){

    EvidenceNodeType* p_newNode;
    p_newNode = malloc(sizeof(EvidenceNodeType));
    p_newNode->p_data = p_evidence;
    p_newNode->p_nextNode = NULL;

    if(p_evidenveList->p_headNode == NULL){
        p_evidenveList->p_headNode = p_newNode;
    }else{

        EvidenceNodeType* p_current;
        p_current = p_evidenveList->p_headNode;
        while(p_current->p_nextNode != NULL){
            p_current = p_current->p_nextNode;
        }

        p_current->p_nextNode = p_newNode;
    }
}

/*Function: deleteEvidence()
  Purpose:  delete evidence form the EvidenceList
       in:  EvidenceListType* p_evidenveList, EvidenceType* p_evidence
*/
void deleteEvidence(EvidenceListType* p_evidenveList, EvidenceType* p_evidenceToDelete)
{
    if(p_evidenveList->p_headNode->p_data == p_evidenceToDelete)
    {
        if(p_evidenveList->p_headNode->p_nextNode != NULL)
        {
          p_evidenveList->p_headNode = p_evidenveList->p_headNode->p_nextNode;
        }
        else
        {
          p_evidenveList->p_headNode = NULL;
        }

        //EvidenceNodeType* p_temp = p_evidenveList->p_headNode;
        //p_evidenveList->p_headNode = p_newNode;
        //free(p_temp);
    }
    else
    {
      EvidenceNodeType* p_previousNode = p_evidenveList->p_headNode;
      EvidenceNodeType* p_currentNode = p_evidenveList->p_headNode->p_nextNode;

      while(p_currentNode != NULL)
      {
          if(p_currentNode->p_data == p_evidenceToDelete)
          {
              if(p_currentNode->p_nextNode != NULL)
              {
                p_previousNode->p_nextNode = p_currentNode->p_nextNode;
              }
              else
              {
                  p_previousNode->p_nextNode = NULL;
              }
          }

          p_currentNode = p_currentNode->p_nextNode;
      }
  }
}

/*Function: printEvidenceList()
  Purpose:  print out the EvidenceList
       in:  EvidenceListType* p_evidenceList
*/
void printEvidenceList(EvidenceListType* p_evidenceList){

    if(p_evidenceList->p_headNode == NULL){
        printf("no evidence in the collection\n");
    }else{

        EvidenceNodeType* p_current;
        p_current = p_evidenceList->p_headNode;

        while (p_current->p_nextNode != NULL)
        {
            printEvidence(p_current->p_data);
            p_current = p_current->p_nextNode;
        }

        printEvidence(p_current->p_data);

    }
}
