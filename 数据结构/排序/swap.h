void swap(int *a,int b,int c)
{
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}
void show(int *a,int max)
{
    for (int yyyyyy=0; yyyyyy < max;yyyyyy++)
    {
        printf("%d ", a[yyyyyy]);
    }
    puts("");
}
void init(int *a,int max,int maxgnum)
{
    for (int gggggg = 0; gggggg < max;gggggg++)
    {
        a[gggggg] = rand() % maxgnum;
    }
    show(a, max);
}