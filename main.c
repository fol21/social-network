#include<helpers.h>
#include<graph.h>
#include<stdio.h>
#define MAXIDSIZE 100

void opt_adicionar_aresta(Graph* graph)
{
    int scan;
    int src;
    int dest;
    do
	{
		printf("Escolha Vértice de origem :\n");
		scan = scanf("%d",&src);
		while ((getchar()) != '\n');
    } while (scan !=1);
    do
	{
		printf("Escolha Vértice para ligar :\n");
		scan = scanf("%d",&dest);
		while ((getchar()) != '\n');
    } while (scan !=1);
    
    add_Edge(graph, src, dest);
    print_Graph(graph);
}

void opt_remover_aresta(){}

void opt_pessoas_maior_idade(Graph* graph)
{
    int v;
    int n = 1;
    Person* persons = NULL;

    int scan;
    int age;
    do
	{
		printf("Escolha idade: \n");
		scan = scanf("%d",&age);
		while ((getchar()) != '\n');
    } while (scan !=1);


    printf("Pessoas maiores que %d anos: \n",age);
    for (v = 0; v < graph->V; ++v)
    {
        if(graph->array[v].person.age > age)
        {
            persons = (Person*)realloc(persons, n*sizeof(Person));
            persons[n-1] = graph->array[v].person;
            printf("%s, %d anos \n", graph->array[v].person.name, graph->array[v].person.age);
        }
    }
}

void opt_calcula_media_arestas(Graph* graph)
{
    printf("Número médio de arestas -> %lf arestas \n", average_edges(graph));
}

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
    //print_Graph(graph);

    fclose(fp);

    int selection = -1;
    int scan;
    
    // Menu bar
    do
    {
        // MENU para escolhar opção por número
        printf("\n");
        printf("--------- [REDE SOCIAL] ---------\n\n");
        printf("Escreva o número da ação desejada:\n");
        printf("1. Adicionar Aresta \n");
        printf("2. Remover Aresta \n");
        printf("3. Buscar pessoas mais velhas que certa idade \n");
        printf("4. Calcular número médio de relações de amizade \n");
        printf("5. Escrever arquivo do grafo \n");
        printf("6. Sair \n");
        printf(">> ");

        scan = scanf("%d",&selection);
        printf("\n");
        while ((getchar()) != '\n');

        // Lógica de decição baseado na seleção
        switch (selection)
        {
            case 1:
                printf("1. Adicionar Aresta \n");
                opt_adicionar_aresta(graph);
                break;
            case 2:
                printf("1. Adicionar Aresta \n");
                opt_remover_aresta();
                break;
            case 3:
                printf("1. Adicionar Aresta \n");
                opt_pessoas_maior_idade(graph);
                break;
            case 4:
                printf("1. Adicionar Aresta \n");
                opt_calcula_media_arestas(graph);
                break;
            case 5:
                printf("1. Adicionar Aresta \n");
                opt_adicionar_aresta(graph);
                break;
            case 6:
                break;

        default:
            printf("Selecione um número entre 1 e 6 !");
            break;
        }

    }while(selection != 6);



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