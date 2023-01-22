/**
                        Playlist Record
                ---------------------------------
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int id;
    char playlist[50], year[20];
    char genre[7];
    char duration[100], song[50], artist[50];

    struct node *next;
    struct node *previous;

} *start = NULL, *end = NULL;
FILE *file;

void login()
{
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";

    printf("  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb       LOGIN       \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");
    printf(" \n\n\t\t                   USERNAME:-");
    scanf("%s", uname);
    printf(" \n\t\t                   PASSWORD:-");
    scanf("%s", pword);

    if (strcmp(uname, "admin") == 0 && strcmp(pword, "groovy") == 0)
    {
        printf("  \n\n\n       WELCOME TO GROOVY - A MUSIC PLAYLIST MANAGER !!!! LOGIN IS SUCCESSFUL");
        //getch();
    }
    else
    {
        printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
        exit(0);
        //getch();
    }
}

void create_playlist_record()
{
    struct node *new_node, *current;
    int i, number_of_song;

    printf("\n\n\n\n\n\n\t\t\tEnter Number of song's for playlist: ");
    scanf("%d", &number_of_song);

    for (i = 1; i <= number_of_song; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));

        if (new_node == NULL)
        {
            printf("\nMemory Does Not Created.\n");
            exit(0);
        }
        else
        {
            file = fopen("Playlist Record.txt", "a+");
            if (file == NULL)
            {
                printf("File does not create.\n");
            }
            else
            {
                printf("\n\n\t\t\tPlaylist Details\n");
                fprintf(file, "\n\n\t\t\tPlaylist Details\n");
                printf("\t\t_________________________________\n");
                fprintf(file, "\t\t_________________________________\n");

                printf("\n\n\tPlaylist Name: ");
                fflush(stdin);
                gets(new_node->playlist);
                fprintf(file, "\n\tPlaylist Name: %s", new_node->playlist);

                printf("\n\tSong ID: ");
                scanf("%d", &new_node->id);
                fprintf(file, "\n\tSong ID: %d", new_node->id);

                printf("\n\tSong Name: ");
                fflush(stdin);
                gets(new_node->song);
                fprintf(file, "\n\tSong Name: %s", new_node->song);

                printf("\n\tArtist: ");
                fflush(stdin);
                gets(new_node->artist);
                fprintf(file, "\n\tArtist: %s", new_node->artist);

                printf("\n\tYear of release: ");
                fflush(stdin);
                gets(new_node->year);
                fprintf(file, "\n\tYear of release: %s", new_node->year);

                printf("\n\tSong Duration: ");
                fflush(stdin);
                gets(new_node->duration);
                fprintf(file, "\n\tSong Duration: %s", new_node->duration);

                printf("\n\tGenre: ");
                fflush(stdin);
                gets(new_node->genre);
                fprintf(file, "\n\tGenre: %s", new_node->genre);

                fclose(file);
                fopen("Playlist Record.txt", "a+");
            }

            new_node->next = NULL;
            new_node->previous = NULL;

            if (start == NULL && end == NULL)
            {
                start = new_node;
                end = new_node;
                current = new_node;
            }
            else
            {
                current->next = new_node;
                new_node->previous = current;
                current = new_node;
                end = new_node;
            }
        }
    }
}

void add_playlist_record_at_first()
{
    struct node *new_node, *current;
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory Is Not Created.\n");
        exit(0);
    }
    else
    {
        file = fopen("Playlist Record.txt", "a+");
        if (file == NULL)
        {
            printf("File is not created.\n");
        }
        else
        {
            printf("\n\n\t\t\tPlaylist Details\n");
            fprintf(file, "\n\n\t\t\tPlaylist Details\n");
            printf("\t\t_________________________________\n");
            fprintf(file, "\t\t_________________________________\n");

            printf("\n\n\tEnter Playlist Name: ");
            fflush(stdin);
            gets(new_node->playlist);
            fprintf(file, "\n\tPlaylist Name: %s", new_node->playlist);

            printf("\n\tSong ID: ");
            scanf("%d", &new_node->id);
            fprintf(file, "\n\tSong ID: %d", new_node->id);

            printf("\n\tSong Name: ");
            fflush(stdin);
            gets(new_node->song);
            fprintf(file, "\n\tSong Name: %s", new_node->song);

            printf("\n\tArtist: ");
            fflush(stdin);
            gets(new_node->artist);
            fprintf(file, "\n\tArtist: %s", new_node->artist);

            printf("\n\tYear of release: ");
            fflush(stdin);
            gets(new_node->year);
            fprintf(file, "\n\tYear of release: %s", new_node->year);

            printf("\n\tSong Duration: ");
            fflush(stdin);
            gets(new_node->duration);
            fprintf(file, "\n\tSong Duration: %s", new_node->duration);

            printf("\n\tGenre: ");
            fflush(stdin);
            gets(new_node->genre);
            fprintf(file, "\n\tGenre: %s", new_node->genre);

            fclose(file);
            fopen("Playlist Record.txt", "a+");
        }
    }

    new_node->next = NULL;
    new_node->previous = NULL;

    current = start;
    new_node->next = current;
    current->previous = new_node;
    start = new_node;
}

void add_playlist_record_at_last()
{
    struct node *new_node, *current;
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory Is Not Created.\n");
        exit(0);
    }
    else
    {
        file = fopen("Playlist Record.txt", "a+");
        if (file == NULL)
        {
            printf("File is not created.\n");
        }
        else
        {
            printf("\n\n\t\t\tPlaylist Details\n");
            fprintf(file, "\n\n\t\t\tPlaylist Details\n");
            printf("\t\t_________________________________\n");
            fprintf(file, "\t\t_________________________________\n");

            printf("\n\n\tEnter Playlist Name: ");
            fflush(stdin);
            gets(new_node->playlist);
            fprintf(file, "\n\tPlaylist Name: %s", new_node->playlist);

            printf("\n\tSong ID: ");
            scanf("%d", &new_node->id);
            fprintf(file, "\n\tSong ID: %d", new_node->id);

            printf("\n\tSong Name: ");
            fflush(stdin);
            gets(new_node->song);
            fprintf(file, "\n\tSong Name: %s", new_node->song);

            printf("\n\tArtist: ");
            fflush(stdin);
            gets(new_node->artist);
            fprintf(file, "\n\tArtist: %s", new_node->artist);

            printf("\n\tYear of release: ");
            fflush(stdin);
            gets(new_node->year);
            fprintf(file, "\n\tYear of release: %s", new_node->year);

            printf("\n\tSong Duration: ");
            fflush(stdin);
            gets(new_node->duration);
            fprintf(file, "\n\tSong Duration: %s", new_node->duration);

            printf("\n\tGenre: ");
            fflush(stdin);
            gets(new_node->genre);
            fprintf(file, "\n\tGenre: %s", new_node->genre);
            fclose(file);
            fopen("Playlist Record.txt", "a+");
        }
    }

    new_node->next = NULL;
    new_node->previous = NULL;

    current = end;
    current->next = new_node;
    new_node->previous = current;
    end = new_node;
}

void display_playlist_record_from_forward()
{
    struct node *current;

    current = start;

    if (current == NULL)
    {
        printf("\n\n\n\n\n\n\n\t\t\tThere Are No Record In The List.\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("\n\t\t\tPlaylist Details\n");
            printf("\t\t_________________________________");

            printf("\n\tPlaylist Name: %s", current->playlist);

            printf("\n\tSong ID: %d", current->id);

            printf("\n\tSong Name: %s", current->song);

            printf("\n\tArtist: %s", current->artist);

            printf("\n\tYear of release: %s", current->year);

            printf("\n\tSong Duration: %s", current->duration);

            printf("\n\tGenre: %s", current->genre);

            current = current->next;
            printf("\n");
        }
    }
}

void display_playlist_record_from_backword()
{
    struct node *current;

    current = end;

    if (current == NULL)
    {
        printf("\n\n\n\n\n\n\n\t\t\tThere Are No Record In The List.\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("\n\t\t\tPlaylist Details\n");
            printf("\t\t_________________________________");

            printf("\n\tPlaylist Name: %s", current->playlist);

            printf("\n\tSong ID: %d", current->id);

            printf("\n\tSong Name: %s", current->song);

            printf("\n\tArtist: %s", current->artist);

            printf("\n\tYear of release: %s", current->year);

            printf("\n\tSong Duration: %s", current->duration);

            printf("\n\tGenre: %s", current->genre);

            current = current->previous;
            printf("\n");
        }
    }
}

int pos(song_id)
{
    int position = 0;
    struct node *current;

    current = start;

    while (current != NULL)
    {
        position++;
        if (song_id == current->id)
        {
            return position;
        }
        current = current->next;
    }
    return -1;
}

int search_playlist_record(song_id)
{
    int position = 0;
    struct node *current;

    current = start;

    while (current != NULL)
    {
        position++;
        if (song_id == current->id)
        {
            printf("\n\t\t\tPlaylist's Details\n");
            printf("\t\t_________________________________");

            printf("\n\tPlaylist Name: %s", current->playlist);

            printf("\n\tSong ID: %d", current->id);

            printf("\n\tSong Name: %s", current->song);

            printf("\n\tArtist: %s", current->artist);

            printf("\n\tYear of release: %s", current->year);

            printf("\n\tSong Duration: %s", current->duration);

            printf("\n\tGenre: %s", current->genre);

            printf("\n\n");

            return position;
        }
        current = current->next;
    }
    return -1;
}

void delete_playlist_record()
{
    struct node *current, *temp1, *temp2;
    int i, delete_id, position;

    printf("\t\t\tEnter ID for delete: ");
    scanf("%d", &delete_id);
    position = pos(delete_id);

    current = start;
    for (i = 1; i <= (position - 1); i++)
    {
        current = current->next;
    }
    if (current == start && current->previous == NULL)
    {
        current = current->next;
        start = current;
        current->previous = NULL;
        printf("\nFirst ID Delete Successfully.\n");
    }
    else if (current->next == NULL && current == end)
    {
        current = current->previous;
        end = current;
        current->next = NULL;
        printf("\nLast ID Delete Successfully.\n");
    }
    else
    {
        temp2 = current->next;
        temp1 = current->previous;
        temp1->next = temp2;
        temp2->previous = temp1;
        printf("\nDelete Successfully.\n");
    }
}

void length_of_the_playlist_record()
{
    struct node *current;
    int count = 0;

    current = start;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    printf("\n\n\n\n\n\n\n\t\t\tThere is/are %d song(s) in the playlist.", count);
    printf("\n                                     Thereforth the length is %d.\n", count);
}

void menu()
{

    int choice, position, song_id, insert_choice, display_choice, delete_choice, search_choice;

    printf("\n\t\t\t\t     Playlist's Record\n");
    printf("\t\t\t_______________________________________________");
    printf("\n\n");

    printf("------------------------------------------------------------------------------------------");
    printf("\n\n");
    printf("\t\t\t\t1. Create Playlist Record.\n");
    printf("\t\t\t\t2. Add Playlist Record.\n");
    printf("\t\t\t\t3. Display Playlist Record.\n");
    printf("\t\t\t\t4. Search Playlist Record.\n");
    printf("\t\t\t\t5. Delete Playlist Record.\n");
    printf("\t\t\t\t6. Length of the Playlist.\n");
    printf("\t\t\t\t7. Exit.\n\n");
    printf("------------------------------------------------------------------------------------------");

    printf("\n\t\t\tPlease Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
    case 1:
        create_playlist_record();
        printf("\n\n\n\n\n\n\n\t\t\tRecord Created Successfully.");
        break;

    case 2:
        while (1)
        {
            printf("\n\n\n\n\n");
            printf("------------------------------------------------------------------------------------------");
            printf("\n\n");
            printf("\t\t\t\t1. Add Record At First.\n");
            printf("\t\t\t\t2. Add Record At Last.\n");
            printf("\t\t\t\t3. Back To Main Program.\n\n");
            printf("------------------------------------------------------------------------------------------");

            printf("\n\n\n\t\t\tPlease Enter your choice: ");
            scanf("%d", &insert_choice);
            printf("\n\n");

            switch (insert_choice)
            {
            case 1:
                add_playlist_record_at_first();

                printf("\n\n\n\n\n\n\n\t\t\tRecord Added successfully.");

                break;

            case 2:
                add_playlist_record_at_last();

                printf("\n\n\n\n\n\n\n\t\t\tRecord Added successfully.");

                break;

            case 3:
                menu();

                break;

            default:
                printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                printf("\n\t\t\tPlease Enter Correct Key to Access.");
            }
        }

    case 3:
        while (1)
        {
            printf("\n\n\n\n\n");
            printf("------------------------------------------------------------------------------------------");
            printf("\n\n");
            printf("\t\t\t\t1. Display From Forward.\n");
            printf("\t\t\t\t2. Display From Backward.\n");
            printf("\t\t\t\t3. Back To Main Program.\n\n");
            printf("------------------------------------------------------------------------------------------");

            printf("\n\n\n\t\t\tPlease Enter your choice: ");
            scanf("%d", &display_choice);
            printf("\n\n");

            switch (display_choice)
            {
            case 1:
                display_playlist_record_from_forward();

                break;

            case 2:
                display_playlist_record_from_backword();

                break;

            case 3:
                menu();

                break;

            default:
                printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                printf("\n\t\t\tPlease Enter Correct Key to Access.");
            }
        }

    case 4:
        while (1)
        {
            printf("\n\n\n\n\n");
            printf("------------------------------------------------------------------------------------------");
            printf("\n\n");
            printf("\t\t\t\t1. Search using Song ID.\n");
            printf("\t\t\t\t2. Back To Main Program.\n\n");
            printf("------------------------------------------------------------------------------------------");
            printf("\n\n\n\t\t\tPlease Enter your choice: ");
            scanf("%d", &search_choice);
            printf("\n\n");

            switch (search_choice)
            {
            case 1:
                printf("\n\n\n\n\n\n\t\t\tEnter Song ID: ");
                scanf("%d", &song_id);

                position = search_playlist_record(song_id);
                if (position == -1)
                {
                    printf("\n\n\n\n\n\n\t\t\tThis Song ID is not in the Record.\n");
                }
                else
                {
                    printf("\n\n\n\n\n\n\t\t\tThe Position of this Record is at Number %d.\n", position);
                }
                break;

            case 2:
                menu();
                break;

            default:
                printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                printf("\n\t\t\tPlease Enter Correct Key to Access.");
                printf("\n\t\t\t\tOr Enter 2 to Main menu.\n");
            }
        }

    case 5:
        while (1)
        {
            printf("\n\n\n\n\n");
            printf("------------------------------------------------------------------------------------------");
            printf("\n\n");
            printf("\t\t\t\t1. Delete.\n");
            printf("\t\t\t\t2. Back To Main Program.\n\n");
            printf("------------------------------------------------------------------------------------------");
            printf("\n\n\n\t\t\tPlease Enter your choice: ");
            scanf("%d", &delete_choice);
            printf("\n\n");

            switch (delete_choice)
            {
            case 1:
                delete_playlist_record();
                break;

            case 2:
                menu();
                break;

            default:
                printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
                printf("\n\t\t\tPlease Enter Correct Key to Access.");
                printf("\n\t\t\t\tOr Enter 2 to Main menu.\n");
            }
        }

    case 6:
        length_of_the_playlist_record();
        menu();
        break;

    case 7:
        exit(1);
        break;

    default:
        printf("\n\n\n\n\n\n\n\t\t\t\tInvalid input!!!");
        printf("\n\t\t\tPlease Enter Correct Key to Access.");
        printf("\n\t\t\t\tOr Enter 8 to Exit.\n");
    }
}

int main()
{

    login();

    printf("\n\n\n\n\n\n\n\n\t\t\t\t   ____________________\n\t\t\t\t  |                    |\n\t\t\t\t  |                    |\n\t\t\t\t  |\t  Welcome      |\n\t\t\t\t  |                    |\n\t\t\t\t  |____________________|\n\n\n");

    while (1)
    {
        menu();
    }
}
