#include<helpers.h>
#include<graph.h>
#include<stdio.h>
#define MAXIDSIZE 100


int main(){
    FILE *fp;
    char c;
    int i= 0;
    char* line = NULL;
    int len = 0;
    int read;
    char* filename = "graph.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    //Read Number of vertices
    read = getline(&line, &len, fp);
    int n_vertices = atoi(line);
    Person* persons = create_person_array(n_vertices);

    //Populate persons structures and AdjList array
    char** name_age_pair;
    for (int i = 0; i < n_vertices ; i++)
    {
        read = getline(&line, &len, fp);
        name_age_pair = str_split(line,' ');
        persons[i].name = name_age_pair[0];
        persons[i].age = atoi(name_age_pair[1]);
    }
    
    Graph* graph = create_Graph(n_vertices,persons);

    // Edges connection logic
     for (int i = 0; i < n_vertices ; i++)
    {
        read = getline(&line, &len, fp);
        name_age_pair = str_split(line,' ');
        for (int j = 0; j < n_vertices; j++)
        {
            if(atoi(name_age_pair[j]))
            {
                add_Edge(graph,i,j);
            }
        }
    }
    print_Graph(graph);

    fclose(fp);

    // while ((read = getline(&line, &len, fp)) != -1) {
    //     printf("Retrieved line of length %zu :\n", read);
    //     printf("%s", line);
    // }
    // const char* names[] = {"Maria","Bob","Ana"}; 
    // Graph* graph = create_Graph(3, names);
    // add_Edge(graph, 0,1);
    // add_Edge(graph, 0,2);
    // add_Edge(graph, 1,2);
    // print_Graph(graph);
    return 0;
}