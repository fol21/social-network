#include<helpers.h>
#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
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
    add_Edge(graph, dest, src);
    print_Graph(graph);
}

void opt_remover_aresta(Graph* graph)
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
    
    remove_edge(graph, src, dest);
    remove_edge(graph, dest, src);
    print_Graph(graph);
}

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

void opt_write_txt_file(Graph* graph)
{
    FILE* fp;
    char filename[50];

    // Setup da matriz de adjacencias
    int size = 2*graph->V*sizeof(char)+1;
    char** rows = (char**)malloc(graph->V*sizeof(char*));
    for(int i= 0 ; i < graph->V;i++)
    {
        rows[i] = (char*)malloc(size);
        for(int j=0; j < graph->V; j++)
        {
            rows[i][2*j] = '0';
            rows[i][2*j+1] = ' ';
        }
    }


    printf("Escolha nome do arquivo do grafo a ser lido : \n ");
    
    scanf("%s",filename);
    while ((getchar()) != '\n');

    
    fp = fopen(filename,"w");
    if(fp != NULL)
    {
        
        //Numero de vertices
        printf("%d\n",graph->V);
        fprintf(fp,"%d\n",graph->V);
        //Persons
        for(int i= 0 ; i < graph->V;i++)
        {
            printf("%s %d\n", graph->array[i].person.name, graph->array[i].person.age);
            fprintf(fp,"%s %d\n", graph->array[i].person.name, graph->array[i].person.age);
            
        }
        for(int i= 0 ; i < graph->V;i++)
        {
            //Matrix
            AdjacencyListNode* pCrawl = graph->array[i].head;
            while (pCrawl)
            {
                rows[i][2*pCrawl->dest] = '1';
                pCrawl = pCrawl->next;
            }
            rows[i][size-1] = '\0';
            printf("%s\n", rows[i]);
            fprintf(fp,"%s\n", rows[i]);

        }
    
        //Wrapup
        fclose(fp);
        printf("\n Arquivo escrito em %s \n", filename);
    }
    else printf("Arquivo não pode ser criado.");
}

int main(){
    FILE *fp;
    char c;
    int i= 0;
    char* line = NULL;
    int len = 0;
    int read;
    char filename[50];
    
    //Read File
    printf("Escolha nome do arquivo do grafo a ser lido :  ");
    scanf("%s",filename);
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

    // Grafico inicial
    printf("/n ------ Mapeamento Inicial do grafo ------/n");
    print_Graph(graph);

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
                printf("2. Remover Aresta \n");
                opt_remover_aresta(graph);
                break;
            case 3:
                printf("3. Buscar pessoas mais velhas que certa idade \n");
                opt_pessoas_maior_idade(graph);
                break;
            case 4:
                printf("4. Calcular número médio de relações de amizade \n");
                opt_calcula_media_arestas(graph);
                break;
            case 5:
                printf("5. Escrever arquivo do grafo \n");
                opt_write_txt_file(graph);
                break;
            case 6:
                printf("\n Saindo...\n");
                break;

        default:
            printf("Selecione um número entre 1 e 6 !\n");
            break;
        }

    }while(selection != 6);

    return 0;
}