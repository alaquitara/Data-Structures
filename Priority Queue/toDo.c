/*
 * CS 261 Assignment 5
 * Name: Alexander Laquitara
 * Date: 5/11/2016
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
    
    Task *newTask, *tempTask;
    int priority= 0;
    char fileName[100];
    char taskName[100];
    FILE* file = NULL;
    
    switch(command)
    {
        case 'l':
                printf("What is the list named?");
                scanf("%s", fileName);
                while(getchar() != '\n');
                file = fopen(fileName,"r");
                if(file ==NULL)
                {
                    printf("File does not exist");
                    break;
                }
            
                listLoad(list, file);
                fclose(file);
                printf("file loaded");
                break;
           
        case 's':
                printf("Enter a name to save");
                scanf("%s", fileName);
                while(getchar() != '\n');
                file = fopen(fileName, "w");
                if(file ==NULL)
                {
                    printf("File does not exist");
                    break;
                }
                listSave(list, file);
                fclose(file);
                printf("File Saved");
                break;
        
        case 'a':
            
                printf("Enter task:");
                fgets(taskName, sizeof(taskName),stdin);
                printf("enter priority:");
                scanf("%d", &priority);
                while(getchar() != '\n');
                newTask = taskNew(priority, taskName);
                dyHeapAdd(list, newTask, taskCompare);
                break;
      
        case 'g':
                if(dySize(list) > 0)
                {
                    tempTask = dyHeapGetMin(list);
                    printf("First Task:  %s\n", tempTask->name);
                }
                else
                {
                    printf("List is empty");
                }
                break;
                
        case 'r':
                if(dySize(list) >0)
                {
                    tempTask = dyHeapGetMin(list);
                    printf("Task %s completed \n", tempTask->name);
                    dyHeapRemoveMin(list, taskCompare);
                }
                else
                {
                    printf("list is empty");
                }
                break;
        
        case 'p':
                if(dySize(list) >0)
                {
                    printf("Printing list...\n");
                    listPrint(list);
                }
                else
                {
                    printf("List is empty");
                }
                break;
        
        case 'e':
                printf("Exiting program \n");
                break;
        
        default:
                printf("Please enter a valid command");
                       
            
    }
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}