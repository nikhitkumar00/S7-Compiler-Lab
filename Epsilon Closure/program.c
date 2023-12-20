#include <stdio.h>
#include <string.h>

struct node
{
    char state1;
    char transition;
    char state2;
} nodes[10];

char states[5] = {'A', 'B', 'C', 'D'};

void findClosure(char a, int flag)
{
    char result[10];
    if (flag == 0)
        printf("%c ", a);

    for (int j = 0; j < 6; j++)
    {
        if (nodes[j].state1 == a && nodes[j].transition == 'e')
        {
            printf("%c ", nodes[j].state2);
            findClosure(nodes[j].state2, 1);
        }
    }
}

void main()
{
    printf("THE EPSILON CLOSURES ARE :\n\n");
    nodes[0].state1 = 'A';
    nodes[0].transition = '0';
    nodes[0].state2 = 'A';

    nodes[1].state1 = 'A';
    nodes[1].transition = 'e';
    nodes[1].state2 = 'B';

    nodes[2].state1 = 'B';
    nodes[2].transition = '0';
    nodes[2].state2 = 'C';

    nodes[3].state1 = 'B';
    nodes[3].transition = 'e';
    nodes[3].state2 = 'D';

    nodes[4].state1 = 'C';
    nodes[4].transition = '1';
    nodes[4].state2 = 'B';

    nodes[5].state1 = 'D';
    nodes[5].transition = '0';
    nodes[5].state2 = 'D';

    nodes[6].state1 = 'D';
    nodes[6].transition = '1';
    nodes[6].state2 = 'D';

    for (int i = 0; i < 4; i++)
    {
        printf("\n\n%c -> ", states[i]);
        findClosure(states[i], 0);
    }
}