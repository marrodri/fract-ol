 #include <stdio.h>
 #include <pthread.h>

void myturn()
{
    while(1)
    {
        sleep(1);
        printf("My Turn!\n");
    }
}


void yourturn()
{
    while(1)
    {
        sleep(2);
        printf("Your Turn!\n");
    }
}

int main()
{
    // myturn();
    // yourturn();
    char a[] = "hello\n";
    char  b = *(a + 1); 
    printf("%c\n",b);
}