#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int timeid = 10;
struct Rating
{
    int val;
    int ts;
};

struct Photo
{
    struct Rating rat[100];
    int s_rat;
    float avg_rat;
    int med_rat;
    int key;
    struct Rating min_heap[10];
    int s_min;
    struct Rating max_heap[10];
    int s_max;
};

int search(struct Photo *lib, int id, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (id == lib[i].key)
            return i;
    }
    return -1;
}

int earliest_rating(struct Photo *lib, int id)
{
    int min = 21, idx;
    for (int i = 0; i < lib[id].s_max; i++)
    {
        if (min > lib[id].max_heap[i].ts)
        {
            min = lib[id].max_heap[i].ts;
            idx = i;
        }
    }
    for (int i = 0; i < lib[id].s_min; i++)
    {
        if (min > lib[id].min_heap[i].ts)
        {
            min = lib[id].min_heap[i].ts;
            idx = -(i + 1);
        }
    }
    return idx;
}

int earliest(struct Photo *lib, int n)
{
    int min = 100, idx;
    for (int i = 0; i < n; i++)
    {
        if (min > lib[i].key)
        {
            min = lib[i].key;
            idx = i;
        }
    }
    return idx;
}

void max_heapify_photo(struct Photo *lib, int id, int n, int prev)
{
    int j = (id - 1) / 2, k = 2 * id + 1;
    if (lib[id].avg_rat >= prev)
    {
        while (id && lib[j].avg_rat < lib[id].avg_rat)
        {
            struct Photo temp = lib[id];
            lib[id] = lib[j];
            lib[j] = temp;
            id = j;
            j = (id - 1) / 2;
        }
    }
    else
    {
        while (k < n - 1)
        {
            if (lib[k + 1].avg_rat > lib[k].avg_rat)
                k++;
            if (lib[id].avg_rat < lib[k].avg_rat)
            {
                struct Photo temp = lib[id];
                lib[id] = lib[k];
                lib[k] = temp;
            }
            else
                break;
            id = k;
            k = 2 * id + 1;
        }
    }
}
void max_insert(struct Photo *lib, int id, struct Rating temp)
{
    lib[id].max_heap[lib[id].s_max] = temp;
    int i = lib[id].s_max, j = (i - 1) / 2;
    while (i > 0 && lib[id].max_heap[j].val < lib[id].max_heap[i].val)
    {
        struct Rating temp2 = lib[id].max_heap[j];
        lib[id].max_heap[j] = lib[id].max_heap[i];
        lib[id].max_heap[i] = temp2;
        i = j;
        j = (i - 1) / 2;
    }
    lib[id].s_max++;
}

struct Rating del_max(struct Photo *lib, int id, int i)
{
    struct Rating temp = lib[id].max_heap[i];
    lib[id].s_max--;
    lib[id].max_heap[i] = lib[id].max_heap[(lib[id].s_max)];
    int cur = i, j = 2 * cur + 1;
    while (j < lib[id].s_max)
    {
        if (lib[id].max_heap[j + 1].val > lib[id].max_heap[j].val)
            j++;
        if (lib[id].max_heap[cur].val < lib[id].max_heap[j].val)
        {
            struct Rating temp2 = lib[id].max_heap[cur];
            lib[id].max_heap[cur] = lib[id].max_heap[j];
            lib[id].max_heap[j] = temp2;
        }
        else
            break;
        cur = j;
        j = 2 * cur + 1;
    }
    return temp;
}

void min_insert(struct Photo *lib, int id, struct Rating temp)
{
    lib[id].min_heap[lib[id].s_min] = temp;
    int i = lib[id].s_min, j = (i - 1) / 2;
    while (i > 0 && lib[id].min_heap[j].val > lib[id].min_heap[i].val)
    {
        struct Rating temp2 = lib[id].min_heap[j];
        lib[id].min_heap[j] = lib[id].min_heap[i];
        lib[id].min_heap[i] = temp2;
        i = j;
        j = (i - 1) / 2;
    }
    lib[id].s_min++;
}

struct Rating del_min(struct Photo *lib, int id, int i)
{
    struct Rating temp = lib[id].min_heap[i];
    lib[id].s_min--;
    lib[id].min_heap[i] = lib[id].min_heap[(lib[id].s_min)];
    int cur = i, j = 2 * cur + 1;
    while (j < lib[id].s_min)
    {
        if (lib[id].min_heap[j + 1].val < lib[id].min_heap[j].val)
            j++;
        if (lib[id].min_heap[cur].val > lib[id].min_heap[j].val)
        {
            struct Rating temp2 = lib[id].min_heap[cur];
            lib[id].min_heap[cur] = lib[id].min_heap[j];
            lib[id].min_heap[j] = temp2;
        }
        else
            break;
        cur = j;
        j = 2 * cur + 1;
    }
    return temp;
}

struct Rating new_rating(struct Photo *lib, int id, int r)
{
    lib[id].rat[lib[id].s_rat].val = r;
    lib[id].avg_rat = (lib[id].avg_rat * lib[id].s_rat + r) / (lib[id].s_rat + 1);
    lib[id].rat[lib[id].s_rat].ts = lib[id].s_rat++;
    return lib[id].rat[lib[id].s_rat - 1];
}

void balance(struct Photo *lib, int id)
{
    if (lib[id].s_max - lib[id].s_min >= 2)
    {
        struct Rating y = del_max(lib, id, 0);
        min_insert(lib, id, y);
    }
    else if (lib[id].s_min - lib[id].s_max >= 2)
    {
        struct Rating y = del_min(lib, id, 0);
        max_insert(lib, id, y);
    }
}

void newsub(struct Photo *lib, int *n)
{
    int id, prev = 0;
    if ((*n) == 10)
    {
        id = earliest(lib, *n);
        prev = lib[id].avg_rat;
        lib[id].key = timeid++;
    }
    else
    {
        lib[*n].key = *n;
        id = *n;
        (*n)++;
    }
    printf("Enter Rating of 3 judges\n");
    lib[id].s_max = 0;
    lib[id].s_min = 0;
    lib[id].s_rat = 0;
    lib[id].avg_rat = 0;
    for (int j = 0; j < 3; j++)
    {
        int x;
        printf("Enter rating: ");
        scanf("%d", &x);
        struct Rating temp = new_rating(lib, id, x);
        max_insert(lib, id, temp);
    }
    balance(lib, id);

    lib[id].med_rat = lib[id].max_heap[0].val;
    max_heapify_photo(lib, id, (*n) - 1, prev);
}

void initialize(struct Photo *lib, int *n, int t)
{
    int id, prev = 0;
    lib[id].s_max = 0;
    lib[id].s_min = 0;
    lib[id].s_rat = 0;
    lib[id].avg_rat = 0;
    for (int i = 0; i < t; i++)
    {
        lib[*n].key = *n;
        id = *n;
        (*n)++;
        for (int j = 0; j < 3; j++)
        {
            int x = rand() % (21);
            struct Rating temp = new_rating(lib, id, x);
            max_insert(lib, id, temp);
        }
        struct Rating y = del_max(lib, id, 0);
        min_insert(lib, id, y);
        lib[id].med_rat = lib[id].max_heap[0].val;
        max_heapify_photo(lib, id, (*n) - 1, prev);
    }
}

void rate(struct Photo *lib, int id, int r, int n)
{
    if (r >= lib[id].med_rat - 3 && r <= lib[id].med_rat + 3)
    {
        int prev = lib[id].avg_rat;
        if (lib[id].s_rat >= 9)
        {
            int i = earliest_rating(lib, id);
            if (i >= 0)
            {
                del_max(lib, id, i);
            }
            else
            {
                del_min(lib, id, -(i + 1));
            }
        }
        balance(lib, id);
        if (r < lib[id].max_heap[0].val)
        {
            struct Rating temp = new_rating(lib, id, r);
            max_insert(lib, id, temp);
        }
        else
        {
            struct Rating temp = new_rating(lib, id, r);
            min_insert(lib, id, temp);
        }
        balance(lib, id);
        if (lib[id].s_min == lib[id].s_max)
            lib[id].med_rat = (lib[id].max_heap[0].val + lib[id].min_heap[0].val) / 2;
        else if (lib[id].s_min > lib[id].s_max)
            lib[id].med_rat = lib[id].min_heap[0].val;
        else
            lib[id].med_rat = lib[id].max_heap[0].val;
        max_heapify_photo(lib, id, n - 1, prev);
    }
    else
        printf("not a valid Rating!");
}

void display(struct Photo *lib, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Photo id: %d     ", lib[i].key);
        printf("avg Rating: %d   ", (int)lib[i].avg_rat);
        printf("med Rating: %d   ", lib[i].med_rat);
        printf("ratings: ");
        int k;
        for (k = 0; k < lib[i].s_rat - 1; k++)
        {
            printf("%d, ", lib[i].rat[k].val);
        }
        printf("%d\n", lib[i].rat[k].val);
        printf("ratings in maxheap: ");
        for (int j = 0; j < lib[i].s_max; j++)
        {
            printf("%d ", lib[i].max_heap[j].val);
        }
        printf("minheap: ");
        for (int j = 0; j < lib[i].s_min; j++)
        {
            printf("%d ", lib[i].min_heap[j].val);
        }
        printf("\n\n");
    }
    printf("\n");
}

int main()
{
    struct Photo lib[100];
    int n = 0;
    initialize(lib, &n, 10);
    display(lib, n);
    while (1)
    {
        printf("1: New submition\n2: Rate a Photo\n3: who is the winner?\n4: To exit\n");
        int q;
        scanf("%d", &q);
        switch (q)
        {
        case 1:
        {
            newsub(lib, &n);
            display(lib, n);
            break;
        }
        case 2:
        {
            for (int i = 0; i < n; i++)
            {
                printf("Photo id: %d ", lib[i].key);
            }
            printf("\nchoose a Photo and Rating: ");
            int x, y;
            scanf("%d %d", &x, &y);
            if (y >= 0 && y <= 20)
            {
                int idx = search(lib, x, n);
                if (idx != -1)
                    rate(lib, idx, y, n);
                else
                    printf("not found!");
            }
            else
                printf("invalid Rating!");
            display(lib, n);
            break;
        }
        case 3:
        {
            printf("Photo: %d with avg Rating: %d \n", lib[0].key, (int)lib[0].avg_rat);
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
            printf("wrong option, Choose number: ");
        }
    }
}
